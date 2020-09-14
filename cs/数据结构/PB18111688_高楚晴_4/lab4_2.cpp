#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
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
#define ERROR -1
#define OVERFLOW -2
#define OK 1
int visited[MAX_NUM];
int(*visitfunc)(int v);
int count = 0;
int w, v, n = 0;
int min = 0;
int pre[MAX_NUM];  // 

typedef struct Arcnode {               //�ڽӱ�
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
struct Node;                            //�ǵݹ��㷨�õ���ջ�Ļ�������
typedef struct Node *pNode;
typedef pNode Stack;
struct Node {
	int data;
	pNode next;
};
Stack S;
Arcnode *p;

Algraph *create() {   //������ 
	int i = 0, c1, c2;
	Algraph *G0;
	Arcnode* temp, *temp2;
	G0 = (Algraph *)malloc(sizeof(Algraph));
	scanf("%d", &G0->vexnum);
	for (i = 0; i <= G0->vexnum; i++)
	{
		G0->vertices[i].data = i;
		G0->vertices[i].firstarc = NULL;
	}
	while (scanf("%d %d", &c1, &c2) == 2)
	{
		temp = (Arcnode*)malloc(sizeof(Arcnode));
		temp->adjvex = c2;
		//printf("%d\n",temp->adjvex);
		temp->nextarc = NULL;   //���ٿռ�֮��һ��Ҫ��ÿһ��Ԫ�ظ�ֵ��NULLҲҪ��ֵ 
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
		temp->nextarc = NULL;   //���ٿռ�֮��һ��Ҫ��ÿһ��Ԫ�ظ�ֵ��NULLҲҪ��ֵ 
		if (G0->vertices[c2].firstarc == NULL)        //!!!!=��== 
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
//��ʼ��ջ 
void InitStack(Stack &S) {
	S = (pNode)malloc(sizeof(Node));
	S->next = NULL;
}
 
void Push(int n, Stack &S) {
	pNode temp;
	temp = (pNode)malloc(sizeof(Node));
	temp->data = n;
	temp->next = S->next;
	S->next = temp;
}

int Pop(Stack &S) {
	int x;
	pNode temp;
	x = S->next->data;
	temp = S->next;
	S->next = S->next->next;
	free(temp);
	return x;
}

int stackempty(Stack &S) {
	return S->next == NULL;
}

void shortest(int dest,Algraph *G) {
	int path[MAX_NUM];  //���·�� 
	int visit[MAX_NUM]; //�ڵ��Ƿ��ѷ��� 	
	int i, len=1,find = 0;
	int v0 = 0;
	Arcnode *p,*p1;
	InitStack(S);
	//p = G->vertices[v0].firstarc;
	//printf("%d\n",p->adjvex);
	Push(v0,S);
	visit[0] = 1;
	for (i = 1; i < G->vexnum; i++) {
		path[i] = 0;
		visit[i] = 0;
	}
	while (!find) {
		v0 = Pop(S);
		p1 = p = G->vertices[v0].firstarc;
		visit[v0] = 1;
		while (p&&visit[p->adjvex] != 0){
			p = p->nextarc;
		}
		if (!p)              //��ǰ����v0û��û�����ʹ����ٶ�
			continue;
		p = p1;             //��ԭ
		while (p&&dest != p->adjvex)
			p = p->nextarc;
		if (!p) {
			Push(v0, S);
			p = p1;
			while(visit[p->adjvex]!=0)    //����һ��û���ʹ����ٶ���ʼ 
				p = p->nextarc;
			Push(p->adjvex, S);
			continue;
		}
		find = 1;
		path[0] = dest;
		path[len++] = v0;
	}
	while (!stackempty(S))
		path[len++] = Pop(S);
	printf("%d 0", len-1);
	for (i = len-2; i >=0; i--)
		printf("->%d", path[i]);
	printf("\n");
}
//**********Ѱ�����·��************ 
void find(Algraph *G) {
	int used[MAX_NUM]; 
	int i,v0 = 0;
	int count = 1;
	Arcnode *p;
	pre[0] = 0;
	used[0] = 1;
	for (i = 1; i < G->vexnum; i++){
		pre[i] = -1;
		used[i] = 0;
	}
	for(p = G->vertices[0].firstarc;p;p = p->nextarc){
		pre[p->adjvex] = 0;
		count++;
	}
	while (count != G->vexnum) {
		for(i = 1;i<G->vexnum;i++){
			if(pre[i]!=-1&&used[i]==0){   //��û���õ�ǰ�ڵ��ҹ���һ���� 
				used[i] = 1;
				for(p = G->vertices[i].firstarc;p;p = p->nextarc)
					if(pre[p->adjvex]==-1){
						pre[p->adjvex] = i;
						count++;
					}
			}
		}
	}
}
//*********������·��************** 
void output(Algraph *G) {
	int i,j,len,path[MAX_NUM];
	for (i = 1; i < G->vexnum; i++) {
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
	G0 = create();
	//Findart();
	/**************
	printf("��ӡ�ڽӱ�\n");
	for (i = 0; i < G0->vexnum; i++)   //��� 
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
