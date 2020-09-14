#include<stdio.h>
#include<stdlib.h>
struct student
{
    int num;
    char name[10];
    float score[3];
    float average;
}s[5];

void main()
{
    FILE *fp;
    int i,j;
    for(i=0;i<5;i++)
    {
        printf("student%d:\n",i+1);
        printf("num:");
        scanf("%d",&s[i].num);
        printf("name:");
        scanf("%s",s[i].name);
        s[i].average=0;
        for(j=0;j<3;j++)
        {
            printf("score[%d]=",j+1);
            scanf("%f",&s[i].score[j]);
            s[i].average+=s[i].score[j];
        }
        s[i].average/=3;
    }
    if((fp=fopen("stud","wt"))==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
    fwrite(s,sizeof(struct student),5,fp);
    fclose(fp);



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
}
