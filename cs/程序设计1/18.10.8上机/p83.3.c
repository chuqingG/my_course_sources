#include <stdio.h>
#include <math.h>
int main()
{
	float m,d,p,r;
	printf("����������ܶÿ�»�����������\n");
	scanf("%f%f%f",&d,&p,&r);                                  
	m = log10(p/(p-d*r))/log10(1+r);                                //�������� 
    printf("��������Ϊ:%.1f\n",m);
	return 0;	 
 } 
