#include <stdio.h>
#include<stdlib.h>
#include <time.h>

void test1() {
	time_t rawtime;
	struct tm* timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);

	printf("��ǰ����ʱ��Ϊ: %d\n", timeinfo->tm_year);
	printf("��ǰ����ʱ��Ϊ: %s", asctime(timeinfo));
}
void test2() {
	time_t start, end;
	int i;
	start = time(NULL);
	for (i = 0; i < 300000; i++)
	{
		printf("-");  // ��������time_t�ͱ���֮���ʱ����
		if (i%100==10)
		{
			printf("|");
		}
	}
	end = time(NULL);

	// ���ִ��ʱ��
	printf("ʱ����Ϊ %6.3f\n", difftime(end, start));
}
void test3(){


	long i = 10000000L;
	clock_t start, finish;
	double TheTimes;
	printf("��%ld�ο�ѭ����Ҫ��ʱ��Ϊ", i);
	start = clock();
	while (i--);
	finish = clock();
	TheTimes = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("%f�롣\n", TheTimes);
}

int main10()
{
	test1();
	test2();
	test3();
}