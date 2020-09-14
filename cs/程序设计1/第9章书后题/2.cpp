#include <stdio.h>
int main()
{
	int year,month,day;
	int days(int a,int b,int c);
	printf("请依次输入年、月、日：\n");
	scanf("%d%d%d",&year,&month,&day);
	printf("该日在本年中是第%d天\n",days(year,month,day));
	return 0;
}

int days(int a, int b,int c)
{
	int num = 0;
	switch(b)
	{
		case 12: num += 30;
		case 11: num += 31;
		case 10: num += 30;
		case 9:  num += 31;
		case 8:  num += 31;
		case 7:  num += 30;
		case 6:  num += 31;
		case 5:  num += 30;
		case 4:  num += 31;
		case 3:  num += 28;
		case 2:  num += 31;
		case 1:  num += c;break;
	}
	if((a%4==0&&a%100!=0)||a%400==0) num += 1;
	return (num);
}
