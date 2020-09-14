#include<stdio.h>
#include<math.h>
int main()
{
    float x,y,a=0;
    int h=0;
    scanf("%f%f",&x,&y);
    if(pow(fabs(x)-2,2)+pow(fabs(y)-2,2)<=1)
        h=10;
    printf("h=%dm",h);

    return 0;
}
