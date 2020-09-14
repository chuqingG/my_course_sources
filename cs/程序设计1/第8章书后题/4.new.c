#include <stdio.h>
#define N 9
#define M 3 
int main()
{
  int i,a[N];
  void convert_(int array[],int m,int n);
  printf("请给n个整数赋值：\n");
  for(i=0;i<N;i++)
    scanf("%d",&a[i]);
  printf("输入的整数依次为：\n");
  for(i=0;i<N;i++)
    printf("%4d",a[i]);
  printf("\n");
  convert_(a,M,N);
  printf("转换后的整数依次为：\n");
  for(i=0;i<N;i++)
    printf("%4d",a[i]);
  printf("\n");
  return 0;  
} 


void convert_(int array[],int m,int n)
{
  int *p,temp;
  temp=*(array+n-1);
  for(p=array+n-1;p>array;p--)
  	*p=*(p-1);
  *array=temp;
  m--;
  if(m>0)
    convert_(array,m,n);
} 
