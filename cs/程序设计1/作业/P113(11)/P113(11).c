#include<stdio.h>
int main()
{
    int a[4]={0};
    int i,j,b;
    for(i=0;i<4;i++)
    {
        scanf("%d",&a[i]);
    }

    for(j=0;j<4;j++)
    {
        for(i=0;i<4;i++)
        {
            if(a[i]>a[i+1])
            {
                b=a[i];
                a[i]=a[i+1];
                a[i+1]=b;
            }
        }
    }

    for(i=0;i<4;i++)
    {
        printf("%d\n",a[i]);
    }

    return 0;
}
