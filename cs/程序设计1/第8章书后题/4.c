#include <stdio.h>
#define N 9
#define M 3 
int a[N];
int main()
{
  int i;
  void convert_(int array[]);
  printf("���n��������ֵ��\n");
  for(i=0;i<N;i++)
    scanf("%d",&a[i]);
  printf("�������������Ϊ��\n");
  for(i=0;i<N;i++)
    printf("%4d",a[i]);
  printf("\n");
  convert_(a);
  printf("ת�������������Ϊ��\n");
  for(i=0;i<N;i++)
    printf("%4d",a[i]);
  printf("\n");
  return 0;  
} 


void convert_(int array[])
{
  int k;
  int *temp[M],*p[N];                             //�����ݴ��m����ַ 
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
