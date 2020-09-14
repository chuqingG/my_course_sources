#include <stdio.h>
#include <math.h>
int main()
{
	int a,i,flag;
	float m; 
	printf("2\n3\n");
	for(a=4;a<=100;a++)
	{
		flag=0;
		m=sqrt(a);
	    for(i=2;i<=m;i++)
	      if(a%i==0) flag=1;
	    if(flag==0)  
	      printf("%d\n",a);
	}
	return 0;   
} 
