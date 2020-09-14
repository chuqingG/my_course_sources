#include <stdio.h>
#include <string.h>
int main()
{
	void sort(char s[][6]);
	int i;
	char str[10][6];
	printf("请输入十个字符串：\n");
	for(i=0;i<10;i++)
	  scanf("%s",str[i]);
	sort(str);
	printf("排序后的结果为：\n");
	for(i=0;i<10;i++)
	  printf("%s\n",str[i]);
	return 0;
} 

void sort(char s[10][6])
{
	int i,j;
	char *p,temp[10];
	p = temp;
	for(i=0;i<9;i++)
	  for(j=0;j<9;j++)
	    if(strcmp(s[j],s[j+1])>0)
	    {
	      strcpy(p,s[j]);
	      strcpy(s[j],s[j+1]);
	      strcpy(s[j+1],p);
		}
 } 
