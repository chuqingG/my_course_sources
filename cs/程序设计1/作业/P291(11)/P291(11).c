#include<stdio.h>
#include<string.h>
#define N 4
void sort(char (*s)[10])
{
    char t[10],*temp=t;
    int i,j,k;
    for(i=0;i<N-1;i++)
    {
        k=i;
        for(j=i+1;j<N;j++)
            if(strcmp(s+k,s+j)>0)
                k=j;
        strcpy(temp,s+k);
        strcpy(s+k,s+i);
        strcpy(s+i,temp);
    }
}

void main()
{
    char s[N][10];
    int i;
    printf("input:\n");
    for(i=0;i<N;i++)
    {
        scanf("%s",s[i]);
    }
    sort(s);
    printf("output:\n");
    for(i=0;i<N;i++)
        printf("%s ",s[i]);
}
