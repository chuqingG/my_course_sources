#include <stdio.h>
#include <stdlib.h>
char *deck[52][2];
char *suit[4] = { "Spades", "Heart", "Diamonds", "Clubs" };
char *face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

//ϴ�ƺ���
void shuffle(char *a[52][2])
{
	char *temp;
	int i,r;
	for (i = 0; i < 51; i++)
	{
		r = (int)(rand()%52);
		temp = a[r][0];
		a[r][0] = a[i][0];
		a[i][0] = temp;
		temp = a[r][1];
		a[r][1] = a[i][1];
		a[i][1] = temp;
	}

}

int main()
{
	int i;
	printf("ϴ��ǰΪ��\n");
	for (i = 0; i < 52; i++)                         
	{
		deck[i][0] = suit[i % 4];                     //Ϊÿ���Ƹ�ֵ
		deck[i][1] = face[i % 13];
		printf("��%2d����Ϊ��%9s%6s\t", i+1,deck[i][0], deck[i][1]);    //����ֵ��������
		if (i % 3 == 2)
			printf("\n");
	}
	printf("\n\n\n\n");
	printf("ϴ��֮��Ϊ��\n");
	shuffle(deck);
	for (i = 0; i < 52; i++)                          //��ϴ�õ������
	{
		printf("��%2d����Ϊ��%9s%6s\t",i+1, deck[i][0], deck[i][1]);
		if (i % 3 == 2)
			printf("\n");
	}
	return 0;
}
