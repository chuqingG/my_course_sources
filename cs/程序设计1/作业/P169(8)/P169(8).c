#include<stdio.h>
void main()
{
    int i,j,k,x,y,a[3][3];
    for(i=0;i<3;i++)
        for(j=0;j<3;j++)
            scanf("%d",&a[i][j]);


    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
            printf("%d\t",a[i][j]);
        printf("\n");
    }
    printf("\n");

    for(i=0;i<3;i++)
    {
        x=0;
        for(j=0;j<3;j++)
        {
            if(a[i][x]<a[i][j])
                x=j;
        }
        y=1;
        for(k=0;k<3;k++)
        {
            if(a[i][x]>a[k][x])
                y=0;
        }
        if(y==1)
            printf("a[%d][%d]=%d\n",i,x,a[i][x]);

    }

}
