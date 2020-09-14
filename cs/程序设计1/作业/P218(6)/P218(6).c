#include<stdio.h>
#include<string.h>
void connect(char a[20],char b[20],char c[40])
{
    int i,j;
    for(i=0;a[i]!='\0';i++)
    {
        c[i]=a[i];
    }
    for(j=0;b[j]!='\0';j++,i++)
    {
        c[i]=b[j];
    }
    c[i]='\0';
}


void main()
{
    char a[20];
    char b[20];
    char c[40];
    gets(a);
    gets(b);
    connect(a,b,c);
    puts(c);
}
