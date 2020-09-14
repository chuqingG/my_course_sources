#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h> 
#define LEN sizeof(struct entry)


//创建一个关于词条的结构体
typedef struct entry
{
	char *word;
	char *explain;
	char *sentence;
	struct entry *next;
}entry;
entry dict;

//创建链表，将数据读入
entry *readin()
{
	entry *head, *tail, *pnew;

	//以只读方式打开文件dict.dat
	FILE *fp;
	fp = fopen("F:\\dict.dat", "rt");
	if (fp == NULL)                   //打开失败 
	{
		printf("error");
		exit(0);
	}
	tail = head = (entry *)malloc(LEN);
	if (head == NULL)                  //创建失败则返回 
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
		pnew->next = NULL;       //和直接tail->next = NULL有什么区别？
		tail->next = pnew;
		tail = pnew;
	}
	fclose(fp);
	return head;
}

//写一个函数输出链表来检测读入是否正确
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