#include <stdio.h>
int main()
{
	int i=0,a;
	char s1[100],s2[100];
	printf("�������һ���ַ�����");
	gets(s1);
	printf("������ڶ����ַ�����");
	gets(s2);
	while((s1[i]==s2[i])&&(s1[i]!='\0'))
	  i++;
	if(s1[i]=='\0'&&s2[i]=='\0')
	  a=0;
	else
	  a=s1[i]-s2[i];
	printf("%d",a);
	return 0;
	 
}
