#include <stdio.h>
#include <string.h>
int i,j,number[10];
char name[10][10];
int main()
{
  int num;
  printf("请输入每个职工的姓名和职工号：\n"); 
  void input_();
  void sort_();
  void search_(int n);
  input_();
  sort_();
  printf("输入一个职工号：\n");
  scanf("%d",&num);
  search_(num);
  return 0;
} 

void input_()
{
  for(i=0;i<10;i++)
  {
    printf("第%d个职工：",i+1);
    gets(name[i]);
	scanf("%d",&number[i]);
  }
}

void sort_()
{
  int swap1,min=0;
  char swap2[10];
  for(i=0;i<9;i++)
    for(j=i+1;j<10;j++)
    {
	  if(number[j]<number[min])
	  {
	  	min = j;
	  	swap1 = number[i];
	  	number[i] = number[min];
	  	number[min] = swap1;
	  	strcpy(swap2,name[i]);
	  	strcpy(name[i],name[min]);
	  	strcpy(name[min],swap2);
	   } 
    }
  printf("\n排序后的结果为：\n");
  for(i=0;i<10;i++)
    printf("%4d%10s\n",number[i],name[i]);
}

void search_(int n)
{
  int top=0,bot=9,mid,loca=0,sign=1;
  if(number[0]>n||n>number[9])
    loca=-1;
  while((sign==1)&&(top<=bot))
  {
  	mid=(bot+top)/2;
  	if(n==number[mid])
  	{
  	  loca=mid;
  	  printf("%d号职工姓名为%s\n",n,name[loca]);
  	  sign=0;
	}
	else if(n<number[mid])
	  bot=mid-1;
	else
	  top=mid+1;
  }
  if(sign==0||loca==-1)
    printf("找不到该职工\n");
}

