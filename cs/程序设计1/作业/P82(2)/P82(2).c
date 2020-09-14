#include<stdio.h>
#include<math.h>
int main()
{
    double plan[6]={0};
    int i;
    plan[1]=1000*(1+5*0.0585);
    plan[2]=1000*(1+2*0.0468)*(1+3*0.054);
    plan[3]=1000*(1+3*0.054)*(1+2*0.0468);
    plan[4]=1000*pow(1+0.0414,5);
    plan[5]=1000*pow(1+0.0072/4,4*5);
    for (i=1;i<6;i++)
    {
        printf("plan[%d]=%f\n",i,plan[i]);
    }


    return 0;
}
