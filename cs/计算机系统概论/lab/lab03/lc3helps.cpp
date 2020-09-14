#include <stdio.h>
int main(){
	int a;
	int i;
	for(i = 0;i<200;i++){
		scanf("%d",&a);
		printf("	.FILL	x%x\n",a);
	}
	return 0;
}
