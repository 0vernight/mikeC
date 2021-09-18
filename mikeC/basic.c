#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
#include <Windows.h>


enum Color
{
	red, white, blue
};
struct StructPerson
{
	int age;
	char c;
};

int strTimes(char *str,char *substr);
int lengthOfLongestSubstring(char* s);
void statisticChar(char str[]);
void reverseArr(int arr[],int n);
void timeMaker(int n);
void guessNum(int n);

int main(void) {

	int n, m;
	char s[] = "hello world";
	int arr[] = { 1,2,3,4,5,6 };
	char str[] = "helloallobllocllo"; 
	char st[] = "llo";

	n = 20;
	m = 30;



	//printf("ret=%d\n",lengthOfLongestSubstring(s));
	printf("%s:%u:%d:%s\n", (char*)(strstr("maimaitijumai","ti")), sizeof(arr), n, st);

	n = sizeof(arr) / sizeof(arr[0]);
	//����Ϊ��������

	
	printf("ret=%d\n",strTimes(str,st));
	//printf("ret=%d\n",lengthOfLongestSubstring(s));
	//statisticChar(str);
	//reverseArr(&arr,n);
	//timeMaker(n);
	//guessNum(n);


	return 0;
	
}

////��Ҫ��ע��
	
	//strlen()
	//strstr("maimaitijumai","ti")
	//s=getchar();
	// gets(str);
	//scanf("%s", st);
	//printf("%c\n", s);


	//sizeof���Ǻ��������Բ���Ҫ�����κ�ͷ�ļ������Ĺ����Ǽ���һ���������͵Ĵ�С����λΪ�ֽ�,
	//sizeof�ķ���ֵΪsize_t.
	//size_t������32λ����ϵͳ����unsigned int����һ���޷��ŵ�������

	//size_t t = 4;
	//printf("sizeof=%d\n", sizeof(int));

	/*Sleep(2000);
	system("cls");
	Sleep(1000);*/
	//system("calc");

//����ʵ��

//�ַ��������ִ�
int strTimes(char* str, char* substr) {
	int count = 0;
	char* p = strstr(str, substr);
	while (p != NULL)
	{
		count++;
		p += strlen(substr);
		p = strstr(p, substr);
	}
	return count;
}
int lengthOfLongestSubstring(char* s) {
	int start = 0, end = 0, maxlen = 0;
	char map[256] = { 0 };

	map[(int)*(s + start)] = 1;
	//printf("%c-%d-%c\n", *s,(int)*(s + start), (int)*(s + start));
	//printf("%d-%c-%d\n", 0=='\0',0,'\0');
	printf("%d\n", *(s + 11)==0 );
	while (*(s + end) != 0)
	{
		maxlen = maxlen > (end - start + 1) ? maxlen : (end - start + 1);
		++end;
		while (map[(int)*(s + end)]!=0 )//��Ҫ�������Ԫ����map��Ԫ�س�ͻ
		{
			map[(int)*(s + start)] = 0;
			++start;
		}
		map[(int)*(s + end)] = 1;
	}
	//��Ŀ�������ÿ���Ҵ��������ƶ�ʽ����һ���ǿ�ȡ�
	//�����ѭ���൱���󴰿ڣ���ѭ���൱���Ҵ��ڡ�

	return maxlen;

}
void statisticChar(char str[]) {		//û��д�ɺ���֮ǰ�ǶԵ�
	int count[26] = { 0 };
	printf("%s", str);
	for (int i = 0; i < sizeof(str) / sizeof(str[0]); i++)
	{
		count[str[i] - 'a'] ++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (count[i] != 0)
		{
			printf("%c=%d ", 'a' + i, count[i]);
		}
	}
	printf("\n");
}

void reverseArr(int arr[],int n) {
	int  m;
	
	
	//n = (sizeof(arr) / sizeof(arr[0]));		//��ȡ����ĳ���//����sizeofȡ���Ĵ�С��������Ĵ�С����ָ��Ĵ�С32λΪ4��64λΪ8.
	for (int i = 0; i < n; i++)
	{
		printf("arr[%d]=%d\n", i, arr[i]);
	}
	printf("n=%d\n", n);
	for (int i = 0; i < n / 2; i++)
	{
		m = arr[i];
		arr[i] = arr[n - i - 1];
		arr[n - i - 1] = m;
	}

	for (int i = 0; i < n; i++)
	{
		printf("arr[%d]=%d\n", i, arr[i]);
	}
	printf("n=%d\n", n);
}

void timeMaker(int n) {

	for (int i = 0; i < 24; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			for (int k = 0; k < 60; k++)
			{
				printf("%02d:%02d:%02d\n", i, j, k);
				Sleep(1000);
				system("cls");
			}
		}
	}
}

void guessNum(int n) {
	int m;
	srand(time(NULL) % 100);		//���������������,������

	n = rand() % 100;
	while (1)
	{
		printf("������µ�����=");
		scanf("%d", &m);
		if (n == m)
		{
			printf("ni�ɹ���\n");
			break;
		}
		else if (m > n)
		{
			printf("������Ĵ���\n");
		}
		else if (m < n)
		{
			printf("�������С��\n");
		}

	}
}