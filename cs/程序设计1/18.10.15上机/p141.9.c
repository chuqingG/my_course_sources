#include <stdio.h>
int main()
{
	int a=1,i,sum;
	for(;a<=1000;a++)
	{
		sum=0; 
	    for(i=1;i<a;i++)
		  {
	        if((a%i)==0)
			  sum=sum+i;
		  }
	    if(a==sum)
	      {
	    	printf("%d its factors are ",a);
	    	  for(i=1;i<a;i++)
	            if((a%i)==0)
			      {
		 	        sum=sum+i;
			        printf("%d ",i);
			      }	 
			printf("\n");       
	      }
	}
	return 0; 
}
