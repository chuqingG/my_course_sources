#include<stdio.h>
struct Day
{
    int year,month,day;
};
int days(struct Day date)
{
    int i,n=0;
    if(date.year%4==0&&date.year%100!=0||date.year%400==0)
    {
        for(i=1;i<date.month;i++)
        {
            switch(i)
            {
                case 1:n+=31;break;
                case 2:n+=29;break;
                case 3:n+=31;break;
                case 4:n+=30;break;
                case 5:n+=31;break;
                case 6:n+=30;break;
                case 7:n+=31;break;
                case 8:n+=31;break;
                case 9:n+=30;break;
                case 10:n+=31;break;
                case 11:n+=30;break;
            }
        }
        n+=date.day;
    }
    else
    {
        for(i=1;i<date.month;i++)
        {
            switch(i)
            {
                case 1:n+=31;break;
                case 2:n+=28;break;
                case 3:n+=31;break;
                case 4:n+=30;break;
                case 5:n+=31;break;
                case 6:n+=30;break;
                case 7:n+=31;break;
                case 8:n+=31;break;
                case 9:n+=30;break;
                case 10:n+=31;break;
                case 11:n+=30;break;
            }
        }
        n+=date.day;
    }

    return(n);
}

void main()
{
    int n;
    struct Day date;
    printf("year:");
    scanf("%d",&date.year);
    printf("month:");
    scanf("%d",&date.month);
    printf("day:");
    scanf("%d",&date.day);
    n=days(date);
    printf("n=%d",n);
}
