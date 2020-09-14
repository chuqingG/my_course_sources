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
	if ((Q.rear+1)%MAXSIZE == Q.front)     //������
		return ERROR;
	Q.base[Q.rear] = e;
	Q.rear = (Q.rear + 1) % MAXSIZE;
	return OK;
}
/*********
int DeQueue(SqQueue &Q, char &e) {               //ɾ����ͷԪ�ز�������ֵ
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXSIZE;
	return OK;
}
*****/
int DeQueuet(SqQueue &Q, char &e) {               //ɾ����βԪ�ز�������ֵ
	if (Q.front == Q.rear)
		return ERROR;
	e = Q.base[Q.rear-1];
	Q.rear = (Q.rear - 1 + MAXSIZE) % MAXSIZE;
	return OK;
}

int main() {
	char ori[30];
	int i = 0, j;
	char temp,head;
	//char aftertran[100];
	printf("������ħ�����ԣ�\n");
	scanf("%s", ori);
	SqQueue Q;
	InitQueue(Q);
	while(ori[i]){                                 //����ħ�����Է���
		if (ori[i] == 'A') {
			printf("sae");
			i++;
			continue;
		}
		if (ori[i] == 'B') {
			printf("tsaedsae");
			i++;
			continue;
		}
		if (ori[i] == '(') {
			i++;                   //������
			head = ori[i++];           //����һ���ַ����ݴ�������Ԫ��
			while(ori[i]!=')')
				EnQueue(Q, ori[i++]);
			printf("%c", head);
			while(Q.front != Q.rear) {    //strlen�ǳ��ȣ�û�м�1
				DeQueuet(Q, temp);
				if (temp == 'A')
					printf("sae%c", head);
				else if (temp == 'B')
					printf("tsaedsae%c", head);
				else
					printf("%c%c", temp, head);
			}
			i++;                         //��֮ǰi��������
			continue;
		}
		printf("%c", ori[i++]);
	}
	return 0;
}