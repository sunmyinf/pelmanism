#include <stdio.h>

int main(){
	int card[10] = {0,1,2,3,4,5,6,7,8,9};
	int block[10] = {}
	//配列シャッフル
	int firstNum;
	int secondNum;

	for(;;){
		printf("■　■　■　■　■　■　■　■　■　■\n");
		printf("好きなカードを選んでください(左から0,1,2,3,4,5,6,7,8,9に対応しています。\n");
		scanf("%d",&firstNum);
		printf("もう一つ選んでください\n");
		scanf("%d",&secondNum);
		printf("%d,%d\n",firstNum,secondNum);

	}
}