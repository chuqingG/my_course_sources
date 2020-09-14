#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h> 
#include <windows.h>
#define LEN sizeof(struct entry)


//����һ�����ڴ����Ľṹ��
typedef struct entry
{
	char word[32];
	char explain[128];
	char sentence[128];
	int flag;
	struct entry *next;
}entry;
entry dict;

//�������������ݶ���
entry *readin()
{
	entry *head, *tail, *pnew;

	//��ֻ����ʽ���ļ�dict.dat
	FILE *fp;
	fp = fopen("dict.dat", "rb");
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
	while (!feof(fp))
	{
		pnew = (entry *)malloc(LEN);
		if (pnew == NULL)                  //����ʧ���򷵻� 
		{
			printf("no enough memory");
			return(NULL);
		}
		fscanf(fp, "%[^_]_%[^_]_%[^\n]\n", pnew->word, pnew->explain, pnew->sentence);
		pnew->flag = 0;
		pnew->next = NULL;                                                                 //��ֱ��tail->next = NULL��ʲô����
		tail->next = pnew;
		tail = pnew;

	}
	fclose(fp);
	return head;
}

/**дһ����������������������Ƿ���ȷ
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


//���Һ��� 
void search(entry *p)
{
	char *c;
	LARGE_INTEGER timeStart;	    //��ʼʱ��
	LARGE_INTEGER timeEnd;	   	    //����ʱ�� 	
	LARGE_INTEGER frequency;	    //��ʱ��Ƶ��	
	QueryPerformanceFrequency(&frequency);
	double quadpart = (double)frequency.QuadPart;     //��ʱ��Ƶ��
	double timecost;

	printf("������һ�����ʣ�\n");
	scanf("%s", c);
	p = p->next;
	QueryPerformanceCounter(&timeStart);
	while (strcmp(p->word, c))
	{
		p= p->next;
		if(p->next==NULL)
		{
			printf("���������ڣ�\n");
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
			printf("�ô����ѱ���ǣ�\n");
	} 
	else

		printf("%s\n",p->explain);
		printf("%s\n",p->sentence);
		
	printf("��ѯʱ��Ϊ��%f seconds\n", timecost);

}


//����������Ӵ���
void add(entry *p)
{
	char s[25];
	char tail[2];
	entry *pnew;
	printf("������Ҫ��ӵĵ��ʣ�\n");
	scanf("%s", s);
	p = p->next;
	while (strcmp(p->next->word, s) < 0)
		p = p->next;
	pnew = (entry *)malloc(LEN);
	pnew->next = p->next;
	p->next = pnew;
	strcpy(pnew->word, s);
	printf("�����뵥�ʵĽ��ͣ�\n");
	scanf("\n%[^\n]", pnew->explain);
	printf("�����뵥�ʵ����䣨û��������NONE)��\n");
	scanf("\n%[^\n]", pnew->sentence);
	tail[0] ='\r';
	tail[1] = '\n';
	strcat(pnew->sentence,tail);
	pnew->flag = 0;
	
}

//��Ǵ�������
void mark(entry *p)
{
	char word[25];
	p = p->next;
	printf("���������ǵĵ��ʣ�\n");
	scanf("%s", word);
	while (strcmp(word, p->word))
		p = p->next;
	p->flag = 1;
}

//�༭��������
void edit(entry *p)
{
	char word[25];
	entry *pnew;
	p = p->next;
	printf("��������༭�ĵ��ʣ�\n");
	scanf("%s", word);
	while (strcmp(word, p->word))
		p = p->next;
	p->flag = 1;
	pnew = (entry *)malloc(LEN);
	pnew->next = p->next;
	p->next = pnew;
	strcpy(pnew->word, word);
	printf("�������µĽ��ͣ�\n");
	scanf("\n%[^\n]", pnew->explain);
	printf("�����뵥�ʵ����䣨û��������NONE)��\n");
	scanf("\n%[^\n]", pnew->sentence);
	pnew->flag = 0;
	//printf("%d %s %s",p->flag,p->next->explain,p->next->next->explain);	
}

//�������ϱ�ǵĴ���
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
	printf("Ӣ���ֵ�������¹��ܣ�\n");
	printf("1.��ѯ����\n2.����һ���´���\n3.��Ǵ�������ǹ��Ĵ����ڲ�ѯ�н�������ʾ��\n4.�༭����\n5.�����ǹ��Ĵ���\n�����������ֿ��˳��ֵ�\n"); 
	while(1)
	{
		printf("������������еĲ�����\n");
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
					 printf("�˳��ʵ�\n"); 
		}
		if(flag ==1)
			break;
	}
	
	rewrite(head);
	return 0;

}
