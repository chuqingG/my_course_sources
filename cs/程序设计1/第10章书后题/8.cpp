//��˳�����һ��ѧ��֮�󱣴浽ԭ�ļ� 
#include <stdio.h>
#include <stdlib.h>
struct Student
{ char num[10];
  char name[8];
  int score[3];
  float ave;
}st[10],s;

int main()
{
	FILE *fp,*fp1;
	int i,j,t,n;
	printf("ѧ�ţ�");
	scanf("%s",s.num);
	printf("������");
	scanf("%s",s.name);
	printf("�÷�(�ÿո����)��");
	scanf("%d %d %d",&s.score[0],&s.score[1],&s.score[2]);
	s.ave=(s.score[0]+s.score[1]+s.score[2])/3.0;
	
	if((fp=fopen("stu_sort","r"))==NULL)                            //��ȡ���� 
	{
		printf("�޷����ļ�");
		exit(0);
	}
	printf("����ǰ���ļ�Ϊ��\n");
	for(i=0;fread(&st[i],sizeof(struct Student),1,fp)!=0;i++)
	{
		printf("\n%8s%8s",st[i].num,st[i].name);
		for(j=0;j<3;j++)
		  printf("%8d",st[i].score[j]);
		printf("%8.2f",st[i].ave);  
	}
	n = i;
	for(t=0;st[t].ave>s.ave&&t<n;t++);
	printf("\n�������ļ�Ϊ��\n");
	fclose(fp);
	
	fp1=fopen("stu_sort","w");
	for(i=0;i<t;i++)
	{
		fwrite(&st[i],sizeof(struct Student),1,fp1);
		printf("\n%8s%8s",st[i].num,st[i].name);
		for(j=0;j<3;j++)
		  printf("%8d",st[i].score[j]);
		printf("%8.2f",st[i].ave);  
	}
	fwrite(&s,sizeof(struct Student),1,fp1);
	printf("\n%8s%8s%8d%8d%8d%8.2f",s.num,s.name,s.score[0],s.score[1],s.score[2],s.ave);
	for(i=t;i<n;i++)
	{
		fwrite(&st[i],sizeof(struct Student),1,fp1);
		printf("\n%8s%8s",st[i].num,st[i].name);
		for(j=0;j<3;j++)
		  printf("%8d",st[i].score[j]);
		printf("%8.2f",st[i].ave);  
	}
	printf("\n");
	fclose(fp1);
	return 0;	
	
}







