#include <stdio.h>
int m=0,n=0;                        //mΪ��������λ�ã�nΪ���� 
char str[200];
int main()
{
  int x,y;
  void longest_(char str[ ]);
  printf("������һ���ַ���\n");
  gets(str);
  longest_(str);
  printf("��ĵ���Ϊ��\n");
  for(x=m-n;x<m;x++)
    printf("%c",str[x]);
  return 0; 
}

 
void longest_(char str[ ])
{
  int i=0,j=0,k=0;
  for(;str[i]!='\0';i++)                //Ѱ����ĵ��� 
  {
	if(str[i]!=' ')	j++;
	else
	{
	  if(j>n)
      {
	    n=j;m=i;
	  }
	  j=0;
	}
  }
}
