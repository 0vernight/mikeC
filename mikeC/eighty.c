#include<stdint.h>
#include<stdlib.h>

typedef struct Person {
	char name;

};


void main6(void) {
	int  i,sum = 4,j=1;

	//很好的一个题
	// 解题思路是：从后往前每一只猴子的分量*5+1，是上一个四个猴子分到的总和，除掉4算出每一个猴子的分成
	//j表示最后那一只猴子分成五分之后拿走的最小数量,分成五分之后从分到的最小1开始网上累加，一直到复合的最小分成
	//
	//
	//
    while (1)
    {
		//sum = j;					//这是我想得到的
		sum = 4*j;					//不过zhe个更好
		for (i = 0; i < 5; i++)
		{
			if (sum % 4 != 0) {
				break;
			}
			sum /= 4;				//算出每个猴子的
			sum = (sum) * 5 + 1;
		}
		if (i == 5)
		{
			break;
		}
		j++;
    }
	printf("res=%d\n", sum);
    //很漂亮的穷举函数，总共四个开关(j,while,for,if)。
    //
	i = 0; j = 1;
    int x  ;
    while (i < 5) {
        x = 4 * j;						//最后一个🐒猴子分成五分之后的四个人的数量
		for (i = 0; i < 5; i++)
		{
			if (x % 4 != 0)
			{
				break;
			}
			x = (x / 4) * 5 + 1;		//算出上一个猴子分掉之前的数量
			//printf("%d\n", x);
		}
		j++;
    }
    printf("%d\n", x);
}

//#include <stdio.h>
int check(int i)
{
	if ((i - 1) % 5 == 0)return 1;	//猴子分了五分
	return 0;
}
int getNext(int i)
{
	return (i - 1) * 0.8;			//猴子拿走了一份
}
int main5()
{
	/*  Write C code in this online editor and run it. */
	int num = 1;
	while (1)
	{
		int num1 = num;
		int i;
		for (i = 0; i < 5; ++i)
		{
			if (!check(num1))break;
			num1 = getNext(num1);
		}
		if (i == 5)break;
		++num;
	}
	printf("%d", num);
	return 0;
}

