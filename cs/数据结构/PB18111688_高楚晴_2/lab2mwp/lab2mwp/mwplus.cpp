#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>
#define MAXSIZE 100
#define ERROR -1
#define OVERFLOW -2
#define OK 1
#define STACKINCREMENT 10
typedef struct {
	char *base;
	int front;
	int rear;
}SqQueue;

int InitQueue(SqQueue &Q) {
	Q.base = (char *)malloc(MAXSIZE * sizeof(char));
	if (!Q.base)
		exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return OK;
}

int QueueLength(SqQueue Q) {
	return(Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

int EnQueue(SqQueue &Q, char e) {
	if ((Q.rear + 1) % MAXSIZE == Q.front)     //队列满
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return OK;
}
/*********
int DeQueue(SqQueue &Q, char &e) {               //删除队头元素并返回其值
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return OK;
}
*****/
int DeQueuet(SqQueue &Q, char &e) {               //删除队尾元素并返回其值
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.rear - 1];
	Q.rear = (Q.rear - 1 + MAXSIZE) % MAXSIZE;
	return OK;
}

int main() {
	char ori[30];
	char name[5];
	int label[5];
	char tran[5][40];
	int i = 0, j,k,t;
	int len1, len2;
	char temp, head,num,flag;
	//char aftertran[100];
	printf("请输入魔王语言语法规则：[输入0结束语法输入]\n");
	while (1) {
		scanf("%c", &name[i]);
		if (name[i] == '0')
			break;
		scanf("%s", tran[i]);
		getchar();
		i++;
	}
	num = i;
	for (i = 0; i < num; i++) {
		for(j = 0;j<strlen(tran[j]);j++)
			if (tran[i][j] < 'a') {
				label[i] = 1;
				break;
			}
	}
	for (i = 0; i < num; i++) {
		if (label[i] == 0)
			continue;
		for (j = 0; j < strlen(tran[j]); j++) {
			if (tran[i][j] >= 'a') continue;
			for (k = 0; k < num; k++) {
				if (tran[i][j] == name[k] && label[k] == 0) {
					len1 = strlen(tran[k]);
					len2 = strlen(tran[j]);
					for (t = j+1; t < len2; t++) 
						tran[i][t + len1-1] = tran[i][t];
					for (t = j; t < len1; t++)
						tran[i][t] = tran[k][t - j];
				}

			}
		}
	}
	for (i = 0; i < num; i++) {
		for (j = 0; j < strlen(tran[j]); j++)
			if (tran[i][j] < 'a') {
				label[i] = 1;
				break;
			}
	}
	for (i = 0; i < num; i++) {
		if (label[i] == 0)
			continue;
		for (j = 0; j < strlen(tran[j]); j++) {
			if (tran[i][j] >= 'a') continue;
			for (k = 0; k < num; k++) {
				if (tran[i][j] == name[k] && label[k] == 0) {
					len1 = strlen(tran[k]);
					len2 = strlen(tran[j]);
					for (t = j + 1; t < len2; t++)
						tran[i][t + len1 - 1] = tran[i][t];
					for (t = j; t < len1; t++)
						tran[i][t] = tran[k][t - j];
				}

			}
		}
	}
	printf("请输入魔王语言：\n");
	scanf("%s", ori);
	SqQueue Q;
	InitQueue(Q);
	i = 0;
	while (ori[i]) {  //进行魔王语言翻译
		flag = 0;
		for (j = 0; j < num; j++) {
			if (ori[i] == name[j]) {
				printf("%s", tran[j]);
				i++;
				flag = 1;
			}
		}
		if (flag == 1) continue;
		if (ori[i] == '(') {
			i++;                   //跳过（
			head = ori[i++];           //先用一个字符串暂存括号内元素
			while (ori[i] != ')')
				EnQueue(Q, ori[i++]);
			printf("%c", head);
			while (Q.front != Q.rear) {    //strlen是长度，没有减1
				DeQueuet(Q, temp);
				flag = 0;
				for (j = 0; j < num; j++) {
					if (temp == name[j]) {
						printf("%s%c", tran[j],head);
						flag = 1;
					}
				}
				if (flag == 1)
					continue;
				printf("%c%c", temp, head);
			}
			i++;                         //加之前i是右括号
			continue;
		}
		printf("%c", ori[i++]);
	}
	return 0;
}