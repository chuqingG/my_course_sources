#include<stdio.h>
#include<string.h>
#define N 4
void sort(char *str[N])
{
    char *temp=str[0];
    int i,j,k;
    for(i=0;i<N-1;i++)
    {
        k=i;
        for(j=i+1;j<N;j++)
            if(strcmp(str[k],str[j])>0)
                k=j;
        temp=str[k];
        str[k]=str[i];
        str[i]=temp;
    }
}

void main()
{
    char s[N][10],*str[N];
    int i;
    for(i=0;i<N;i++)
    {
        str[i]=s[i];
    }
    printf("input:\n");
    for(i=0;i<N;i++)
    {
        scanf("%s",str[i]);
    }
    sort(str);
    printf("output:\n");
    for(i=0;i<N;i++)
        printf("%s ",str[i]);
}
