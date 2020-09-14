#include <stdio.h>
int main()
{
	int n,i,num;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d",&num);
		if ((num % 2) == 0)
		{
			if (num % 4 == 0)
				printf("%d %d\n", num / 4, num / 2);
			else
				printf("%d %d\n", num / 4 + 1, num / 2);
		}
		else
			printf("0 0\n");
	}
	return 0;
}