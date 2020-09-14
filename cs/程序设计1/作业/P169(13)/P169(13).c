#include<stdio.h>
void main()
{
    char a[10],b[10],c[20];
    int i,j;
    gets(a);
    gets(b);
    for(i=0;i<10;i++)
    {
        if(a[i]!='\0')
            c[i]=a[i];
        else
            break;
    }
    for(j=0;j<10;j++,i++)
    {
        if(b[j]!='\0')
            c[i]=b[j];
        else
            break;
    }
    c[i]='\0';
    puts(c);

}
