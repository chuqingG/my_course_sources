#include <stdio.h>
#include <math.h>
int main()
{
  int a[8][1000]={2,3,5,7},b[4]={1,3,7,9},num[8]={4};    //b���ڴ�ſɼ�β�� 
  int i,j,k,m,n,N,flag;
  scanf("%d",N);
  for(i=1;i<8;i++)                               //iΪ������λ�� 
  {
  	for(j=0;j<num[i];j++)                        //jΪ��ÿһ��ǰһλ��������ѭ���Ĳ��� 
  	{
  	  for(m=0;m<4;m++)
  	  {
		n=a[i-1][j]*10+b[m];                     //nΪ���ܵı�λ���������� 
  	    for(k=2;k<sqrt(n);k++)                   //k����n�ǲ������� 
	    {
		  if(n%k==0)
		  {
		    flag=1;
		    break;
		  }  
	    }
	    if(flag==0)
	    {
	  	  a[i][num[i]]=n;                        //numΪ��λ����������-1 
	  	  num[i]++;                           
	    }
	  }	
	}
  }
  printf("%dλ�ĳ��������У�\n",N); 
  for(i=0;i<num[N];i++)
    printf("%d  ",a[N-1][i]);
  return 0;
} 
