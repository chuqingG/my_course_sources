#include<stdio.h>
void main()
{
    int i,j,n[101]={0};
    for(i=0;i<=100;i++)
        n[i]=i;
    n[1]=0;
    for(i=2;i<=100;i++)
    {
        if(n[i]!=0)
        {
            for(j=i+1;j<=100;j++)
            {
                if(j%i==0)
                    n[j]=0;
            }
        }
    }

    for(i=0;i<=100;i++)
        if(n[i]!=0)
            printf("%d\n",n[i]);

}
