
#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct Student)

struct Student{                                        //定义结构体类型 
	long num;
	int score;
	struct Student *next;
};

struct Student list1,list2;                           //定义链表a和b 
int n,sum = 0;

struct Student *create()                              //创建链表函数        
{
	struct Student *p1,*p2,*head;
	printf("请依次输入学生的学号和成绩\n");           //录入成绩和学号 
	head = p1 = p2 = (struct Student *)malloc(LEN);                         
	scanf("%d%d",&p1->num,&p1->score);
	n = 1;
	while(p1->num!=0)
	{
	  n++;
 	  p1 = (struct Student *)malloc(LEN);
	  scanf("%d%d",&p1->num,&p1->score);
	  p2->next = p1;
	  p2 = p1;
	}
	p2->next = NULL;   	                             //将最后一个节点的尾指针指向NULL 
	return head;
}


void sort(struct Student *head)                      //对链表进行升序排列的函数 
{
	struct Student *p1,*p2;
	long tempnum;
	int tempscore,i;
	
	for(i=1;i<n;i++)
	{
		p1 = head;
		p2 = head->next;
		while(p2->next!=NULL)
		{
		  if((p1->num)>(p2->num))
		  {
			tempnum = p1->num;
			p1->num = p2->num;
			p2->num = tempnum;
			tempscore = p1->score;
			p1->score = p2->score;
			p2->score = tempscore;
		  }
		  p1 = p2;
		  p2 = p2->next;
		}
	}
}


struct Student *link(struct Student *a,struct Student *b)             //该函数将两链表连接 
{
	struct Student *pa1,*pa2,*pb1,*pb2,*abhead;                                 
	pa1 = a;
	pa2 = a->next;
	pb1 = b;
	pb2 = b->next;
	if(a->num>b->num) abhead = b;
	else abhead = a; 
	while((pb1->next)!=NULL)
	{
	  while((pa1->num)<=(pb1->num)) 
	  {
	  	pa1 = pa2;
	  	pa2 = pa2->next;
	  }	
	  pb1->next = pa2;
	  pa1->next = pb1;
	  pb1 = pb2;
	  pb2 = pb1->next;
	} 
	return abhead;
}

void print(struct Student *head)                         //将合并后的链表输出 
{
	struct Student *p;
	p = head;
	while(p->next!=NULL)
	{
		printf("%8ld%5d\n",p->num,p->score);
		p = p->next;
	}
}


int main()
{ 
	struct Student *ahead,*bhead,*ab;
	printf("请输入链表a：\n");
	ahead = create();                               //得到链表a的头地址 
	sort(ahead); 									//对a进行升序 
	sum += n;
	printf("请输入链表b: \n");
	bhead = create();                               //得到链表b的头地址 
	sort(bhead);									//对b进行升序 
	sum += n;
	ab = link(ahead,bhead);                         //将两链表连接 
	print(ab);
	return 0; 
} 
