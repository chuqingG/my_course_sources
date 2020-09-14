/******************************************************
File name:  学生成绩管理系统
Description:读取、计算平均分、最高分和最低分、插入、删除、查找、修改、排序、保存 
Author:     PB18111688
Date:       2018.12.10
******************************************************/
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h> 
#define LEN sizeof(struct student)

//定义一个结构体存放一个学生的所有数据
struct student  
{
	char id[5];         
	char name[10];     
	int score[3];      //依次用于存放语文、数学、英语成绩
	float ave;         //平均分
	int max,min;       //最高分和最低分 
	struct student *next;
}stu[10];

/*********创建链表、读取文件并将成绩表输出***********/ 
struct student *create()
{
  struct student *head,*tail,*pnew;
  int i = 0;
  //以只读的方式打开grade.txt文件 
  
  FILE *fp;
  fp = fopen("grade2.txt","rt");
  if(fp == NULL)                   //打开失败 
  {
  	printf("error");
  	exit(0);
  } 
  head = (struct student*)malloc(LEN);     //创建头结点 
  if(head == NULL)                  //创建失败则返回 
  {
  	printf("no enough memory");
  	return(NULL);
  } 
  head->next = NULL;                   //头结点指针域置空 
  tail = head;                         //开始时尾指针指向头结点 
  while(i<8)
  {
  	pnew = (struct student *)malloc(LEN);   //开辟新结点 
  	if(pnew == NULL)                        //开辟失败则返回 
  	{
      printf("no enough memory");
  	  return(NULL);	  
    }
    
  	fscanf(fp,"%s%s%d%d%d\n",pnew->id,pnew->name,&pnew->score[0],&pnew->score[1],&pnew->score[2]);       //从文件中读成绩 
  	printf("%s,%10s,%4d,%4d,%4d\n",pnew->id,pnew->name,pnew->score[0],pnew->score[1],pnew->score[2]);     //将成绩输出到屏幕 
  	pnew->next = NULL;
  	tail->next = pnew;
  	tail = pnew;
  	i++;
  }
  fclose(fp);                         //关闭文件 
  printf("\n\n");
  return (head);                      //返回链表的头地址 
} 


/********求平均分、最高分和最低分并输出********/
void average(struct student *p)
{
	
	int i,temp;
    while(p->next != NULL)
    {
      p = p->next;
      p->max = 0;
	  p->min = 100;                                               //现将最低分设为满分,最高分设为0分 
	  p->ave = (p->score[0] + p->score[1] + p->score[2])/3.0;     //求平均值 
	  for(i = 0;i < 3;i++)
	  {
	  	if(p->score[i]>p->max)
	  	  p->max = p->score[i];               //求最大值 
	  	if(p->score[i]<p->min)
	  	  p->min = p->score[i];               //求最小值 
	  }
	  printf("%s%10s%4d%4d%4d%8.2f%4d%4d\n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->ave,p->max,p->min);      //输出数据 
	}
	printf("\n\n");
}


/*******根据id或姓名查找学生*********/
struct student *search(struct student *p)
{	
	int flag = 0;                                     //flag标记变量用于检测是否找到该学生 
	char ident[10];                                   //用于存放输入的ID或姓名 
	printf("请输入想查找的学生的ID或姓名：\n");
    scanf("%s",ident);
	while(p->next != NULL)
	{
		p = p->next;
		if(strcmp(p->id,ident) == 0||strcmp(p->name,ident) == 0)             //检查ID或姓名中是否有与输入的字符相同的 
		{
			flag = 1;
			break;
		}
	}
	if(flag == 0)                                             
			printf("找不到该学生！\n");
	else
	{
	    printf("该学生的全部信息为：\n");
	    printf("%s%10s%4d%4d%4d%8.2f%4d%4d\n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->ave,p->max,p->min);
	} 
	printf("\n\n");
	return (p);
	    
} 


/**********查找平均分大于60的学生 ***************/
void search60(struct student *p)
{
	int flag = 0;                   //标记是否查找到平均分大于60的学生
	printf("平均分大于60分的学生有：\n");
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
	  printf("不存在平均分大于60的学生"); 
	printf("\n\n");
}


/*************修改成绩*****************/
void change(struct student *p)
{
	int i,j,x;
	struct student *p1,*p2 = p->next;
	struct student temp;
	char seek[10];
	p1 = search(p);                              //使用search函数找到需要修改的学生 
    printf("请选择您想修改的科目：\n语文输入1，数学输入2，英语输入3\n");
    scanf("%d",&i);
	printf("\n请输入修改后的成绩：\n");
	scanf("%d",&x);
	p1->score[i - 1] = x;
	p1->ave = (p1->score[0] + p1->score[1] + p1->score[2])/3.0;     //求平均值 
	for(i = 0;i < 3;i++)
	{
	  	if(p1->score[i]>p1->max)
	  	    p1->max = p1->score[i];               //求最大值 
	  	if(p1->score[i]<p1->min)
	  	    p1->min = p->score[i];               //求最小值 
	}
	printf("该学生修改后的成绩为：\n");
	printf("%s%10s%4d%4d%4d\n",p1->id,p1->name,p1->score[0],p1->score[1],p1->score[2]);
	printf("\n\n");	
	FILE *fp;
	fp = fopen("grade2.txt","w");
	while(p2->next != NULL)
	{
		fprintf(fp,"%s %s %d %d %d\n",p2->id,p2->name,p2->score[0],p2->score[1],p2->score[2]);   //将新的成绩表写入文件 
		p2 = p2->next;
	}
	fclose(fp);

} 


/********将某两个学生全部数据交换的函数******/ 
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


/*************按某个属性将学生排序****************/ 
void sort(struct student *p)
{
	int i,j,k,len = 0;
	struct student *p1,*p2;
	p1 = p->next;
	while(p1 != NULL)   			//测链表长度,不包括表头结点
	{
		p1 = p1->next;
		len++;
	}
	printf("请选择要将学生按哪项数据排序：\n");
	printf("语文成绩请输入1\n数学成绩输入2\n英语成绩输入3\n平均分输入4\n");
	scanf("%d",&i);
	switch (i)
	{
		case 1: for(j = 0;j < len;j++)                        //语文成绩降序排列   
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
		case 2: for(j = 0;j < len;j++)                        //语文成绩降序排列   
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
		case 3: for(j = 0;j < len;j++)                        //语文成绩降序排列   
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
		case 4: for(j = 0;j < len;j++)                        //语文成绩降序排列   
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
		default: printf("输入错误！\n");
	}
	printf("排序后的成绩表为：\n");
	while(p->next != NULL)
	{ 
		p = p->next;
	    printf("%s%10s%4d%4d%4d%8.2f%4d%4d\n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->ave,p->max,p->min);      //输出数据 
	}
	printf("\n\n");
} 


/*********插入新纪录***********/
void insert(struct student *p)
{
	struct student stu,*pnew,*p1 = p;
	printf("请依次输入ID、姓名、语文、数学、英语成绩：\n");
	scanf("%s%s%d%d%d",stu.id,stu.name,&stu.score[0],&stu.score[1],&stu.score[2]);
	//以在末端写的方式打开文件 
	FILE *fp;
	fp = fopen("grade2.txt","a+");
    if(fp == NULL)                   //打开失败 
    {
  	    printf("error");
  	    exit(0);
    } 
    fprintf(fp,"%s %s %d %d %d",stu.id,stu.name,stu.score[0],stu.score[1],stu.score[2]);        //将数据写入文件 
    fclose(fp);
    while(p->next != NULL)
        p = p->next;
    pnew = (struct student *)malloc(LEN);      //开辟新结点 
	p->next = pnew;
	p = p->next;
	p->next = NULL;
	strcpy(p->id,stu.id);                      //将得到的数据赋给链表 
	strcpy(p->name,stu.name);
	p->score[0] = stu.score[0];
	p->score[1] = stu.score[1];
	p->score[2] = stu.score[2];
	average(p1);
	while(p1->next != NULL)
	{ 
		p1 = p1->next;
	    printf("%s%10s%4d%4d%4d\n",p1->id,p1->name,p1->score[0],p1->score[1],p1->score[2]);      //输出数据 
	}
	printf("\n\n"); 
} 


/***********删除记录*************/
void dele(struct student *p)
{
	struct student *p1 = p,*pseek,*p2;
	int flag = 0;                         //标记变量检测是否找到该学生 
	char ident[5];                        //要删除的记录的ID
	printf("请输入要删除的学生的ID：\n");
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
	    printf("未找到该学生");
	p1->next = p1->next->next;             //删除该条记录 
	FILE *fp;
	fp = fopen("grade2.txt","w");
	if(fp == NULL)                   //打开失败 
    {
  	    printf("error");
  	    exit(0);
    } 
    while(p->next != NULL)
    {
    	p = p->next;
    	printf("%s%10s%4d%4d%4d\n",p->id,p->name,p->score[0],p->score[1],p->score[2]);      //输出数据
    	fprintf(fp,"%s %s %d %d %d\n",p->id,p->name,p->score[0],p->score[1],p->score[2]);   //将新的成绩表写入文件 
	}
	fclose (fp); 	
} 


/***********************************************
Function:   
	将成绩表按照ID升序排列后保存为txt文件
parameters：
	链表的头地址head
************************************************/ 
void save(struct student *p)
{
	int j,k,len = 0;
	struct student *p1,*p2;
	average(p);
	p1 = p->next;
	while(p1 != NULL)   			//测链表长度,不包括表头结点
	{
		p1 = p1->next;
		len++;
	}
	for(j = 0;j < len;j++)                        //ID升序排列   
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
	if(fp == NULL)                   //打开失败 
    {
  	    printf("error");
  	    exit(0);
    } 
    while(p->next != NULL)
    {
    	p = p->next;
    	printf("%s%10s%4d%4d%4d%8.2f%4d%4d\n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->ave,p->max,p->min);      //输出数据 
    	fprintf(fp,"%s %s %d %d %d %.2f %d %d\n",p->id,p->name,p->score[0],p->score[1],p->score[2],p->ave,p->max,p->min);   //将新的成绩表写入文件 
	}
	fclose (fp); 	
	 
	 
} 
 


/********************主函数*********************/
int main()
{
	int i;                            //用于作为菜单选择 
	int flag = 0;                     //作为标记变量 
	struct student *head;             //链表的头地址
    head = create();
    average(head);
    printf("请输入对应数字选择您想进行的操作：\n");
    printf("1:插入一个新记录\n2:删除一条记录\n3:修改某个学生的成绩\n4:根据ID或者姓名查找某个学生的记录\n5:查找平均分高于60的学生\n6:按照某种属性对学生进行排序\n7:按照ID对学生排序，并保存成绩为txt文件\n");
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
					 printf("输入错误！\n"); 
		}
	if(flag == 1)
		break;
	}
	return 0;
} 
