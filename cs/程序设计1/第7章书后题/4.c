#include <stdio.h>
int a[3][3];
int main()
{
	void swap(int a[ ][3]);
	int i,j;
	printf("������鸳ֵ\n");
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			scanf("%4d",&a[i][j]);
	swap(a);
	printf("ת�ú������Ϊ��\n");
	for(i=0;i<3;i++);
	{
		for(j=0;j<3;j++)
			printf("%3d",a[i][j]);
		printf("\n");
	}
	return 0;
} 
void swap(int a[ ][3])
{
	int x,y,z;
	for(x=0;x<3;x++)
		for(y=0;y<x+1;y++)
		{
			z=a[x][y];
			a[x][y]=a[y][x];
			a[y][x]=z;	
		}
}
