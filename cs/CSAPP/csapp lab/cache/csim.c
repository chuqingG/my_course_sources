#include "cachelab.h"
#include <getopt.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>
#include <time.h>

typedef unsigned long int uint64_t;
trans_func_t func_list[MAX_TRANS_FUNCS];
int func_counter = 0; 
typedef struct {
    int valid;
    int lru;
    uint64_t tag;
}cacheLine;

typedef cacheLine* cacheSet;
typedef cacheSet* Cache;

const char* usage = "Usage: %s [-hv] -s <s> -E <E> -b <b> -t <tracefile>\n";

int verbose = 0; //verbose flag 
int s;  //number of set index bits 
int E;  //number of lines per set
int b;  //number of block bits
FILE* fp = NULL;
Cache cache;

int hits = 0;
int misses = 0;
int evictions = 0;
void printSummary(int hits, int misses, int evictions)
{
    printf("hits:%d misses:%d evictions:%d\n", hits, misses, evictions);
    FILE* output_fp = fopen(".csim_results", "w");
    assert(output_fp);
    fprintf(output_fp, "%d %d %d\n", hits, misses, evictions);
    fclose(output_fp);
}

/* 
 * initMatrix - Initialize the given matrix 
 */
void initMatrix(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;
    srand(time(NULL));
    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            // A[i][j] = i+j;  /* The matrix created this way is symmetric */
            A[i][j]=rand();
            B[j][i]=rand();
        }
    }
}

void randMatrix(int M, int N, int A[N][M]) {
    int i, j;
    srand(time(NULL));
    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            // A[i][j] = i+j;  /* The matrix created this way is symmetric */
            A[i][j]=rand();
        }
    }
}

/* 
 * correctTrans - baseline transpose function used to evaluate correctness 
 */
void correctTrans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;
    for (i = 0; i < N; i++){
        for (j = 0; j < M; j++){
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }    
}



/* 
 * registerTransFunction - Add the given trans function into your list
 *     of functions to be tested
 */
void registerTransFunction(void (*trans)(int M, int N, int[N][M], int[M][N]), 
                           char* desc)
{
    func_list[func_counter].func_ptr = trans;
    func_list[func_counter].description = desc;
    func_list[func_counter].correct = 0;
    func_list[func_counter].num_hits = 0;
    func_list[func_counter].num_misses = 0;
    func_list[func_counter].num_evictions =0;
    func_counter++;
}


void parseArgument(int argc, char* argv[]);
int visitCache(uint64_t address);
int simulate();

int main(int argc, char* argv[])
{
    parseArgument(argc, argv);
    simulate();
    printSummary(hits, misses, evictions);
    return 0;
}

void parseArgument(int argc, char* argv[])
{
    int opt;
    while ((opt = getopt(argc, argv, "hvs:E:b:t:")) != -1)
    {
        switch(opt)
        {
            case 'h':
                fprintf(stdout, usage, argv[0]);
                exit(1);
            case 'v':
                verbose = 1;
                break;
            case 's':
                s = atoi(optarg);
                break;
            case 'E':
                E = atoi(optarg);
                break;
            case 'b':
                b = atoi(optarg);
                break;
            case 't':
                fp = fopen(optarg, "r");
                break;
            default:
                fprintf(stdout, usage, argv[0]);
                exit(1);
        }
    }
}

int simulate()
{
    int S = pow(2, s);
    cache = (Cache)malloc(sizeof(cacheSet) * S);
    if (cache == NULL) return -1;
    for (int i = 0; i < S; i++)
    {
        cache[i] = (cacheSet)calloc(E, sizeof(cacheLine));
        if (cache[i] == NULL) return -1;
    }

    char buf[20];
    char operation;
    uint64_t address;
    int size;

    while (fgets(buf, sizeof(buf), fp) != NULL)
    {
        int ret;

        if (buf[0] == 'I') //ignore instruction cache accesses
        {
            continue;
        }
        else
        {
            sscanf(buf, " %c %lx,%d", &operation, &address, &size);

            switch (operation)
            {
                case 'S':
                    ret = visitCache(address);
                    break;
                case 'L':
                    ret = visitCache(address);
                    break;
                case 'M':
                    ret = visitCache(address);
                    hits++;
                    break;
            }

            if (verbose)
            {
                switch(ret)
                {
                    case 0:
                        printf("%c %lx,%d hit\n", operation, address, size);
                        break;
                    case 1:
                        printf("%c %lx,%d miss\n", operation, address, size);
                        break;
                    case 2:
                        printf("%c %lx,%d miss eviction\n", operation, address, size);
                        break;
                }
            }
        }
    }

    for (int i = 0; i < S; i++)
        free(cache[i]);
    free(cache);
    fclose(fp);
    return 0;
}

/*return value
      0             cache hit
      1             cache miss
      2             cache miss, eviction
*/
int visitCache(uint64_t address)
{
    uint64_t tag = address >> (s + b);
    unsigned int setIndex = address >> b & ((1 << s) - 1);

    int evict = 0;
    int empty = -1;
    cacheSet cacheset = cache[setIndex];

    for (int i = 0; i < E; i++)
    {
        if (cacheset[i].valid)
        {
            if (cacheset[i].tag == tag)
            {
                hits++;
                cacheset[i].lru = 1;
                return 0;
            }

            cacheset[i].lru++;
            if (cacheset[evict].lru <= cacheset[i].lru) // =是必须的,why?
            {
                evict = i;
            }
        }
        else
        {
            empty = i;
        }
    }

    //cache miss
    misses++;

    if (empty != -1)
    {
        cacheset[empty].valid = 1;
        cacheset[empty].tag = tag;
        cacheset[empty].lru = 1;
        return 1;
    }
    else
    {
        cacheset[evict].tag = tag;
        cacheset[evict].lru = 1;
        evictions++;
        return 2;
    }
}