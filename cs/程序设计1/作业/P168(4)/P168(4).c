#include<stdio.h>
void main()
{
    int i,b,a[5]={12,25,31,44};
    scanf("%d",&a[4]);
    for(i=4;i>0;i--)
    {
        if(a[i]<a[i-1])
        {
            b=a[i];
            a[i]=a[i-1];
            a[i-1]=b;
        }
        else
            break;
    }
    for(i=0;i<5;i++)
        printf("%d ",a[i]);

}
