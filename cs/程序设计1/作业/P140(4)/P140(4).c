#include<stdio.h>
int main()
{
    int a,a1=0,a2=0,a3=0,a4=0;

    while((a=getchar())!='\n')
    {
        if((a>='A'&&a<='Z')||(a>='a'&&a<='z'))
            a1++;
        else if(a==' ')
            a2++;
        else if(a>='0'&&a<='9')
            a3++;
        else
            a4++;
    }

    printf("英文字母：%d\n空格：%d\n数字：%d\n其他字符：%d",a1,a2,a3,a4);

    return 0;
}
