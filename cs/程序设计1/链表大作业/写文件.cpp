//将成绩表写入文件 
#include <stdio.h>
#include <stdlib.h>
//定义一个结构体存放一个学生的所有数据
struct student  
{
	char id[4];         
	char name[10];     
	int score[3];      //依次用于存放语文、数学、英语成绩
	float ave;         //平均分
}stu[10];
 
int main()
{
	int i; 
	//将成绩表赋给数组
	printf("请依次输入学号、姓名、语文、数学、英语成绩\n");
	for(i = 0;i < 8;i++)
	  scanf("%s,%s,%d,%d,%d",stu[i].id,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
	//创建一个名为grade的txt文件存放成绩表
	FILE*fp;
	fp = fopen("grade.txt","w");        //写的方式打开文件 
	if(fp = NULL)                       //打开失败 
	{
	  printf("error");
	  exit(0);
	}
	for(i = 0;i < 8;i++)               //将成绩表写入文件 
	  fprintf(fp,"%s,%s,%d,%d,%d\n",stu[i].id,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
	fclose(fp);                        //关闭文件 
	return 0;   
}
