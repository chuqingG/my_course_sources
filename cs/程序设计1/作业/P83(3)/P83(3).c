#include<stdio.h>
#include<math.h>
int main()
{
    int d=300000,p=6000;
    float r=0.01,m;
    m=log(p/(p-d*r))/log(1+r);
    printf("m=%.1f",m);

    return 0;
}
