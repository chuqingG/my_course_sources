#include<stdio.h>
int main()
{
    int n,j,i;

    for(i=1;i<=1000;i++)
    {
        n=0;
        for(j=1;j<i;j++)
            if(i%j==0)
                n=n+j;
        if(n==i)
        {
            printf("%d its factors are ",n);
            for(j=1;j<i;j++)
            {
                if(i%j==0)
                {
                    printf("%d",j);
                    if(j!=i/2)
                        printf(",");
                }
            }
            printf("\n");
        }
    }



    return 0;
}
