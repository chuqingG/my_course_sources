#include <stdio.h>
int main()
{ 
	char c;
	int letter=0,space=0,digit=0,other=0;
	printf("请输入一行字符：");
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
	printf("英文字母数为%d\n空格数为%d\n数字数为%d\n其他字符数为%d\n",letter,space,digit,other);
	return 0;
}
