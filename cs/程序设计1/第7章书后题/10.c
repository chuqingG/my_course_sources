#include <stdio.h>
int m=0,n=0,p[10];                        //mΪ��������λ�ã�nΪ���� 
char str[200];
int main()
{
  int x,y,z;
  void longest_(char str[ ]);
  printf("������һ���ַ���\n");
  gets(str);
  longest_(str);
  printf("��ĵ���Ϊ��\n");
  for(z=0;p[z]!='\0';z++)
  {
    for(x=p[z]-n;x<p[z];x++)
      printf("%c",str[x]);
    printf("\n");
  }
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
  p[0]=m;                              //Ѱ���Ƿ���ڲ�����ĵ��� 
  for(i=m;str[i]!='\0';i++)
  { 
  	if(str[i]!=' ') j++;
  	else 
	{  
	  if(j=n)
  	  p[++k]=i;
  	  j=0; 
	}  
  } 
  p[k]='\0';
}
