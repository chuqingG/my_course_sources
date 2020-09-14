#include <stdio.h>
#include <math.h>
int main()
{
	int a=100,a1,a2,a3;
	while(a<999)
	{
		a1=a/100;
		a2=a/10-10*a1;
		a3=a-a1*100-a2*10;
		a1=pow(a1,3);
		a2=pow(a2,3);
		a3=pow(a3,3);
		if(a==a3+a2+a1)
			printf("%d\n",a);
		a++;
	}
	return 0;
}
