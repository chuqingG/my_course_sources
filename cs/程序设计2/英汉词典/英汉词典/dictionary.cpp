#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h> 
#define LEN sizeof(struct entry)


//����һ�����ڴ����Ľṹ��
typedef struct entry
{
	char *word;
	char *explain;
	char *sentence;
	struct entry *next;
}entry;
entry dict;

//�������������ݶ���
entry *readin()
{
	entry *head, *tail, *pnew;

	//��ֻ����ʽ���ļ�dict.dat
	FILE *fp;
	fp = fopen("F:\\dict.dat", "rt");
	if (fp == NULL)                   //��ʧ�� 
	{
		printf("error");
		exit(0);
	}
	tail = head = (entry *)malloc(LEN);
	if (head == NULL)                  //����ʧ���򷵻� 
	{
		printf("no enough memory");
		return(NULL);
	}
	tail->next = NULL;
	pnew = (entry *)malloc(LEN);
	while (!feof(fp))
	{
		pnew = (entry *)malloc(LEN);
		fscanf(fp, "%[^_]_%[^_]_", pnew->word, pnew->explain);
		fgets(pnew->sentence, 100,fp);
		fgetc(fp);
		pnew->next = NULL;       //��ֱ��tail->next = NULL��ʲô����
		tail->next = pnew;
		tail = pnew;
	}
	fclose(fp);
	return head;
}

//дһ����������������������Ƿ���ȷ
void output(entry *x)
{
	entry *p =x;
	int i;
	for (i = 0; i < 10; i++)
	{
		printf("%s\n    %s\n    %s\n", p->word, p->explain, p->sentence);
		p = p->next;
	}
}

int main()
{
	entry *head;
	head = readin();
	output(head);
	return 0;

}