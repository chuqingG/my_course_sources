//���ɼ���д���ļ� 
#include <stdio.h>
#include <stdlib.h>
//����һ���ṹ����һ��ѧ������������
struct student  
{
	char id[4];         
	char name[10];     
	int score[3];      //�������ڴ�����ġ���ѧ��Ӣ��ɼ�
	float ave;         //ƽ����
}stu[10];
 
int main()
{
	int i; 
	//���ɼ���������
	printf("����������ѧ�š����������ġ���ѧ��Ӣ��ɼ�\n");
	for(i = 0;i < 8;i++)
	  scanf("%s,%s,%d,%d,%d",stu[i].id,stu[i].name,&stu[i].score[0],&stu[i].score[1],&stu[i].score[2]);
	//����һ����Ϊgrade��txt�ļ���ųɼ���
	FILE*fp;
	fp = fopen("grade.txt","w");        //д�ķ�ʽ���ļ� 
	if(fp = NULL)                       //��ʧ�� 
	{
	  printf("error");
	  exit(0);
	}
	for(i = 0;i < 8;i++)               //���ɼ���д���ļ� 
	  fprintf(fp,"%s,%s,%d,%d,%d\n",stu[i].id,stu[i].name,stu[i].score[0],stu[i].score[1],stu[i].score[2]);
	fclose(fp);                        //�ر��ļ� 
	return 0;   
}
