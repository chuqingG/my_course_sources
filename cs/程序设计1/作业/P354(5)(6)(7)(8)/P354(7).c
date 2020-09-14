#include<stdio.h>
#include<stdlib.h>
struct student
{
    int num;
    char name[10];
    float score[3];
    float average;
}s[6],s_new;

void main()
{
    FILE *fp;
    int i,j;

    //读取
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

    //输入
    printf("new student:\n");
    printf("num:");
    scanf("%d",&s_new.num);
    printf("name:");
    scanf("%s",s_new.name);
    s_new.average=0;
    for(i=0;i<3;i++)
    {
        printf("score[%d]=",i+1);
        scanf("%f",&s_new.score[i]);
        s_new.average+=s_new.score[i];
    }
    s_new.average/=3;

    //插入
    for(i=0;i<5;i++)
    {
        if(s_new.average>s[i].average)
        {
            for(j=5;j>i;j--)
                s[j]=s[j-1];
            s[i]=s_new;
            break;
        }
    }

    //写入
    if((fp=fopen("stu_new","wt"))==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
    fwrite(s,sizeof(struct student),6,fp);
    fclose(fp);

    //打印
    if((fp=fopen("stu_new","rt"))==NULL)
    {
        printf("cannot open file\n");
        exit(0);
    }
    fread(s,sizeof(struct student),6,fp);
    fclose(fp);
    printf("num\tname\tscore[1]\tscore[2]\tscore[3]\taverage\n");
    for(i=0;i<6;i++)
        printf("%d\t%s\t%.1f\t\t%.1f\t\t%.1f\t\t%.1f\n",s[i].num,s[i].name,s[i].score[0],s[i].score[1],s[i].score[2],s[i].average);
}
