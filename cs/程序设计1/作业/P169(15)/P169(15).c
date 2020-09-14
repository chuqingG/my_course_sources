//'\0'
#include<stdio.h>
void main()
{
    char s1[20]={"HelloWorld!"},s2[20]={"Banana"};
    int i;
    for(i=0;i<20;i++)
    {
        if(s2[i]!='\0')
            s1[i]=s2[i];
        else
            break;
    }
    s1[i]='\0';
    puts(s1);


}
