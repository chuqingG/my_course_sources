//û�н����ֵ��ͬ������ 
#include <stdio.h>
int main()
{
	int x,y,i,j,k,m,flag1=0,flag2=0;
	printf("����������������������");
	scanf("%d %d",&x,&y);
	int a[x][y];
	printf("��Ϊ���鸳ֵ\n");
	for(i=0;i<x;i++)
	  for(j=0;j<y;j++)
	    scanf("%d",&a[i][j]);                        //������֮ǰ�ǰ������ֵ������ 
	for(i=0;i<x;i++)
	{
		for(j=0,k=0;j<y;j++)
		  if(a[i][j]>a[i][k]) k=j;                   //��ÿ���е����һ�����Ҽ�ס������һ�� 
		for(m=0;m<y;m++)                             //��֤����ǲ�����������С�� 
		{                                            //��Ϊi�������ѭ�����ܸľ�����һ����ĸm���и���ѭ�� 
		  if(m==i) continue;
		  else if(a[m][k]<a[i][k]) flag1=1;          //flag1��Ǳ����жϸ������Ƿ���ڱȸ�����С�� 
		}
		if(flag1==0)
		{
		  printf("��%d�е�%d����һ�����㣬ֵΪ%d\n",i+1,k+1,a[i][k]);      //������������İ��� 
		  flag2=1;                                   //flag2��Ǳ����ж��Ƿ��а������ 
		}
	}
	if(flag2==0)
	  printf("û�а���");
	return 0;
}
