#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h> 
#include <windows.h>
#define LEN sizeof(struct entry)


//创建一个关于词条的结构体
typedef struct entry
{
	char word[32];
	char explain[128];
	char sentence[128];
	int flag;
	struct entry *next;
}entry;
entry dict;

//创建链表，将数据读入
entry *readin()
{
	entry *head, *tail, *pnew;

	//以只读方式打开文件dict.dat
	FILE *fp;
	fp = fopen("dict.dat", "rb");
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
	while (!feof(fp))
	{
		pnew = (entry *)malloc(LEN);
		if (pnew == NULL)                  //创建失败则返回 
		{
			printf("no enough memory");
			return(NULL);
		}
		fscanf(fp, "%[^_]_%[^_]_%[^\n]\n", pnew->word, pnew->explain, pnew->sentence);
		pnew->flag = 0;
		pnew->next = NULL;                                                                 //和直接tail->next = NULL有什么区别？
		tail->next = pnew;
		tail = pnew;

	}
	fclose(fp);
	return head;
}

/**写一个函数输出链表来检测读入是否正确
void output(entry *x)
{
	entry *p = x;
	int i;
	p = p->next;
	for (i = 0; i < 10; i++)
	{
		printf("%s\n    %s\n    %s\n", p->word, p->explain, p->sentence);
		p = p->next;
	}
}
*******/


//查找函数 
void search(entry *p)
{
	char *c;
	LARGE_INTEGER timeStart;	    //开始时间
	LARGE_INTEGER timeEnd;	   	    //结束时间 	
	LARGE_INTEGER frequency;	    //计时器频率	
	QueryPerformanceFrequency(&frequency);
	double quadpart = (double)frequency.QuadPart;     //计时器频率
	double timecost;

	printf("请输入一个单词：\n");
	scanf("%s", c);
	p = p->next;
	QueryPerformanceCounter(&timeStart);
	while (strcmp(p->word, c))
	{
		p= p->next;
		if(p->next==NULL)
		{
			printf("词条不存在！\n");
			return;
		}
	} 
	QueryPerformanceCounter(&timeEnd);
	timecost = (timeEnd.QuadPart - timeStart.QuadPart) / quadpart;
	if(p->flag)
	{
		if(strcmp(p->next->word,c)==0)
			printf("%s\n%s\n",p->next->explain,p->next->sentence);
		else
			printf("该词条已被标记！\n");
	} 
	else

		printf("%s\n",p->explain);
		printf("%s\n",p->sentence);
		
	printf("查询时间为：%f seconds\n", timecost);

}


//操作链表添加词条
void add(entry *p)
{
	char s[25];
	char tail[2];
	entry *pnew;
	printf("请输入要添加的单词：\n");
	scanf("%s", s);
	p = p->next;
	while (strcmp(p->next->word, s) < 0)
		p = p->next;
	pnew = (entry *)malloc(LEN);
	pnew->next = p->next;
	p->next = pnew;
	strcpy(pnew->word, s);
	printf("请输入单词的解释；\n");
	scanf("\n%[^\n]", pnew->explain);
	printf("请输入单词的例句（没有请输入NONE)；\n");
	scanf("\n%[^\n]", pnew->sentence);
	tail[0] ='\r';
	tail[1] = '\n';
	strcat(pnew->sentence,tail);
	pnew->flag = 0;
	
}

//标记词条功能
void mark(entry *p)
{
	char word[25];
	p = p->next;
	printf("请输入想标记的单词：\n");
	scanf("%s", word);
	while (strcmp(word, p->word))
		p = p->next;
	p->flag = 1;
}

//编辑词条功能
void edit(entry *p)
{
	char word[25];
	entry *pnew;
	p = p->next;
	printf("请输入想编辑的单词：\n");
	scanf("%s", word);
	while (strcmp(word, p->word))
		p = p->next;
	p->flag = 1;
	pnew = (entry *)malloc(LEN);
	pnew->next = p->next;
	p->next = pnew;
	strcpy(pnew->word, word);
	printf("请输入新的解释：\n");
	scanf("\n%[^\n]", pnew->explain);
	printf("请输入单词的例句（没有请输入NONE)；\n");
	scanf("\n%[^\n]", pnew->sentence);
	pnew->flag = 0;
	//printf("%d %s %s",p->flag,p->next->explain,p->next->next->explain);	
}

//清理被打上标记的词条
void clean(entry *p)
{
	while (p->next != NULL)
	{
		if (p->next->flag == 1)
			p->next = p->next->next;
		p = p->next;
	}
}

void cleantest(entry *p)
{
	p = p->next;
	while (p->next != NULL)
	{
		if (p->flag)
			printf("q");
		p = p->next;
	}
}

void rewrite(entry *p)
{
	FILE *fp;
	char s[2];
	s[0] = '\n';
	s[1] = '\r'; 
	fp = fopen("dict.dat","wb");
	p = p->next;
	while(p->next!=NULL)
	{
		fprintf(fp,"%s_%s_%s",p->word,p->explain,p->sentence);
		fwrite(s,2,1,fp);
		p = p->next;
	}
	fclose(fp);
}

int main()
{
	int num;
	int flag = 0; 
	entry *head;
	head = readin();
	/*search(head);
	add(head);
	output(head);
	cleantest(head);****/
	printf("英汉字典具有以下功能：\n");
	printf("1.查询词条\n2.加入一个新词条\n3.标记词条（标记过的词条在查询中将不再显示）\n4.编辑词条\n5.清理标记过的词条\n输入其他数字可退出字典\n"); 
	while(1)
	{
		printf("请输入您想进行的操作：\n");
		scanf("%d",&num);
		switch(num)
    	{
    		case 1: search(head);
					 break;
			case 2: add(head);
					 break;
			case 3: mark(head);
					 break;
			case 4: edit(head);
					 break;
			case 5: clean(head);
					 break;
			default: flag = 1;
					 printf("退出词典\n"); 
		}
		if(flag ==1)
			break;
	}
	
	rewrite(head);
	return 0;

}
