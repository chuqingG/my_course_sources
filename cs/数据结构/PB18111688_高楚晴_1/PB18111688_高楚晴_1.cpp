#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#define LEN sizeof(struct person)

typedef struct person{
	int num;
	int key;
	struct person *next;
}person;
person *p;

person *Init() {
	p = (person *)malloc(LEN);                        
	p->next = p;
	return p;
}

int main(int argc, char *argv[]) {
	person *pnew, *head;
	int m,n,k,count;
	freopen("output.txt", "w", stdout);
	//printf("����<��ִ�г�����> <����n> <��ʼ�ı�������m> <����1>...<����n>�ĸ�ʽ�������룺\n");
	n = atoi(argv[1]);
	head = Init();
	m = atoi(argv[2]);
	for (k = 3; k < n + 3;k++) {
		pnew = (person*)malloc(LEN);
		pnew->key = atoi(argv[k]);
		pnew->num = k - 2;
		pnew->next = head->next;
		p->next = pnew;
		p = p->next;
	}
	for (k = 1; k < n; k++) {
		for (count = 1; count < m; count++) 
			p = p->next;
		m = p->next->key;           //����m��ֵΪ�ó�Ա������
		printf("%d ",p->next->num);
		p->next = p->next->next;    //ɾ���ó�Ա
	}
	printf("%d", p->next->num);
	return 0;
}
