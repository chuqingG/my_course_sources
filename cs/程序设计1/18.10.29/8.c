//没有解决数值相同的问题 
#include <stdio.h>
int main()
{
	int x,y,i,j,k,m,flag1=0,flag2=0;
	printf("请依次输入行数、列数：");
	scanf("%d %d",&x,&y);
	int a[x][y];
	printf("请为数组赋值\n");
	for(i=0;i<x;i++)
	  for(j=0;j<y;j++)
	    scanf("%d",&a[i][j]);                        //到这行之前是把数组的值都赋好 
	for(i=0;i<x;i++)
	{
		for(j=0,k=0;j<y;j++)
		  if(a[i][j]>a[i][k]) k=j;                   //找每行中的最大一个并且记住它是哪一个 
		for(m=0;m<y;m++)                             //验证这个是不是所在列最小的 
		{                                            //因为i正在外层循环不能改就再来一个字母m进行该列循环 
		  if(m==i) continue;
		  else if(a[m][k]<a[i][k]) flag1=1;          //flag1标记变量判断该列中是否存在比该数更小的 
		}
		if(flag1==0)
		{
		  printf("第%d行第%d列是一个鞍点，值为%d\n",i+1,k+1,a[i][k]);      //输出符合条件的鞍点 
		  flag2=1;                                   //flag2标记变量判断是否有鞍点输出 
		}
	}
	if(flag2==0)
	  printf("没有鞍点");
	return 0;
}
