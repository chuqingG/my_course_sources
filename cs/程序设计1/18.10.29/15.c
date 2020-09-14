#include <stdio.h>
#include <string.h>
int main( )
{
	char s1[100],s2[100];
	int i;
	printf("ÇëÊäÈë×Ö·û´®2£º");
	scanf("%s",&s2);
	for(i=0;i<strlen(s2);i++)
	  s1[i]=s2[i];
	printf("×Ö·û´®1:%s\n",s1);
	return 0;
}
