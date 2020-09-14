#include <stdio.h>
#include <string.h>
char str1[50],str2[50];
int main()
{
	void connect(char str1[ ],char str2[ ]);
	printf("请输入两个字符串:\n");
	scanf("%s%s",str1,str2);
	connect(str1,str2);
	printf("%s",str1);
	return 0;
}
void connect(char str1[ ],char str2[ ])
{
	int i;
	for(i=0;i<strlen(str2);i++)
		str1[i+strlen(str1)]=str2[i];
}
//第一次错误：输入abcde fghij	输出abcdfg 
