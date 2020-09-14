#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#define MAXSIZE 100


/**********************************
一、
通过添加虚结点，为二叉树的每一实结点补足其孩子，再对补足虚结点后的二叉树按层次遍历的次序输入。
例如：ABC*DEFG**H******
构建这颗二叉树（不包含图中的虚结点），并增加左右标志域，将二叉树后序线索化。
完成后序线索化树上的遍历算法，依次输出该二叉树先序遍历、中序遍历和后序遍历的结果。

二、
输入合法的波兰式(仅考虑运算符为双目运算符的情况)，构建表达式树，分别输出对应的中缀表达式
（可含有多余的括号）、逆波兰式和表达式的值，输入的运算符与操作数之间会用空格隔开。
选做要求（二选一即可）：
1. 输出的中缀表达式中不含有多余的括号。
例如在上面的样例中，期望的输出结果应该是。
2. 输入逆波兰式，输出波兰式、中缀表达式（可含有多余的括号）和表达式的值。
**************************/
typedef enum{ 
	Link, 
	Thread 
}pointertag;
typedef struct Bitnode {
	char data;
	struct Bitnode *lchild, *rchild,*parent;       //孩子/线索
 	pointertag ltag, rtag;                 //左右标志域
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
	if ((Q.rear + 1) % MAXSIZE == Q.front)     //队列满
		printf("Queue is full");
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return 0;
}

int postorder(Bitree T) {       //后序
	if (T) {
		postorder(T->lchild);
		postorder(T->rchild);
		printf("%c", T->data);
	}
	else
		return 0;
}

Bitnode *DeQueue(SqQueue &Q){               //删除队头元素并返回其值
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

int preorder(Bitree T, int(*prin)(Bitree T)) {        //先序
	if (T) {
		prin(T);
		preorder(T->lchild, prin);
		preorder(T->rchild, prin);
	}
	else
		return 0;
}

int inorder(Bitree T, int(*prin)(Bitree T)) {         //中序
	if (T) {
		inorder(T->lchild, prin);
		prin(T);
		inorder(T->rchild, prin);
	}
	else
		return 0;
}

//层序遍历中的Visit函数，用于创建节点
int Crea(Bitree &T) {
	T = (Bitnode *)malloc(sizeof(Bitnode));
	T->data = tree[i++];
	EnQueue(Q, T);
	return 0;
}
//用层序遍历的方式创建二叉树
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
		if (Prev && Prev->rchild == NULL) //条件 Prev
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
	LevelCreate(T,Crea);                //构建二叉树
	printf("\n先序遍历：");
	preorder(T, prin);
	printf("\n中序遍历：");
	inorder(T, prin);
	printf("\n后序遍历：");
	postorder(T);
	return 0;
}

