#include <stdio.h>
int main()
{
	int i,j=0,n,x;
	printf("����������Ĵ�Сn="); 
	scanf("%d",&n);
	int a[n];
	printf("������Ϊ�����е����ݸ�ֵ��");
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	printf("������һ��������");
	scanf("%d",&x);
	for(i=0;a[i]<x;i++)
	  j++;
    for(i=n;i>j;i--)
      a[i]=a[i-1];
    a[j]=x;
    printf("�����������Ϊ��");
    for(i=0;i<n+1;i++)
      printf("%4d",a[i]);
    return 0;
      	
}
