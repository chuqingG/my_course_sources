#include <stdio.h>
#include <math.h>
int main()
{
	float m,d,p,r;
	printf("请输入贷款总额，每月还款额，贷款利率\n");
	scanf("%f%f%f",&d,&p,&r);                                  
	m = log10(p/(p-d*r))/log10(1+r);                                //计算月数 
    printf("还清月数为:%.1f\n",m);
	return 0;	 
 } 
