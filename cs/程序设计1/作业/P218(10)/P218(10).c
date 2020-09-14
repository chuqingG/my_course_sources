#include<stdio.h>
void longest(char a[40],char b[40])
{
    int i,j,n,m=0,l=0;
    for(i=0;a[i]!='\0';i++)
    {
        if(a[i]>='A'&&a[i]<='Z'||a[i]>='a'&&a[i]<='z')
            l++;
        else
        {
            if(m<l)
            {
                m=l;
                n=i;
            }
            l=0;
        }
    }
    if(m<l)
    {
        m=l;
        n=i;
    }
    for(i=n-m,j=0;i<n;i++,j++)
    {
        b[j]=a[i];
    }
    b[j]='\0';
}


void main()
{
    char a[40],b[40];
    gets(a);
    longest(a,b);
    puts(b);
}
