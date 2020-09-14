#include <stdio.h>
int main ()
{
	int i=0,j=0,k;
	char a[100],b[100];
	gets(a);
	gets(b);
	while(a[i]!='\0')
	{
	  i++;
	  k++;
	}  
	while(b[j]!='\0')
	  a[i++]=b[j++];
	a[i]='\0';
	printf("连接之后的字符串为：%s",a);
	return 0;
}
