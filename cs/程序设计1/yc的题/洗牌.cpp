#include <stdio.h>
#include <stdlib.h>
char *deck[52][2];
char *suit[4] = { "Spades", "Heart", "Diamonds", "Clubs" };
char *face[13] = { "Ace", "Deuce", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Jack", "Queen", "King" };

//洗牌函数
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
	printf("洗牌前为：\n");
	for (i = 0; i < 52; i++)                         
	{
		deck[i][0] = suit[i % 4];                     //为每张牌赋值
		deck[i][1] = face[i % 13];
		printf("第%2d张牌为：%9s%6s\t", i+1,deck[i][0], deck[i][1]);    //将赋值后的牌输出
		if (i % 3 == 2)
			printf("\n");
	}
	printf("\n\n\n\n");
	printf("洗牌之后为：\n");
	shuffle(deck);
	for (i = 0; i < 52; i++)                          //将洗好的牌输出
	{
		printf("第%2d张牌为：%9s%6s\t",i+1, deck[i][0], deck[i][1]);
		if (i % 3 == 2)
			printf("\n");
	}
	return 0;
}
