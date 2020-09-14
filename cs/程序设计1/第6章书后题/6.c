#include <stdio.h>
#include <math.h>
int main()
{
	int a[10][10]={1};
	int i,j,k;
	for(i=0;i<10;i++)
	{  
	  for(j=0;j<=i;j++)
	  {
	    if(j==0||j==i)
	      a[i][j]=1;
	    else
	      a[i][j]=a[i-1][j]+a[i-1][j-1];
	  }
	  for(k=0;k<=i;k++)
	    printf("%6d",a[i][k]);
	  printf("\n");
	}
	return 0;	  	  
}
