#include <stdio.h>
int main()
{
	int a[5];
	int i;
	for(i=0;i<5;i++)
	  scanf("%d",&a[4-i]); 
	printf("a[5]={");
	for(i=0;i<5;i++)
	  printf("%d,",a[i]);
	printf("\b}");
	return 0;               
}
