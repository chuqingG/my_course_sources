/******************************************************
File name:  ѧ���ɼ�����ϵͳ
Description:��ȡ������ƽ���֡���߷ֺ���ͷ֡����롢ɾ�������ҡ��޸ġ����򡢱��� 
Author:     PB18111688
Date:       2018.12.10
******************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h> 
#define LEN sizeof(struct student)

//����һ���ṹ����һ��ѧ������������
struct student  
{
	char id[5];         
	char name[10];     
	int score[3];      //�������ڴ�����ġ���ѧ��Ӣ��ɼ�
	float ave;         //ƽ����
	int max,min;       //��߷ֺ���ͷ� 
	struct student *next;
}stu[10];

/*********����������ȡ�ļ������ɼ������***********/ 
struct student *create()
{
  struct student *head,*tail,*pnew;
  int i = 0;
  //��ֻ���ķ�ʽ��grade.txt�ļ� 
  
  FILE *fp;
  fp = fopen("grade2.txt","rt");
  if(fp == NULL)                   //��ʧ�� 
  {
  	printf("error");
  	exit(0);
  } 
  head = (struct student*)malloc(LEN);     //����ͷ��� 
  if(head == NULL)                  //����ʧ���򷵻� 
  {
  	printf("no enough memory");
  	return(NULL);
  } 
  head->next = NULL;                   //ͷ���ָ�����ÿ� 
  tail = head;                         //��ʼʱβָ��ָ��ͷ��� 
  while(i<8)
  {
  	pnew = (struct student *)malloc(LEN);   //�����½�� 
  	if(pnew == NULL)                        //����ʧ���򷵻� 
  	{
      printf("no enough memory");
  	  return(NULL);	  
    }
    
  	fscanf(fp,"%s%s%d%d%d\n",pnew->id,pnew->name,&pnew->score[0],&pnew->score[1],&pnew->score[2]);       //���ļ��ж��ɼ� 
  	printf("%s,%10s,%4d,%4d,%4d\n",pnew->id,pnew->name,pnew->score[0],pnew->score[1],pnew->score[2]);     //���ɼ��������Ļ 
  	pnew->next = NULL;
  	tail->next = pnew;
  	tail = pnew;
  	i++;
  }
  fclose(fp);                         //�ر��ļ� 
  printf("\n\n");
  return (head);                      //���������ͷ��ַ 
} 


/********��ƽ���֡���߷ֺ���ͷֲ����********/
void average(struct student *p)
{
	
	int i,temp;
    while(p->next != NULL)
    {
      p = p->next;
      p->max = 0;
	  p->min = 100;                                               //�ֽ���ͷ���Ϊ����,��߷���Ϊ0�� 
	  p->ave = (p->score[0] + p->score[1] + p->score[2])/3.0;     //��ƽ��ֵ 
	  for(i = 0;i < 3;i++)
	  {
	  	if(p->score[i]>p->max)
	  	  p->max = p->score[i];               //�����ֵ 
	  	if(p->score[i]<p->min)
	  	  p->min = p->score[i];               //����Сֵ 
	  }
	  printf("%s%10s%4d%4d%4d%8.2f%4d%4d\n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->ave,p->max,p->min);      //������� 
	}
	printf("\n\n");
}


/*******����id����������ѧ��*********/
struct student *search(struct student *p)
{	
	int flag = 0;                                     //flag��Ǳ������ڼ���Ƿ��ҵ���ѧ�� 
	char ident[10];                                   //���ڴ�������ID������ 
	printf("����������ҵ�ѧ����ID��������\n");
    scanf("%s",ident);
	while(p->next != NULL)
	{
		p = p->next;
		if(strcmp(p->id,ident) == 0||strcmp(p->name,ident) == 0)             //���ID���������Ƿ�����������ַ���ͬ�� 
		{
			flag = 1;
			break;
		}
	}
	if(flag == 0)                                             
			printf("�Ҳ�����ѧ����\n");
	else
	{
	    printf("��ѧ����ȫ����ϢΪ��\n");
	    printf("%s%10s%4d%4d%4d%8.2f%4d%4d\n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->ave,p->max,p->min);
	} 
	printf("\n\n");
	return (p);
	    
} 


/**********����ƽ���ִ���60��ѧ�� ***************/
void search60(struct student *p)
{
	int flag = 0;                   //����Ƿ���ҵ�ƽ���ִ���60��ѧ��
	printf("ƽ���ִ���60�ֵ�ѧ���У�\n");
	while(p->next != NULL)
	{
		p = p->next;
		if(p->ave > 60)
		{
			flag = 1;
			printf("%s%10s%4d%4d%4d%8.2f%4d%4d\n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->ave,p->max,p->min);
		}	
	}
	if(flag == 0)
	  printf("������ƽ���ִ���60��ѧ��"); 
	printf("\n\n");
}


/*************�޸ĳɼ�*****************/
void change(struct student *p)
{
	int i,j,x;
	struct student *p1,*p2 = p->next;
	struct student temp;
	char seek[10];
	p1 = search(p);                              //ʹ��search�����ҵ���Ҫ�޸ĵ�ѧ�� 
    printf("��ѡ�������޸ĵĿ�Ŀ��\n��������1����ѧ����2��Ӣ������3\n");
    scanf("%d",&i);
	printf("\n�������޸ĺ�ĳɼ���\n");
	scanf("%d",&x);
	p1->score[i - 1] = x;
	p1->ave = (p1->score[0] + p1->score[1] + p1->score[2])/3.0;     //��ƽ��ֵ 
	for(i = 0;i < 3;i++)
	{
	  	if(p1->score[i]>p1->max)
	  	    p1->max = p1->score[i];               //�����ֵ 
	  	if(p1->score[i]<p1->min)
	  	    p1->min = p->score[i];               //����Сֵ 
	}
	printf("��ѧ���޸ĺ�ĳɼ�Ϊ��\n");
	printf("%s%10s%4d%4d%4d\n",p1->id,p1->name,p1->score[0],p1->score[1],p1->score[2]);
	printf("\n\n");	
	FILE *fp;
	fp = fopen("grade2.txt","w");
	while(p2->next != NULL)
	{
		fprintf(fp,"%s %s %d %d %d\n",p2->id,p2->name,p2->score[0],p2->score[1],p2->score[2]);   //���µĳɼ���д���ļ� 
		p2 = p2->next;
	}
	fclose(fp);

} 


/********��ĳ����ѧ��ȫ�����ݽ����ĺ���******/ 
void swap(struct student *p1,struct student *p2)
{
	int temp1;
	char temp2[10];
	float temp3;
	strcpy(temp2,p1->id);
	strcpy(p1->id,p2->id);
	strcpy(p2->id,temp2);
	strcpy(temp2,p1->name);
	strcpy(p1->name,p2->name);
	strcpy(p2->name,temp2);
	temp1 = p1->score[0];
	p1->score[0] = p2->score[0];
	p2->score[0] = temp1;
	temp1 = p1->score[1];
	p1->score[1] = p2->score[1];
	p2->score[1] = temp1;
	temp1 = p1->score[2];
	p1->score[2] = p2->score[2];
	p2->score[2] = temp1;
	temp1 = p1->max;
	p1->max = p2->max;
	p2->max = temp1;
	temp1 = p1->min;
	p1->min = p2->min;
	p2->min = temp1;
	temp3 = p1->ave;
	p1->ave = p2->ave;
	p2->ave = temp3;		
}


/*************��ĳ�����Խ�ѧ������****************/ 
void sort(struct student *p)
{
	int i,j,k,len = 0;
	struct student *p1,*p2;
	p1 = p->next;
	while(p1 != NULL)   			//��������,��������ͷ���
	{
		p1 = p1->next;
		len++;
	}
	printf("��ѡ��Ҫ��ѧ����������������\n");
	printf("���ĳɼ�������1\n��ѧ�ɼ�����2\nӢ��ɼ�����3\nƽ��������4\n");
	scanf("%d",&i);
	switch (i)
	{
		case 1: for(j = 0;j < len;j++)                        //���ĳɼ���������   
				{
					p1 = p->next;
					p2 = p->next->next;
		            for(k = 0;k <len - j - 1;k++)
		            {
		       	    	if(p1->score[0] < p2->score[0])
		       	        	swap(p1,p2);    
						p1 = p1->next;
						p2 = p2->next;            
		       	    } 
			    };break;
		case 2: for(j = 0;j < len;j++)                        //���ĳɼ���������   
				{
					p1 = p->next;
					p2 = p->next->next;
		            for(k = 0;k <len - j - 1;k++)
		            {
		       	    	if(p1->score[1] < p2->score[1])
		       	        	swap(p1,p2);  
						p1 = p1->next;
						p2 = p2->next;               
		       	    } 
			    };break;
		case 3: for(j = 0;j < len;j++)                        //���ĳɼ���������   
				{
					p1 = p->next;
					p2 = p->next->next;
		            for(k = 0;k <len - j - 1;k++)
		            {
		       	    	if(p1->score[2] < p2->score[2])
		       	        	swap(p1,p2); 
						p1 = p1->next;
						p2 = p2->next;                
		       	    } 
			    };break;
		case 4: for(j = 0;j < len;j++)                        //���ĳɼ���������   
				{
					p1 = p->next;
					p2 = p->next->next;
		            for(k = 0;k <len - j - 1;k++)
		            {
		       	    	if(p1->ave < p2->ave)
		       	        	swap(p1,p2);
						p1 = p1->next;
						p2 = p2->next;                 
		       	    } 
			    };break;
		default: printf("�������\n");
	}
	printf("�����ĳɼ���Ϊ��\n");
	while(p->next != NULL)
	{ 
		p = p->next;
	    printf("%s%10s%4d%4d%4d%8.2f%4d%4d\n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->ave,p->max,p->min);      //������� 
	}
	printf("\n\n");
} 


/*********�����¼�¼***********/
void insert(struct student *p)
{
	struct student stu,*pnew,*p1 = p;
	printf("����������ID�����������ġ���ѧ��Ӣ��ɼ���\n");
	scanf("%s%s%d%d%d",stu.id,stu.name,&stu.score[0],&stu.score[1],&stu.score[2]);
	//����ĩ��д�ķ�ʽ���ļ� 
	FILE *fp;
	fp = fopen("grade2.txt","a+");
    if(fp == NULL)                   //��ʧ�� 
    {
  	    printf("error");
  	    exit(0);
    } 
    fprintf(fp,"%s %s %d %d %d",stu.id,stu.name,stu.score[0],stu.score[1],stu.score[2]);        //������д���ļ� 
    fclose(fp);
    while(p->next != NULL)
        p = p->next;
    pnew = (struct student *)malloc(LEN);      //�����½�� 
	p->next = pnew;
	p = p->next;
	p->next = NULL;
	strcpy(p->id,stu.id);                      //���õ������ݸ������� 
	strcpy(p->name,stu.name);
	p->score[0] = stu.score[0];
	p->score[1] = stu.score[1];
	p->score[2] = stu.score[2];
	average(p1);
	while(p1->next != NULL)
	{ 
		p1 = p1->next;
	    printf("%s%10s%4d%4d%4d\n",p1->id,p1->name,p1->score[0],p1->score[1],p1->score[2]);      //������� 
	}
	printf("\n\n"); 
} 


/***********ɾ����¼*************/
void dele(struct student *p)
{
	struct student *p1 = p,*pseek,*p2;
	int flag = 0;                         //��Ǳ�������Ƿ��ҵ���ѧ�� 
	char ident[5];                        //Ҫɾ���ļ�¼��ID
	printf("������Ҫɾ����ѧ����ID��\n");
	scanf("%s",ident);
	while(p1->next->next != NULL)
	{
		if(strcmp(ident,p1->next->id) == 0)
    	{
    		flag = 1;
    		break;
		}
		p1 = p1->next;
	}
	if(flag == 0)
	    printf("δ�ҵ���ѧ��");
	p1->next = p1->next->next;             //ɾ��������¼ 
	FILE *fp;
	fp = fopen("grade2.txt","w");
	if(fp == NULL)                   //��ʧ�� 
    {
  	    printf("error");
  	    exit(0);
    } 
    while(p->next != NULL)
    {
    	p = p->next;
    	printf("%s%10s%4d%4d%4d\n",p->id,p->name,p->score[0],p->score[1],p->score[2]);      //�������
    	fprintf(fp,"%s %s %d %d %d\n",p->id,p->name,p->score[0],p->score[1],p->score[2]);   //���µĳɼ���д���ļ� 
	}
	fclose (fp); 	
} 


/***********************************************
Function:   
	���ɼ�����ID�������к󱣴�Ϊtxt�ļ�
parameters��
	�����ͷ��ַhead
************************************************/ 
void save(struct student *p)
{
	int j,k,len = 0;
	struct student *p1,*p2;
	average(p);
	p1 = p->next;
	while(p1 != NULL)   			//��������,��������ͷ���
	{
		p1 = p1->next;
		len++;
	}
	for(j = 0;j < len;j++)                        //ID��������   
	{
		p1 = p->next;
		p2 = p->next->next;
	    for(k = 0;k <len - j - 1;k++)
		{
		    if(strcmp(p1->id,p2->id) > 0)
		       	swap(p1,p2);    
			p1 = p1->next;
			p2 = p2->next;            
		} 
    };	
	FILE *fp;
	fp = fopen("gradeid.txt","w");
	if(fp == NULL)                   //��ʧ�� 
    {
  	    printf("error");
  	    exit(0);
    } 
    while(p->next != NULL)
    {
    	p = p->next;
    	printf("%s%10s%4d%4d%4d%8.2f%4d%4d\n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->ave,p->max,p->min);      //������� 
    	fprintf(fp,"%s %s %d %d %d %.2f %d %d\n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->ave,p->max,p->min);   //���µĳɼ���д���ļ� 
	}
	fclose (fp); 	
	 
	 
} 
 


/********************������*********************/
int main()
{
	int i;                            //������Ϊ�˵�ѡ�� 
	int flag = 0;                     //��Ϊ��Ǳ��� 
	struct student *head;             //�����ͷ��ַ
    head = create();
    average(head);
    printf("�������Ӧ����ѡ��������еĲ�����\n");
    printf("1:����һ���¼�¼\n2:ɾ��һ����¼\n3:�޸�ĳ��ѧ���ĳɼ�\n4:����ID������������ĳ��ѧ���ļ�¼\n5:����ƽ���ָ���60��ѧ��\n6:����ĳ�����Զ�ѧ����������\n7:����ID��ѧ�����򣬲�����ɼ�Ϊtxt�ļ�\n");
    while(1)
	{
		scanf("%d",&i);
    	switch(i)
    	{
    		case(1): insert(head);break;
			case(2): dele(head);break;
			case(3): change(head);break;
			case(4): search(head);break;
			case(5): search60(head);break;
			case(6): sort(head);break;
			case(7): save(head);break;
			default: flag = 1;
					 printf("�������\n"); 
		}
	if(flag == 1)
		break;
	}
	return 0;
} 
