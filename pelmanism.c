/**
*
* @title 神経衰弱アプリ
* @author shalman,yota
* @comment 標準入力から読み取った整数で神経衰弱をします
*
**/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void shuffle(int[],int);

int main(){
	int card[10] = {1,1,2,2,3,3,4,4,5,5};
	int hit[10]  = {0,0,0,0,0,0,0,0,0,0};
	char block[] = "■";

	int firstNum;
	int secondNum;

	//カードシャッフル
	shuffle(card,10);
	//count関数がないので、sizeofから取得
	int cardCnt = sizeof(card) / (sizeof(int));
	
	//無限ループ
	for(int j = 1;;j++){
		printf("----------------------------------------------------------------------------\n\n");
		printf("%d回目 : 好きなカードを選んでください(左から数字0,1,2,3,4,5,6,7,8,9に対応しています。\n\n",j);
		
		for(int i=0;i < cardCnt;i++){
			if(hit[i] == 0){
				printf("%s ", block);
			} else {
				printf("%d ", card[i]);
			}
		}

		printf("\n\n");
		scanf("%d",&firstNum);
		printf("もう一つ選んでください\n");
		scanf("%d",&secondNum);
		// printf("%d\n",cardCnt);
		for(int i=0;i < cardCnt;i++ ){
			if(i == firstNum || i == secondNum){
				if(i == firstNum){
					printf("%d ",card[firstNum]);
				}else{
					printf("%d ",card[secondNum]);
				}
			}else{
				if(hit[i] == 0){
					printf("%s ", block);
				}else{
					printf("%d ", card[i]);
				}
			}
		}
		printf("\n\n");

		if(card[firstNum] == card[secondNum]){
			//配列削除すると、indexを詰めたり面倒なので、当たった番号を記録
			hit[firstNum]  = 1;
			hit[secondNum] = 1;
			printf("当たり！\n\n");
		}else{
			printf("はずれ！\n\n");
		}
	}
}

/*
	Fisher–Yatesシャッフルアルゴルズム
	配列の要素をランダムシャッフルする
*/
void shuffle(int ary[],int size)
{
    for(int i=0;i<size;i++)
    {
        int j = rand()%size;
        int t = ary[i];
        ary[i] = ary[j];
        ary[j] = t;
    }
}
