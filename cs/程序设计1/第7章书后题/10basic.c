#include <stdio.h>
int m=0,n=0;                        //m为单词所在位置，n为长度 
char str[200];
int main()
{
  int x,y;
  void longest_(char str[ ]);
  printf("请输入一行字符：\n");
  gets(str);
  longest_(str);
  printf("最长的单词为：\n");
  for(x=m-n;x<m;x++)
    printf("%c",str[x]);
  return 0; 
}

 
void longest_(char str[ ])
{
  int i=0,j=0,k=0;
  for(;str[i]!='\0';i++)                //寻找最长的单词 
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
