#include <stdio.h>
#define N 9
#define M 3 
int a[N];
int main()
{
  int i;
  void convert_(int array[]);
  printf("请给n个整数赋值：\n");
  for(i=0;i<N;i++)
    scanf("%d",&a[i]);
  printf("输入的整数依次为：\n");
  for(i=0;i<N;i++)
    printf("%4d",a[i]);
  printf("\n");
  convert_(a);
  printf("转换后的整数依次为：\n");
  for(i=0;i<N;i++)
    printf("%4d",a[i]);
  printf("\n");
  return 0;  
} 


void convert_(int array[])
{
  int k;
  int *temp[M],*p[N];                             //用于暂存后m个地址 
  for(k=0;k<N;k++)
    p[k]=&array[k]; 
  for(k=M-1;k>=0;k--)
  {
    if(k>=N-M)
      temp[k-N+M]=p[k];
    else
      p[k+M]=p[k];
  }
  for(k=0;k<M;k++)
    p[k]=temp[k];	   
} 
