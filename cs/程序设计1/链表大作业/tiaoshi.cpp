#include <stdio.h>
struct STU
{
	char id[10];
	char name[20];
};
int main()
{
	STU a;
	FILE *fp = NULL;
	fp = fopen("F:\\grade2.txt","r");
	if(fp = NULL)
	  printf("error\n");
	  fscanf(fp,"%s%s",a.id,a.name);
	  printf("%s%s",a.id,a.name);
	  return 0;
 } 
