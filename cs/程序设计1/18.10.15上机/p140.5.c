#include <stdio.h>
#include <math.h>
int main()
{
	int a,i=1,sum=0,n,b;
	printf("«Î ‰»Îa£¨n\n");
	scanf("%d%d",&a,&n);
	while(i<n+1)
	{
		b = pow(10,i)-1;
		sum += b*2/9;
		i++; 
	}
	printf("sum=%d\n",sum);
	return 0; 
 } 
