#include<stdio.h>
#include<math.h>
int main()
{
    int i,j,a0,a;
    int b[6]={0};
    scanf("%d",&a0);
    a=a0;
    for(i=1;i<6;i++)
    {
        if(a/pow(10,i)<1)
            break;
    }
    printf("%d\n\n",i);


    a=a0;
    for(j=1;j<i+1;j++)
    {
        b[j]=a%10;
        a=a/10;
        printf("%d\n",b[j]);
    }

    printf("\n");

    for(j=1;j<i+1;j++)
    {
        printf("%d",b[j]);
    }


    return 0;
}
