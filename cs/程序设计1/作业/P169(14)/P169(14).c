#include<stdio.h>
void main()
{
    int i,j;
    char s1[10],s2[10];
    scanf("%s",s1);
    scanf("%s",s2);
    for(i=0;i<3;i++)
    {
        j=s1[i]-s2[i];
        if(j!=0)
            break;
    }
    printf("%d\n",j);
}
