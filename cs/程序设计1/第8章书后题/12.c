#include <stdio.h>
#include <string.h>
int main()
{
	void sort(char *s[]);
	int i;
	char *p[10],str[10][10];
	for(i=0;i<10;i++)
	  p[i]=str[i];
	printf("������ʮ���ַ�����\n");
	for(i=0;i<10;i++)
	  scanf("%s",p[i]);
	sort(p);
	printf("�����Ľ��Ϊ��\n");
	for(i=0;i<10;i++)
	  printf("%s\n",p[i]);
	return 0;
}

void sort(char *s[])
{
	int i,j;
	char *temp;
	for(i=0;i<9;i++)
      for(j=0;j<9;j++)
        if(strcmp(*(s+j),*(s+j+1))>0)
        {
    	  temp = *(s+j);
    	  *(s+j) = *(s+j+1);
    	  *(s+j+1) = temp;
		}
}
