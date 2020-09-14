#include <stdio.h>
#include <math.h>
int main()
{
	float a,d,e,A,B,C,D,E;
	printf("请输入本金："); 
	scanf("%f",&a);
	A = a*(1+5*0.0585);                                //计算存法一 
	B = a*(1+2*0.0468)*(1+3*0.0054);                   //计算寸法二 
	C = a*(1+3*0.0054)*(1+2*0.0468);                   //计算存法三 
	d = pow(1+0.0414,5);                               //计算存法四  
	D = a*d;          
	e = pow(1+0.0414/4,20);                            //计算存法五 
	E = a*e;
	printf("存法一获得本息和为%.2f元\n",A);                //还可以考虑%.2f 
	printf("存法二获得本息和为%.2f元\n",B);
	printf("存法三获得本息和为%.2f元\n",C);
	printf("存法四获得本息和为%.2f元\n",D);
	printf("存法五获得本息和为%.2f元\n",E);
	return 0;
 } 
