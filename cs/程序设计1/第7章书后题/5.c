#include <stdio.h>
#include <string.h>
char a[50];
int main()
{
	int i;
	void convert(char a[50]);
	printf("������һ���ַ���\n");
	gets(a);
	convert(a);
	printf("ת������ַ���Ϊ��\n%s",a);
	return 0;
}
void convert(char a[50])
{
	int i;
	char t;
	for(i=0;i<(strlen(a)/2);i++)
	{
		t=a[i];
		a[i]=a[strlen(a)-i-1];
		a[strlen(a)-i-1]=t;
	}
	a[strlen(a)]='\0';
}
