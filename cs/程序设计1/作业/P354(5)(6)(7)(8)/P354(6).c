#include<stdio.h>
#include<stdlib.h>
struct student
{
    int num;
    char name[10];
    float score[3];
    float average;
}s[5],temp;

void main()
{
    FILE *fp;
    int i,j;

    if((fp=fopen("stud","rt"))==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
    fread(s,sizeof(struct student),5,fp);
    fclose(fp);
    printf("num\tname\tscore[1]\tscore[2]\tscore[3]\taverage\n");
    for(i=0;i<5;i++)
        printf("%d\t%s\t%.1f\t\t%.1f\t\t%.1f\t\t%.1f\n",s[i].num,s[i].name,s[i].score[0],s[i].score[1],s[i].score[2],s[i].average);



    if((fp=fopen("stud","rt"))==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
    fread(s,sizeof(struct student),5,fp);
    fclose(fp);
    for(i=0;i<4;i++)
    {
        for(j=0;j<4-i;j++)
        {
            if(s[j].average<s[j+1].average)
            {
                temp=s[j];
                s[j]=s[j+1];
                s[j+1]=temp;
            }
        }
    }
    if((fp=fopen("stu_sort","wt"))==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
    fwrite(s,sizeof(struct student),5,fp);
    fclose(fp);



    if((fp=fopen("stu_sort","rt"))==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
    fread(s,sizeof(struct student),5,fp);
    fclose(fp);
    printf("num\tname\tscore[1]\tscore[2]\tscore[3]\taverage\n");
    for(i=0;i<5;i++)
        printf("%d\t%s\t%.1f\t\t%.1f\t\t%.1f\t\t%.1f\n",s[i].num,s[i].name,s[i].score[0],s[i].score[1],s[i].score[2],s[i].average);
}
