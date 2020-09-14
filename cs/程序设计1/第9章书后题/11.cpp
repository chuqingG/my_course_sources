#include <stdio.h>
struct student
{
	int num;
	char name[10];
	struct student *next;
}a[3],b[3];
 
void create(struct student*p)        //创建并赋值 
{
 	struct student*p1;
 	int i;
 	for(p1=p,i=1;i<=3;i++)
 	{ if(i<3)
        p1->next=a+i;
	  else
	    p1->next=NULL;
	  scanf("%d %s",&p1->num,&p1->name);
	  if(i<3)
	    p1=p1->next;
	}
	for(p1=p,i=1;i<=3;i++)
	{
 	  printf("%4d%6s\n",p1->num,p1->name);
	  p1=p1->next;
	}
}
 
 
int main()
{
 	struct student *head1,*head2,*p1,*p2,*p;
 	head1 = a;
 	head2 = b;
 	printf("链表a为：\n");
 	create(a);
 	printf("链表b为：\n");
	create(b); 
 	p1 = head1;
 	while(p1!=NULL)
 	{
 		p2 = head2;
 		while((p1->num!=p2->num)&&(p2->next!=NULL))
 		  p2=p2->next;
 		if(p1->num==p2->num)
 		{
 			if(p1=head1)
 			  head1=p1->next;
 			else
 			{
 				p->next=p1->next;
 				p1=p1->next;
			}
 		}
 		else
 		{
 			p=p1;
 			p1=p1->next;
		}
	 }
	printf("删除后的结果为:\n");
	p1 = head1;
	while(p1!=NULL)
	{
		printf("%4d%6s\n",p1->num,p1->name);
		p1=p1->next;
	}
 	return 0;
 }
