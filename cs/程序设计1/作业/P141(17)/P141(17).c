#include<stdio.h>
int main()
{
    int a,b,c,x,y,z;
    a=1;
    b=2;
    c=3;
    for(x=1;x<4;x++)
        if(x!=a&&x!=c)
            for(y=1;y<4;y++)
                if(y!=x)
                    for(z=1;z<4;z++)
                        if(z!=x&&z!=y&&z!=c)
                            printf("x vs %c\ny vs %c\nz vs %c",'a'+x-1,'a'+y-1,'a'+z-1);

    return 0;
}
