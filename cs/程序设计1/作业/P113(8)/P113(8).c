#include<stdio.h>

int main()
{
    int i;
    scanf("%d",&i);
    if(i>=90)
        i='A';
    else if(i>=80)
        i='B';
    else if(i>=70)
        i='C';
    else if(i>=60)
        i='D';
    else
        i='E';

    printf("%c",i);

    return 0;
}
