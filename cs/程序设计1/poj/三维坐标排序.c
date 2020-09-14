#include <stdio.h>
#include <math.h>
int main()
{
	int n,i,j,k=0;
	int x[100],y[100],z[100],io[4950],jo[4950];
	float d[100][100],a[4950]={0};
	scanf("%d",&n);
	for(i=0;i<n;i++)
      scanf("%d%d%d",&x[i],&y[i],&z[i]);
    for(i=0;i<n;i++)
    {
      for(j=0;j<n;j++)
      {
        if(i>=j) continue;
        else 
		{
		  d[i][j]=sqrt((x[i]-x[j])*(x[i]-x[j])+(y[i]-y[j])*(y[i]-y[j])+(z[i]-z[j])*(z[i]-z[j])) ;
		  k++;
	    }
      }
    }
	for(k=0;k<n*(n-1)/2;k++)
	{
	  for(i=0;i<n;i++)
	  {
	    for(j=0;j<n;j++)
	    {
	      if(i>=j) continue;
	      if(d[i][j]>a[k])
	      {
	      	io[k]=i,jo[k]=j;
	      	a[k]=d[i][j];
		  }
		}
	  }
	  d[io[k]][jo[k]]=0;
	}
	for(k=0;k<n*(n-1)/2;k++)  
	  printf("(%d,%d,%d)-(%d,%d,%d)=%.2f\n",x[io[k]],y[io[k]],z[io[k]],x[jo[k]],y[jo[k]],z[jo[k]],a[k]);
	return 0;
     	
}
