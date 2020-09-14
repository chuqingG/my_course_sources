#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
/********************
1.�����ڽӾ���ʹ�÷ǵݹ�DFS�㷨����������ͨͼ��ȫ���ؽڵ㣬���������������
2.�����ڽӱ���BFS�������������0����������·�����Ⱥ͸�·���ж�����Ϣ
input��
13
0 1
0 2
0 5
0 11
1 2
1 3
1 6
1 7
1 12
3 4
6 7
6 8
6 10
7 10
9 11
9 12
11 12

output��
0 1 3 6
1 0->1
1 0->2
2 0->1->3
3 0->1->3->4
1 0->5
2 0->1->6
2 0->1->7
3 0->1->6->8
2 0->11->9
3 0->1->6->10
1 0->11
2 0->1->12
******************/
#define INFINITY 10000
#define MAX_NUM 20
#define TRUE 1
#define FALSE 0
int visited[MAX_NUM];
int (*visitfunc)(int v);
int count = 0;
int n = 0;
//int min = 0;
int low[MAX_NUM];
int isart[5];   //���ڴ�Źؽڵ���ڽ������ 
//int visit[MAX_NUM];

typedef enum { DG, DN, UDG, UDN }Graphkind;
typedef struct arccell {               //�ڽӾ���
	int adj;
	int *info;
}Arccell,Adjmatrix[MAX_NUM][MAX_NUM];
typedef struct {           
	int vexs[MAX_NUM];
	Adjmatrix arcs;
	int vexnum, arcnum;
	Graphkind kind;
}Mgragh;

typedef struct Arcnode {               //�ڽӱ�
	int adjvex;
	struct Arcnode *nextarc;
	int *info;
}Arcnode;
typedef struct Vnode {
	int data;
	Arcnode *firstarc;
}Vnode,Adjlist[MAX_NUM];
typedef struct{
	Adjlist vertices;
	int vexnum, arcnum;
	int kind;
}Algragh;

struct Node;                            //�ǵݹ��㷨�õ���ջ�Ļ�������
typedef struct Node *pNode;
typedef pNode Stack;
typedef struct snode {
	int w;
	int v;
}snode;
struct Node {
	snode *s;
	pNode next;
};

Mgragh G;
Stack S;
Arcnode *p;

void DFSarti(int v0) {
	int min;
	visited[v0] = min = ++count;
	int w = 0;
	while (1) {
		while (G.arcs[v0][w].adj==0&&w<G.vexnum)   //�Ҹö���ȫ���ڽӵ�
			w++;
		if (w >= G.vexnum)    //�ýڵ���ܵ��ڽӵ�ȫ��������
			break;
		if (visited[w]==0) {
			DFSarti(w);
			if (low[w] < min)
				min = low[w];
			if (low[w] >= visited[v0]&&v0!=0){
				isart[v0] = 1;
			}
			
		}
		else if (visited[w] < min)
			min = visited[w];
		w++;
	}
	low[v0] = min;
}


int Isempty() {
	return S->next == NULL;
}

Stack Initstack() {
	S = (pNode)malloc(sizeof(struct Node));
	if (S == NULL)
		printf("fail to create!");
	S->next = NULL;
	return S;
}

void Push(int v, int w) {
	pNode p;
	p = (pNode)malloc(sizeof(struct Node));        //ͷ����ǿյ�
	if (p == NULL)
		printf("no space");
	else {
		p->s->v = v;
		p->s->w = w;
		p->next = S->next;
		S->next = p;
	}
	printf("%d %d\n",S->next->s->v,S->next->s->w);
}

snode *Pop() {
	pNode top;
	snode *preturn;
	if (Isempty())
		printf("stack is empty");
	else {
		preturn = S->next->s;
		top = S->next;
		S->next = S->next->next;
		free(top);
		printf("%d %d\n",preturn->v,preturn->w);
	}
	return preturn;
}

void DFsarti(int v0) {
	snode *p;
	int min;
	visited[v0] = min = ++count;
	//printf("visited[%d] = %d \n",v0,visited[v0]);
	//printf("visit %d\n",v0);
	int v1 = 0;
	Push(v0, v1);
	//printf("push %d %d \n",v0,v1);
	while (!Isempty()) {
		p = Pop();
		v0 = p->v;
		v1 = p->w + 1;
		//printf("pop %d %d \n",v0,v1-1);
		while (G.arcs[v0][v1].adj == 0 && v1 < G.vexnum)   //�Ҹö���ȫ���ڽӵ�
			v1++;
		if (v1 >= G.vexnum)    //�ýڵ���ܵ��ڽӵ�ȫ��������
			continue;
		if (visited[v1] == 0) {
			Push(v0, v1);
			//printf("push %d %d \n",v0,v1);
			v0 = v1;
			v1 = 0;
			visited[v0] = min = ++count;
			low[v0] = min;
			Push(v0, v1);
			//printf("push %d %d \n",v0,v1);
			continue;
		}
		else {
			//printf("visited[%d] = %d \n",v0,visited[v0]);
			//printf("visited[%d] = %d \n",v1,visited[v1]);
			//printf("low[%d] = %d \n",v0,low[v0]);
			//printf("min = %d \n",min);
			if (low[v1] < min)
				min = low[v1];
			if (low[v1] >= visited[v0]) {
				isart[v0] = 1;
				//printf("%d is a arti\n",v0);
			}
			if (visited[v1] < min)
				min = visited[v1];
		}
	}
}
int flag[MAX_NUM];
void DFS(int v){
	int w;
	flag[v] = 0;
	for(w = 1;w<G.vexnum;w++)
		if(G.arcs[v][w].adj&&flag[w])
			DFS(w);
} 

void Findart() {              //Ѱ�ҹؽڵ�
	int i,j,k=0,t=0;
	int v= 0; 
	count = 0;
	visited[0] = 1;
	for (i = 0; i < G.vexnum; ++i){      //��ʼֵ����
		visited[i] = 0;
		isart[i] = 0;
	}
	DFSarti(v);       //�Ӷ���w��ʼDFS�ؽڵ�
	//printf("count -> %d\n",count);
	if (count < G.vexnum) { 
		while (1) {
			while (!G.arcs[v][0].adj&&v < G.vexnum)   //�Ҹö���ȫ���ڽӵ�
				v++;
			if (v >= G.vexnum)          //�ýڵ���ܵ��ڽӵ�ȫ��������
				break;
			if (visited[v] == 0)
				DFSarti(v);
		}
	}
	for(i = 1;i<G.vexnum;i++)
		flag[i] = 1;
	while(G.arcs[0][t].adj==0)
		t++;
	DFS(t);
	for(i = 1;i<G.vexnum;i++)
		if(flag[i]== 1)
			isart[0] = 1;	   //���ڵ��Ҷ�ӽ�㲻��ȫ��ͨ				
	//��� 
	for(i = 0;i<G.vexnum;i++)
		if(isart[i])
			printf("%d ",i);
}
//��ʼ���ڽӾ��� 
void Create() {
	int i, j;
	scanf("%d", &G.vexnum);
	for (i = 0; i < G.vexnum; i++)     
		for (j = 0; j < G.vexnum; j++)
			G.arcs[i][j].adj = 0;
	while (scanf("%d %d", &i, &j) == 2){
		G.arcs[i][j].adj = 1;
		G.arcs[j][i].adj = 1;
	}
}
int main() {
	int i;
	Create();
	Findart();
	printf("\n");
	return 0;
}
