#include <stdio.h>
int main()
{ 
	char c;
	int letter=0,space=0,digit=0,other=0;
	printf("������һ���ַ���");
	for(;(c=getchar())!='\n';) 
		{if(c==32)
			space++;
		 else if((c<=90&&c>=65)||(c>=97&&c<=122))
		 	letter++;
		 else if(c>=48&&c<=57)
		 	digit++;
		 else
		 	other++;
		}
	printf("Ӣ����ĸ��Ϊ%d\n�ո���Ϊ%d\n������Ϊ%d\n�����ַ���Ϊ%d\n",letter,space,digit,other);
	return 0;
}
