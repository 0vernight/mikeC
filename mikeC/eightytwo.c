#include<stdio.h>
#include<stdlib.h>
#include<math.h>



int prime(int n) {

    int m, k, j;            
    for (size_t i = 2; i <= sqrt(n); i++)
    {
        if (n%i==0)
        {
            return 0;
        }
    }
    return 1;
}
void primeNum(int n) {

    int i,m = 0;
    for ( i = 1; i < n; i++)
    {
        if (prime(i)&&prime(n-i)&&i<n-i)
        {
            printf("%d+%d=%d\n", i, n - i, n);
            m++;
        }
    }
	printf("count=%d\n", m);

}
char* strconnect(char* str1, char* str2)
{
    char* str;
    str = (char*)malloc(strlen(str1) + strlen(str2) + 1);
    str[0] = '\0';
    strcat(str, str1);
    strcat(str, str2);
    return str;
}
void main8() {
    int i = 45;
    while (scanf("%d",&i))
    {
		primeNum(i);
    }
    char str1[20], str2[20];
    char* str;
    puts("�����������ַ������ûس��ֿ�:");
    scanf("%s%s", str1, str2);
    str = strconnect(str1, str2);
    puts("���Ӻ���ַ���Ϊ:");
    puts(str);
    //long sum = 4, s = 4;//sum�ĳ�ʼֵΪ4��ʾ��ֻ��һλ������ɵ���������Ϊ4��
    //int j;
    //for (j = 2; j <= 8; j++)
    //{
    //    printf("%dλ��Ϊ�����ĸ���%ld\n", j - 1, s);
    //    if (j <= 2)
    //        s *= 7;
    //    else
    //        s *= 8;
    //    sum += s;
    //}
    //printf("%dλ��Ϊ�����ĸ���%ld\n", j - 1, s);
    //printf("�������ܸ���Ϊ��%ld\n", sum);
    //// system("pause");
    //int n = 0, i = 0;
    //char s[20];

    /*printf("������һ��8������:\n");
    gets(s);
    while (s[i] != '\0') {
        n = n * 8 + s[i] - '0';
        i++;
    }
    printf("�������8������ת��Ϊʮ����Ϊ\n%d\n", n);*/

}