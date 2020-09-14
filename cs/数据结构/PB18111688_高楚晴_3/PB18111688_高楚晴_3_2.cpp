#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
#define MAXSIZE 100
/***********
Input:
- + 2 3 1 //����ʽ
Output:
(2+3)-1 //��׺���ʽ
23+1-   //�沨��
4       //��ֵ 
2+3-1   //ȥ���������� 
************/
char str[30];
int i = 0;
typedef struct Bitnode {
	char data[4];                     //ֻ֧����λ������������         
	struct Bitnode *lchild, *rchild;    
}Bitnode, *Bitree;

int create(Bitree &T) {               //�������ʽ��               
	int j;
	if (!str[i])
		return 0;
	T = (Bitree)malloc(sizeof(Bitnode));
	if(str[i]<'0'){
		T->data[0] = str[i++];
		T->data[1] = '\0';
	}
	else{
		j = 0;
		while(str[i]!=' '&&str[i]!='\0')
			T->data[j++] = str[i++];
		T->data[j] = '\0';	
	}
	T->lchild = NULL;
	T->rchild = NULL;
	i++;                      //�����ո� 
	if (str[i - 2] < '0'      )//�ǲ����� 
	{
		create(T->lchild);
		create(T->rchild);
	}
	return 0;
}

int prin(Bitree T) {               //��ӡ���ո�Ĳ���ʽ 
	printf("%s ", T->data);
	return 0;
}

int pri(Bitree T) {                //��ӡ�����ո����׺���ʽ 
	printf("%s", T->data);
	return 0;
}
int postorder(Bitree T, int(*prin)(Bitree T)) {       //�沨��
	if (T) {
		postorder(T->lchild, prin);
		postorder(T->rchild, prin);
		prin(T);
	}
	else	return 0;
}
int inorder(Bitree T, int(*pri)(Bitree T)) {         //�ж������ŵ���׺ 
	if (T) {
		if (T->lchild->data[0] < '0') {
			printf("(");
			inorder(T->lchild, pri);
			printf(")");
		}
		else	pri(T->lchild);
		pri(T);
		if (T->rchild->data[0] < '0') {
			printf("(");
			inorder(T->rchild, pri);
			printf(")");
		}
		else	pri(T->rchild);
	}
	else	return 0;
}

int inorderp(Bitree T, int(*pri)(Bitree T)) {         //ȥ�������ŵ���׺ 
	if (T) {
		if (T->lchild->data[0] < '0') {
			if ((T->lchild->data[0] == '+' || T->lchild->data[0] == '-') && (T->data[0] == '*' || T->data[0] == '/')) {
				printf("(");
				inorderp(T->lchild, pri);
				printf(")");
			}
			else	inorderp(T->lchild, pri);
		}
		else	pri(T->lchild);
		pri(T);
		if (T->rchild->data[0] < '0') {
			if ((T->rchild->data[0] == '*' || T->rchild->data[0] == '/') && (T->data[0] == '+' || T->data[0] == '-'))
				inorderp(T->rchild, pri);
			else {
				printf("(");
				inorderp(T->rchild, pri);
				printf(")");
			}
		}
		else
			pri(T->rchild);
	}
	else	return 0;
}
int calc(Bitree T){                                //����ĳ���ַ�����Ӧ����ֵ 
	int k = 0,num = 0;
	while(T->data[k]!='\0')
		num = num*10+(T->data[k++]-'0');
	return num;
}
int count(Bitree T) {
	if (T->data[0] >= '0')
		return calc(T);
	else {
		switch (T->data[0]) {
		case '+': return count(T->lchild) + count(T->rchild);
		case '-': return count(T->lchild) - count(T->rchild);
		case '*': return count(T->lchild) * count(T->rchild);
		case '/': return count(T->lchild) / count(T->rchild);
		}
	}
	return 0;
}

int main() {
	gets(str);
	Bitree T;
	create(T);
	inorder(T, pri);
	printf("\n");
	postorder(T, prin);
	printf("\n");
	printf("%d", count(T));
	printf("\n");
	inorderp(T, pri);
	return 0;
}
