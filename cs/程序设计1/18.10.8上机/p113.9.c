#include <stdio.h>
#include <math.h>
int main()
{
	int z,x,a,b,c,d,e;
	printf("请输入一个不多于五位的正整数");
	scanf("%d",&z);
	if(z>9999)
      x = 5;
	else if(a>999)
	  x = 4; 
	else if(a>99)
	  x = 3;
	else if(a>9)
	  x = 2;
	else
	  x = 1;
	printf("位数为%d\n",x);
	a = z/10000;
	b = z/1000-10*a;
	c = z/100-100*a-10*b;
	d = z/10-1000*a-100*b-10*c;
	e = z-10000*a-1000*b-100*c-10*d;
	switch(x)
	{
		case 5:printf("反序数字为：%d%d%d%d%d",e,d,c,b,a);break;
		case 4:printf("反序数字为：%d%d%d%d",e,d,c,b);break;
		case 3:printf("反序数字为：%d%d%d%d",e,d,c);break;
		case 2:printf("反序数字为：%d%d",e,d);break;
		case 1:printf("反序数字为：%d",e);break;
	}
	return 0;
	 
 } 
