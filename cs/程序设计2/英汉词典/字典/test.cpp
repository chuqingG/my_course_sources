#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	char s[10] ;
	FILE *fp;
    fp = fopen("grade2.txt","rt");
    if(fp == NULL)                   //´ò¿ªÊ§°Ü 
    {
    	printf("error");
  	    exit(0);
    } 
    fscanf(fp, "\n%[^a]",s);
    printf("%s",s);
	return 0;
}
