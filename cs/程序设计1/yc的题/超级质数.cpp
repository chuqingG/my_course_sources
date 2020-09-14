#include <stdio.h>
#include <math.h>
int main()
{
  int a[8][1000]={2,3,5,7},b[4]={1,3,7,9},num[8]={4};    //b用于存放可加尾数 
  int i,j,k,m,n,N,flag;
  scanf("%d",N);
  for(i=1;i<8;i++)                               //i为质数的位数 
  {
  	for(j=0;j<num[i];j++)                        //j为对每一个前一位成立进行循环的参量 
  	{
  	  for(m=0;m<4;m++)
  	  {
		n=a[i-1][j]*10+b[m];                     //n为可能的本位数超级质数 
  	    for(k=2;k<sqrt(n);k++)                   //k检验n是不是质数 
	    {
		  if(n%k==0)
		  {
		    flag=1;
		    break;
		  }  
	    }
	    if(flag==0)
	    {
	  	  a[i][num[i]]=n;                        //num为该位数质数个数-1 
	  	  num[i]++;                           
	    }
	  }	
	}
  }
  printf("%d位的超级质数有：\n",N); 
  for(i=0;i<num[N];i++)
    printf("%d  ",a[N-1][i]);
  return 0;
} 
