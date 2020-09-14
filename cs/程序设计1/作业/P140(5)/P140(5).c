#include<stdio.h>
#include<math.h>
int main()
{
    int n,i,j;
    double a,b=0,s=0;

    scanf("%d",&n);
    scanf("%lf",&a);
    for(i=1;i<=n;i++)
    {
        for(j=0;j<i;j++)
        {
            b=b+a*pow(10,j);
        }
        s=s+b;
        b=0;
    }
    printf("s=%.f\n",s);

    return 0;
}
