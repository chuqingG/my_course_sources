#include <stdio.h>
int i,j;
float grade[11][6]={0};
int main()
{
  void student_average();
  void class_average();
  void highest_();
  void variance_();
  printf("请输入学生的成绩：\n");        //录入成绩 
  for(i=0;i<10;i++)
    for(j=0;j<5;j++)
      scanf("%f",&grade[i][j]);
  printf("          class1  class2  class3  class4  class5\n");
  for(i=0;i<10;i++)
  {
  	printf("student%d",i);
  	for(j=0;j<5;j++)
  	  printf("%8.2f",grade[i][j]);
  	printf("\n");
  }
  student_average();
  class_average();
  highest_();
  variance_(); 
  return 0;   
}


void student_average()
{
  for(i=0;i<10;i++)
  {
  	for(j=0;j<5;j++)
  	  grade[i][5]+=grade[i][j];
  	  grade[i][5]/=5;
  	printf("第%d个学生的平均分为%.2f分\n",i+1,grade[i][5]);
  }
}


void class_average()
{
  for(j=0;j<5;j++)
  {
  	for(i=0;i<10;i++)
  	  grade[10][j]+=grade[i][j];
  	grade[10][j]/=10;
  	printf("第%d门课的平均分为%.2f分\n",j+1,grade[10][j]);
  }
}


void highest_()
{
  int highest=0,i0=0,j0=0;
  for(i=0;i<10;i++)
    for(j=0;j<5;j++)
      if(grade[i][j]>highest)
      {
      	highest=grade[i][j];
      	i0=i;j0=j;
	  }
  printf("最高分是第%d名学生的第%d门课\n",i0+1,j0+1);	
}


void variance_()
{
  float sum_average=0,variance=0;
  for(i=0;i<10;i++)
  {
    variance+=grade[i][5]*grade[i][5]/10;
    sum_average+=grade[i][5];
  }
  variance-=sum_average*sum_average/100;
  printf("平均分方差为：%.2f分",variance);
}
