#include<stdio.h>
#include<string.h>
#define N 5
f_scan(char name[N][10],int number[N])
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("name[%d]=",i);
        gets(name[i]);
        printf("number[%d]=",i);
        scanf("%d",&number[i]);
        while(getchar()!='\n');
    }
}

f_sort(char name[N][10],int number[N])
{
    int i,j,temp;
    char tempname[10];
    for(i=0;i<N;i++)
    {
        for(j=0;j<N-i-1;j++)
        {
            if(number[j]>number[j+1])
            {
                temp=number[j];
                number[j]=number[j+1];
                number[j+1]=temp;
                strcpy(tempname,name[j]);
                strcpy(name[j],name[j+1]);
                strcpy(name[j+1],tempname);
            }
        }
    }
}

void f_search(char name[N][10],int number[N],int number_,char name_[10])
{
    int i,min=0,max=N-1;
    for(i=(N-1)/2;;)
    {
        if(number[i]==number_)
        {
            strcpy(name_,name[i]);
            break;
        }
        else if(number[i]>number_)
        {
            max=i-1;
            i=(max+min)/2;
        }
        else
        {
            min=i+1;
            i=(min+max)/2;
        }

    }

}



void main()
{
    char name[N][10];
    int number[N];
    int i,number_;
    char name_[10];
    f_scan(name,number);
    f_sort(name,number);
    for(i=0;i<N;i++)
        printf("%s\t%d\n",name[i],number[i]);

    scanf("%d",&number_);
    f_search(name,number,number_,name_);
    printf("%s",name_);
}
