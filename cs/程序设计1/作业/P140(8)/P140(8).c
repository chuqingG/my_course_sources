#include<stdio.h>
#include<math.h>
int main()
{
    int i,a1,a2,a3;
    for(i=100;i<1000;i++)
    {
        a1=i%10;
        a2=(i/10)%10;
        a3=i/100;
        if(i==pow(a1,3)+pow(a2,3)+pow(a3,3))
            printf("%d\n",i);

    }


    return 0;
}
