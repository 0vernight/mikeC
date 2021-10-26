#include<stdio.h>
#include<stdlib.h>
#include<time.h>


void main7(void) {
	int i = 10,b;
	int num[10] = { 0 };
	while (i<100)
	{
		//b = i * a;
		//if (b >= 1000 && b <= 10000 && 8 * i < 100 && 9 * i >= 100) {}

		b = i * 809;
		if (b==800*i+9*i&&b<10000&&8*i<100&&9*i>=100&&9*i<1000)
		{
			num[i % 10] = i;
			//break;
			//printf("%d\n", num);
		}
		i++;
	}
	i = 0;
	while (i<10)
	{
		if (num[i]!=0)
		{
			printf("%d\n", num[i]);
		}
		i++;
	}
}