#include <stdio.h>
int m=0,n=0,p[10];                        //m为单词所在位置，n为长度 
char str[200];
int main()
{
  int x,y,z;
  void longest_(char str[ ]);
  printf("请输入一行字符：\n");
  gets(str);
  longest_(str);
  printf("最长的单词为：\n");
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
  p[0]=m;                              //寻找是否存在并列最长的单词 
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
