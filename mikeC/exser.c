#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int romanToInt(char* s);
int findComplement(int num);
int reverse(int x);
int romanToInt1(char* s);
char* longestCommonPrefix(char** strs, int strsSize);
typedef int arrInt[10];
void main() {

    arrInt arr[10];
    arr[0][0] = 1;
    printf("arr res=%d\n,", arr[0][0]);




	int n = 1;
	printf("%lf\n",pow(10, 2));			//计算10的2次方
    char* strs[3] = { {"flower"}, { "flow" }, { "flight" }};
	int strsSize = 3;
	char* res = longestCommonPrefix(strs,strsSize);
	printf("%d\n", strlen(res));

	printf("*************\n");

	//char* str = "abcdemikelljlk12345";
	char* str = "abcdemikelljlk12345";
    
	char buf[1024] = { 0 };
	//sscanf(str, "%*d%s", buf);      //忽略
	//printf("%s\n", buf);
 //   sscanf(str, "%*[a-g]%s", buf);      //匹配
 //   printf("%s\n", buf);
    //sscanf(str, "%[a-g]%s", buf);      //匹配,从第一个不匹配的字符开始往后都不匹配不管
    sscanf(str, "%[^0-9]%s", buf);      //匹配,除了数字以外的都匹配
    printf("%s\n", buf);
    //匹配规则
    // %*d忽略数字
    // [a-z]匹配a到z
    // [aBc]
    // [^a]匹配不是a 的
    //
    char* ip = "127.0.0.1";
    int a, b, c, d;
    sscanf(ip, "%d.%d.%d.%d", &a, &b, &c, &d);
    printf("%d\n", d);
    char* s = "MCMXCIV";
	printf("%d\n", romanToInt(s));
	printf("ret1=%d\n", romanToInt1(s));
     
	printf("%d\n", 1<<4);//1100     11000
	printf("%d\n", reverse(-123));
    for (size_t i = 1; i < 5; i++)
    {
        printf("%d->result=%d\n", i,findComplement(i));
    }

}

char* longestCommonPrefix(char** strs, int strsSize) {
    /*int i, j, k, n;
    char** p;
    char** q;
    char* t, ret[200] = { 0 };

    n = strsSize;
    for (i = 0; i < n; i++) {
        for (j = 0; j < strlen(strs[i]); j++) {
            t = ;
        }
    }*/

    char str[200] = { 0 };
    int i = 0;
    int j, k, t;
    str[i] = strs[0][0];

    for (j = 0; j < strlen((strs[0])); j++) {
        for (k = 0; k < strsSize; k++) {
            //printf("%c", strs[k][j]);
            if (str[i] != strs[k][j]) {
                break;
            }
        }
        if (k == strsSize) {
            str[++i] = strs[0][j+1];        //都一样则开始比较下一道工序
        }
        else {
            str[i] = '\0';
            break;
        }
    }
    for ( i = 0; i < strlen(str); i++)
    {
        printf("%c", str[i]);
    }printf("\n");
    return &str;
}
int romanToInt(char* s) {
    int I = 1;
    int V = 5;
    int X = 10;
    int L = 50;
    int C = 100;
    int D = 500;
    int M = 1000;
    int sum = 0;
    char* p, * q;

    q = s;
    p = s;
    
    while ((*p)!='\0') {
        printf("%c", *p);
        p++;
    }
    printf("\n%d\n", p == q);
    
    do {
        char* t;
        t = --p;
        printf("ret t=%c\n", *t);
        printf("ret p=%c\n", *p);
        switch (*t) {
        case 'I':sum += I; break;
        case 'V':if (*(p - 1) == 'I') { sum += 4 * I; p--; }
                else sum += V; 
            break;
        case 'X':if (*(p - 1) == 'I') { sum += V + 4 * I; p--; }
                else sum += X; 
            break;
        case 'L':if (*(p - 1) == 'X') { sum += 4 * X; p--; }
                else sum += L; 
            break;
        case 'C':if (*(p - 1) == 'X') { sum += L + 4 * X; p--; }
                else sum += C; 
            break;
        case 'D':if (*(p - 1) == 'C') { sum += 4 * C; p--; }
                else sum += D;
            break;
        case 'M':if (*(p - 1) == 'C'){ sum += D + 4 * C;p--; }
                else sum += M;
            break;
        default: sum += 0; 
            break;
        }
    } while (p != q);
    printf("\npq=%d\n", p == q);
    printf("%d\n", sum);
    return sum;
}
int romanToInt1(char* s) {
    int I = 1;
    int V = 5;
    int X = 10;
    int L = 50;
    int C = 100;
    int D = 500;
    int M = 1000;
    int sum = 0;
    char* p, * t;
    p = s;
    while (*p!='\0') {
        //printf("************\n");
        
        switch (*p) {
        case 'I':
            if (*(p + 1) == 'V') { sum += 4 * I; p++; break;}
            if (*(p + 1) == 'X') { sum += V + 4 * I; p++; break;}
            else sum += I;
            break;
        case 'V':
            sum += V;
            break;
        case 'X':
            if (*(p + 1) == 'L') { sum += 4 * X; p++;break; }
            if (*(p + 1) == 'C') { sum += L + 4 * X; p++; break;}
            else sum += X; 
            break;
        case 'L':
            sum += L; 
            break;
        case 'C':
            if (*(p + 1) == 'D') { sum += 4 * C; p++; break;}
            if (*(p + 1) == 'M') { sum += D + 4 * C; p++;break; }
            else sum += C;
            break;
        case 'D':
            sum += D; 
            break;
        case 'M':
            sum += M;
            break;
        default: sum += 0;
            break;
        }
        p++;
    };

    return sum;
}
int reverse(int x) {
    int i, j, n, k;
    n = x;
    k = 0;
    printf("%d--%d\n", INT_MIN, INT_MAX);
    
    while (n) {
        k *= 10;
        k += n % 10;
        n /= 10;
    }
    return k;
}
int findComplement(int num) {
    int highbit = 0;
    for (int i = 1; i <= 30; ++i) {
        if (num >= (1 << i)) {
            highbit = i;
        }
        else {
            break;
        }
    }
    int mask = (highbit == 30 ? 0x7fffffff : (1 << (highbit + 1)) - 1);
    return num ^ mask;

}