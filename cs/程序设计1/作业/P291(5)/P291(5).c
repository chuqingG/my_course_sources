#include<stdio.h>
#include<stdlib.h>
#define NULL 0
void main()
{
    int n,i,j=0,k,*s=NULL;
    printf("n=");
    scanf("%d",&n);
    s=(int *)malloc(n*sizeof(int));
    if(s==NULL)
        exit(0);
    for(i=0;i<n;i++)
        *(s+i)=1;
    k=n;
    for(i=0;i<n;i++)
    {
        if(*(s+i)!=0)
            j++;
        if(j==3)
        {
            *(s+i)=0;
            j=0;
            k--;
            if(k==1)
                break;
        }
        if(i==n-1)
            i=-1;
    }
    for(i=0;i<n;i++)
        if(*(s+i)!=0)
            printf("%d",i+1);

    free(s);
}
