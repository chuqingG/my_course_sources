#include <stdio.h>
int main()
{
	float g;
	char c;
	printf("�����������");
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
	printf("�ɼ��ȼ�Ϊ%c",c);
	return 0;
	
 } 
