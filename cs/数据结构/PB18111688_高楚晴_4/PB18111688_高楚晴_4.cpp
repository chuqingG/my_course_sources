#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
/********************
1.基于邻接矩阵使用非递归DFS算法，求无向连通图的全部关节点，按顶点编号升序输出
2.基于邻接表，用BFS，依次输出顶点0到其余的最短路径长度和各路径中顶点信息
input：
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

output：
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
#define MAX_NUM 20
#define TRUE 1
#define FALSE 0
#define ERROR -1
#define OVERFLOW -2
#define OK 1
int visited[MAX_NUM];
int(*visitfunc)(int v);
int count = 0;
int w, v, n = 0;
int min = 0;
int pre[MAX_NUM];  
int low[MAX_NUM];
int isart[5];   //用于存放关节点便于降序输出 


typedef enum { DG, DN, UDG, UDN }Graphkind;
typedef struct arccell {               //邻接矩阵
	int adj;
	int *info;
}Arccell,Adjmatrix[MAX_NUM][MAX_NUM];
typedef struct {           
	int vexs[MAX_NUM];
	Adjmatrix arcs;
	int vexnum, arcnum;
	Graphkind kind;
}Mgragh;

typedef struct Arcnode {               //邻接表
	int adjvex;
	struct Arcnode *nextarc;
	int *info;
}Arcnode;
typedef struct Vnode {
	int data;
	Arcnode *firstarc;
}Vnode, Adjlist[MAX_NUM];
typedef struct {
	Adjlist vertices;
	int vexnum, arcnum;
	int kind;
}Algraph;

struct Node;                            //非递归算法用到的栈的基本函数
typedef struct Node *pNode;
typedef pNode Stack;
typedef struct snode {
	int w;
	int v;
	int min;
}snode;
struct Node {
	snode *s;
	pNode next;
};

Mgragh G;
Stack S;
Arcnode *p;



Algraph *Create() {                         //创建邻接表和邻接矩阵 
	int i = 0,j, c1, c2;
	Algraph *G0;
	Arcnode* temp, *temp2;
	G0 = (Algraph *)malloc(sizeof(Algraph));
	scanf("%d", &G0->vexnum);
	G.vexnum = G0->vexnum; 
	for (i = 0; i <= G0->vexnum; i++)       //初始化邻接表 
	{
		G0->vertices[i].data = i;
		G0->vertices[i].firstarc = NULL;
	}
	for (i = 0; i < G.vexnum; i++)         //初始化邻接矩阵 
		for (j = 0; j < G.vexnum; j++)
			G.arcs[i][j].adj = 0;
	while (scanf("%d %d", &c1, &c2) == 2)
	{   
		//************给邻接矩阵赋值 ***************** 
		G.arcs[c1][c2].adj = 1;
		G.arcs[c2][c1].adj = 1;
		//**************给邻接表赋值 *************** 
		temp = (Arcnode*)malloc(sizeof(Arcnode));
		temp->adjvex = c2;
		//printf("%d\n",temp->adjvex);
		temp->nextarc = NULL;   
		if (G0->vertices[c1].firstarc == NULL)
			G0->vertices[c1].firstarc = temp;
		else {                   //insert
			//printf("%d firtarc is not NULL,have adj %d\n", c1,G0->vertices[c1].firstarc->adjvex);
			temp2 = G0->vertices[c1].firstarc;
			while (temp2->nextarc != NULL)
				temp2 = temp2->nextarc;
			temp2->nextarc = temp;
		}
		temp = (Arcnode*)malloc(sizeof(Arcnode));
		temp->adjvex = c1;
		//printf("%d\n",temp->adjvex);
		temp->nextarc = NULL;    
		if (G0->vertices[c2].firstarc == NULL)        //!!!!=和== 
			G0->vertices[c2].firstarc = temp;
		else {                   //insert
			//printf("c2 firtarc is not NULL,have adj %d\n", c2,G0->vertices[c2].firstarc->adjvex);
			temp2 = G0->vertices[c2].firstarc;
			while (temp2->nextarc != NULL)
				temp2 = temp2->nextarc;
			temp2->nextarc = temp;
		}

	}
	return G0;
}

void DFSarti(int v0) {
	int min;
	visited[v0] = min = ++count;
	int w = 0;
	while (1) {
		while (G.arcs[v0][w].adj==0&&w<G.vexnum)   //找该顶点全部邻接点
			w++;
		if (w >= G.vexnum)    //该节点可能的邻接点全部访问完
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

//*************栈的基本操作*************** 
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

void Push(int v, int w,int min) {
	pNode p1;
	p1 = (pNode)malloc(sizeof(struct Node));        //头结点是空的
	if (p1 == NULL)
		printf("no space");
	else {
		p1->s->v = v;
		p1->s->w = w;
		p1->s->min = min;
		p1->next = S->next;
		S->next = p1;
	}
	//printf("%d %d\n",S->next->s->v,S->next->s->w);
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
		//printf("%d %d\n",preturn->v,preturn->w);
	}
	return preturn;
}
//*************非递归寻找某个顶点开始的关节点************ 
void DFsarti(int v0) {
	snode *p1;
	int min;
	visited[v0] = min = ++count;
	//printf("visited[%d] = %d \n",v0,visited[v0]);
	//printf("visit %d\n",v0);
	int v1 = 0;
	Push(v0, v1,min);
	//printf("push %d %d \n",v0,v1);
	while (!Isempty()) {
		p1 = Pop();
		v0 = p1->v;
		v1 = p1->w + 1;
		min = p1->min;
		//printf("pop %d %d \n",v0,v1-1);
		while (G.arcs[v0][v1].adj == 0 && v1 < G.vexnum)   //找该顶点全部邻接点
			v1++;
		if (v1 >= G.vexnum)    //该节点可能的邻接点全部访问完
			continue;
		if (visited[v1] == 0) {
			Push(v0, v1,min);
			//printf("push %d %d \n",v0,v1);
			v0 = v1;
			v1 = 0;
			visited[v0] = min = ++count;
			low[v0] = min;
			Push(v0, v1,min);
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
//DFS确定根节点以外是否为连通片 
int flag[MAX_NUM];
void DFS(int v){
	int w;
	flag[v] = 0;
	for(w = 1;w<G.vexnum;w++)
		if(G.arcs[v][w].adj&&flag[w])
			DFS(w);
} 
//************寻找关节点************ 
void Findart() {              
	int i,j,k=0,t=0;
	int v= 0; 
	count = 0;
	visited[0] = 1;
	for (i = 0; i < G.vexnum; ++i){      //初始值清零
		visited[i] = 0;
		isart[i] = 0;
	}
	DFSarti(v);       //从顶点w开始DFS关节点
	//printf("count -> %d\n",count);
	if (count < G.vexnum) { 
		while (1) {
			while (!G.arcs[v][0].adj&&v < G.vexnum)   //找该顶点全部邻接点
				v++;
			if (v >= G.vexnum)          //该节点可能的邻接点全部访问完
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
			isart[0] = 1;	   //根节点的叶子结点不完全联通				
	//输出 
	for(i = 0;i<G.vexnum;i++)
		if(isart[i])
			printf("%d ",i);
}

//**********寻找最短路径************ 
void find(Algraph *G0) {
	int used[MAX_NUM]; 
	int i,v0 = 0;
	int count = 1;
	Arcnode *p;
	pre[0] = 0;
	used[0] = 1;
	for (i = 1; i < G0->vexnum; i++){
		pre[i] = -1;
		used[i] = 0;
	}
	for(p = G0->vertices[0].firstarc;p;p = p->nextarc){
		pre[p->adjvex] = 0;
		count++;
	}
	while (count != G0->vexnum) {
		for(i = 1;i<G0->vexnum;i++){
			if(pre[i]!=-1&&used[i]==0){   //还没有用当前节点找过下一个点 
				used[i] = 1;
				for(p = G0->vertices[i].firstarc;p;p = p->nextarc)
					if(pre[p->adjvex]==-1){
						pre[p->adjvex] = i;
						count++;
					}
			}
		}
	}
}
//*********输出最短路径************** 
void output(Algraph *G0) {
	int i,j,len,path[MAX_NUM];
	for (i = 1; i < G0->vexnum; i++) {
		len = 0;
		j = i;
		path[len++] = j;
		while (pre[j] != 0) {
			j = pre[j];
			path[len++] = j;
		}
		printf("%d 0",len);
		for (j = len-1 ; j >= 0; j--)
			printf("->%d", path[j]);
		printf("\n");
	}
}
int main() {
	int i;
	Arcnode* p;
	Algraph *G0;
	G0 = Create();
	Findart();
	printf("\n");
	//Findart();
	/**************
	printf("打印邻接表：\n");
	for (i = 0; i < G0->vexnum; i++)   //输出 
	{
		//printf("%d %d\n",i,G0->vertices[i].firstarc->adjvex);
		if (G0->vertices[i].firstarc == NULL)
			printf("error");
		else
		{
			p = G0->vertices[i].firstarc;
			printf("%d ", G0->vertices[i].data);
			while (p != NULL)
			{
				//printf("p is not NULL\n");
				printf("%d ", p->adjvex);
				p = p->nextarc;
			}
		}
		printf("\n");
	}
	printf("success\n");
	******************/
	find(G0);
	output(G0);
	return 0;
}
