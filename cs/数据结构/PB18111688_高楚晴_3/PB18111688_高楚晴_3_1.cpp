#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAXSIZE 100


/**********************************
һ��
ͨ��������㣬Ϊ��������ÿһʵ��㲹���亢�ӣ��ٶԲ��������Ķ���������α����Ĵ������롣
���磺ABC*DEFG**H******
������Ŷ�������������ͼ�е����㣩�����������ұ�־�򣬽�������������������
��ɺ������������ϵı����㷨����������ö����������������������ͺ�������Ľ����

����
����Ϸ��Ĳ���ʽ(�����������Ϊ˫Ŀ����������)���������ʽ�����ֱ������Ӧ����׺���ʽ
���ɺ��ж�������ţ����沨��ʽ�ͱ��ʽ��ֵ�������������������֮����ÿո������
ѡ��Ҫ�󣨶�ѡһ���ɣ���
1. �������׺���ʽ�в����ж�������š�
����������������У�������������Ӧ���ǡ�
2. �����沨��ʽ���������ʽ����׺���ʽ���ɺ��ж�������ţ��ͱ��ʽ��ֵ��
**************************/
typedef enum{ 
	Link, 
	Thread 
}pointertag;
typedef struct Bitnode {
	char data;
	struct Bitnode *lchild, *rchild,*parent;       //����/����
 	pointertag ltag, rtag;                 //���ұ�־��
}Bitnode,*Bitree;
typedef struct Qnode {
	Bitree data;
	struct Qnode *next;
}Qnode, *QueueP;
typedef struct {
	Bitnode **base;
	int front;
	int rear;
}SqQueue;


char tree[50];
int i = 0;
SqQueue Q;
Bitnode *Prev;

int InitQueue(SqQueue &Q) {
	Q.base = (Bitnode **)malloc(MAXSIZE * sizeof(char));
	if (!Q.base)
		printf("fail to initqueue");
	Q.front = Q.rear = 0;
	return 0;
}

int EnQueue(SqQueue &Q, Bitnode *e) {
	if ((Q.rear + 1) % MAXSIZE == Q.front)     //������
		printf("Queue is full");
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return 0;
}

int postorder(Bitree T) {       //����
	if (T) {
		postorder(T->lchild);
		postorder(T->rchild);
		printf("%c", T->data);
	}
	else
		return 0;
}

Bitnode *DeQueue(SqQueue &Q){               //ɾ����ͷԪ�ز�������ֵ
	Bitnode *e;
	if (Q.front == Q.rear)
		printf("Queue is empty");
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return e;
}

int Isempty(SqQueue &Q)
{
	return (Q.front == Q.rear);
}

int prin(Bitree T) {
	printf("%c", T->data);
	return 0;
}

int preorder(Bitree T, int(*prin)(Bitree T)) {        //����
	if (T) {
		prin(T);
		preorder(T->lchild, prin);
		preorder(T->rchild, prin);
	}
	else
		return 0;
}

int inorder(Bitree T, int(*prin)(Bitree T)) {         //����
	if (T) {
		inorder(T->lchild, prin);
		prin(T);
		inorder(T->rchild, prin);
	}
	else
		return 0;
}

//��������е�Visit���������ڴ����ڵ�
int Crea(Bitree &T) {
	T = (Bitnode *)malloc(sizeof(Bitnode));
	T->data = tree[i++];
	EnQueue(Q, T);
	return 0;
}
//�ò�������ķ�ʽ����������
int LevelCreate(Bitree &T, int(*Crea)(Bitree &)) {
	Bitnode *p;
	InitQueue(Q);
	Crea(T);
	while (!Isempty(Q)) {
		p = DeQueue(Q);
		if (tree[i] == '*') {
			p->lchild = NULL;
			i++;
		}
		else {
			Crea(p->lchild);
			p->lchild->parent = p;
		}
		if (tree[i] == '*') {
			p->rchild = NULL;
			i++;
		}
		else {
			Crea(p->rchild);
			p->rchild->parent = p;
		}
	}
	return 0;
}

int PostThreading(Bitnode*& t)
{
	if (t)
	{
		PostThreading(t->lchild);
		PostThreading(t->rchild);
		if (t->lchild == NULL)
		{
			t->lchild = Prev;
			t->ltag = Thread;
		}
		if (Prev && Prev->rchild == NULL) //���� Prev
		{
			Prev->rchild = t;
			Prev->rtag = Thread;
		}
		Prev = t;
	}
	return 0;
}

int Postorder(Bitnode *t){
	if (!t)
		return 0;
	else {
		Bitnode* temp = t;
		Prev = NULL;
		while (temp)
		{
			while (temp ->lchild != Prev && temp->ltag == Link) 
				temp = temp ->lchild;
			while (temp && temp->rtag == Thread)
			{
				printf("%c", temp->data);
				Prev = temp;
				temp = temp->rchild;
			}
			if (temp == t)
			{
				printf("%c", temp->data);
				return 0;
			}
			while (temp && temp->rchild == Prev)
			{
				printf("%c", temp->data);
				Prev = temp;
				temp = temp->parent;  
			}
			if (temp && temp->rtag == Link)
			{
				temp = temp->rchild;
			}
		}
	}
}



int main() {
	Bitree T;
	scanf("%s", tree);
	LevelCreate(T,Crea);                //����������
	printf("\n���������");
	preorder(T, prin);
	printf("\n���������");
	inorder(T, prin);
	printf("\n���������");
	postorder(T);
	return 0;
}

