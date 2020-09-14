#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <math.h>
#define MAXSIZE 100
/***********
Input:
- + 2 3 1 //波兰式
Output:
(2+3)-1 //中缀表达式
23+1-   //逆波兰
4       //求值 
2+3-1   //去掉多余括号 
************/
char str[30];
int i = 0;
typedef struct Bitnode {
	char data[4];                     //只支持三位以内数字输入         
	struct Bitnode *lchild, *rchild;    
}Bitnode, *Bitree;

int create(Bitree &T) {               //创建表达式树               
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
	i++;                      //跳过空格 
	if (str[i - 2] < '0'      )//是操作符 
	{
		create(T->lchild);
		create(T->rchild);
	}
	return 0;
}

int prin(Bitree T) {               //打印带空格的波兰式 
	printf("%s ", T->data);
	return 0;
}

int pri(Bitree T) {                //打印不带空格的中缀表达式 
	printf("%s", T->data);
	return 0;
}
int postorder(Bitree T, int(*prin)(Bitree T)) {       //逆波兰
	if (T) {
		postorder(T->lchild, prin);
		postorder(T->rchild, prin);
		prin(T);
	}
	else	return 0;
}
int inorder(Bitree T, int(*pri)(Bitree T)) {         //有多余括号的中缀 
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

int inorderp(Bitree T, int(*pri)(Bitree T)) {         //去多余括号的中缀 
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
int calc(Bitree T){                                //计算某个字符串对应数字值 
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
