#include<stdio.h>
#include<stdlib.h>
void magic(int *num,int n,int m)
{
    int *temp,i;
    temp=/*(int *)*/malloc(m*sizeof(int));
    if(temp==NULL)
        exit(0);
    for(i=0;i<m;i++)
        *(temp+i)=*(num+n-m+i);
    for(i=0;i<n-m;i++)
        *(num+n-1-i)=*(num+n-m-1-i);
    for(i=0;i<m;i++)
        *(num+i)=*(temp+i);
    free(temp);
}

void main()
{
    int *num=NULL,n,m,i;
    printf("n=");
    scanf("%d",&n);
    printf("m=");
    scanf("%d",&m);
    num=/*(int *)*/malloc(n*sizeof(int));
    if(num==NULL)
        exit(0);
    printf("input the numbers:\n");
    for(i=0;i<n;i++)
        scanf("%d",num+i);
    magic(num,n,m);
    for(i=0;i<n;i++)
        printf("%d ",*(num+i));
    free(num);
}
