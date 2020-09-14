#include <stdio.h>
int main()
{
	float g;
	char c;
	printf("请输入分数：");
	scanf("%f",&g);
	if(g>90)
	  c = 'A';
	else if(g>80)
	  c = 'B';
	else if(g>70)
	  c = 'C';
	else if(g>60)
	  c = 'D';
	else 
	  c = 'E';
	printf("成绩等级为%c",c);
	return 0;
	
 } 
