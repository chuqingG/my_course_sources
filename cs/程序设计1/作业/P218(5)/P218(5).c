#include<stdio.h>
#include<string.h>
void reverse(char a[20])
{
    char b[20];
    int i,l;
    strcpy(b,a);
    l=strlen(a);
    for(i=0;i<l;i++)
    {
        a[l-i-1]=b[i];
    }
}


void main()
{
    char a[20];
    gets(a);
    reverse(a);
    puts(a);
}
