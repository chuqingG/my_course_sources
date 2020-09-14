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
	//printf("请以<可执行程序名> <人数n> <初始的报数上限m> <密码1>...<密码n>的格式进行输入：\n");
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
		m = p->next->key;           //更新m的值为该成员的密码
		printf("%d ",p->next->num);
		p->next = p->next->next;    //删除该成员
	}
	printf("%d", p->next->num);
	return 0;
}
