#include<stdio.h>
void exchange(int a[3][3])
{
    int i,j,temp;
    for(i=0;i<3;i++)
    {
        for(j=i;j<3;j++)
        {
            temp=a[i][j];
            a[i][j]=a[j][i];
            a[j][i]=temp;
        }
    }
}

void main()
{
    int i,j;
    int a[3][3];
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            scanf("%d",&a[i][j]);

    exchange(a);
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
}
