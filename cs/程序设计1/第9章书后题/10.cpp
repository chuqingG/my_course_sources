
#include <stdio.h>
#include <stdlib.h>
#define LEN sizeof(struct Student)

struct Student{                                        //����ṹ������ 
	long num;
	int score;
	struct Student *next;
};

struct Student list1,list2;                           //��������a��b 
int n,sum = 0;

struct Student *create()                              //����������        
{
	struct Student *p1,*p2,*head;
	printf("����������ѧ����ѧ�źͳɼ�\n");           //¼��ɼ���ѧ�� 
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
	p2->next = NULL;   	                             //�����һ���ڵ��βָ��ָ��NULL 
	return head;
}


void sort(struct Student *head)                      //����������������еĺ��� 
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


struct Student *link(struct Student *a,struct Student *b)             //�ú��������������� 
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

void print(struct Student *head)                         //���ϲ����������� 
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
	printf("����������a��\n");
	ahead = create();                               //�õ�����a��ͷ��ַ 
	sort(ahead); 									//��a�������� 
	sum += n;
	printf("����������b: \n");
	bhead = create();                               //�õ�����b��ͷ��ַ 
	sort(bhead);									//��b�������� 
	sum += n;
	ab = link(ahead,bhead);                         //������������ 
	print(ab);
	return 0; 
} 
