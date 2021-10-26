#include <stdio.h>
#include<stdlib.h>
#include <time.h>

void test1() {
	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	printf("当前本地时间为: %d\n", timeinfo->tm_year);
	printf("当前本地时间为: %s", asctime(timeinfo));
}
void test2() {
	time_t start, end;
	int i;
	start = time(NULL);
	for (i = 0; i < 300000; i++)
	{
		printf("-");  // 返回两个time_t型变量之间的时间间隔
		if (i%100==10)
		{
			printf("|");
		}
	}
	end = time(NULL);

	// 输出执行时间
	printf("时间间隔为 %6.3f\n", difftime(end, start));
}
void test3(){


	long i = 10000000L;
	clock_t start, finish;
	double TheTimes;
	printf("做%ld次空循环需要的时间为", i);
	start = clock();
	while (i--);
	finish = clock();
	TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f秒。\n", TheTimes);
}

int main10()
{
	test1();
	test2();
	test3();
}