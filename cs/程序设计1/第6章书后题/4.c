#include <stdio.h>
int main()
{
	int i,j=0,n,x;
	printf("请输入数组的大小n="); 
	scanf("%d",&n);
	int a[n];
	printf("请依次为数组中的数据赋值：");
	for(i=0;i<n;i++)
	  scanf("%d",&a[i]);
	printf("请输入一个整数：");
	scanf("%d",&x);
	for(i=0;a[i]<x;i++)
	  j++;
    for(i=n;i>j;i--)
      a[i]=a[i-1];
    a[j]=x;
    printf("新数组的排序为：");
    for(i=0;i<n+1;i++)
      printf("%4d",a[i]);
    return 0;
      	
}
