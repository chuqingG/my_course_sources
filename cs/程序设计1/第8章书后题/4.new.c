#include <stdio.h>
#define N 9
#define M 3 
int main()
{
  int i,a[N];
  void convert_(int array[],int m,int n);
  printf("���n��������ֵ��\n");
  for(i=0;i<N;i++)
    scanf("%d",&a[i]);
  printf("�������������Ϊ��\n");
  for(i=0;i<N;i++)
    printf("%4d",a[i]);
  printf("\n");
  convert_(a,M,N);
  printf("ת�������������Ϊ��\n");
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
