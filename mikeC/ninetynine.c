#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>


void main13() {
    FILE* fa, * fb, * fc;
    int i, j, k;
    char str[100], str1[100];
    char tem;
    if ((fa = fopen("D:\\Baosight\\file.txt", "r")) == NULL) // A.txt 文件需要存在
    {
        printf("error: cannot open A file!\n");
        exit(0);
    }
    fgets(str, 99, fa);
    fclose(fa);
    if ((fb = fopen("D:\\Baosight\\mike.txt", "r")) == NULL)  // B.txt 文件需要存在
    {
        printf("error: cannot open B file!\n");
        exit(0);
    }
    fgets(str1, 100, fb);
    fclose(fb);
    strcat(str, str1);
    for (i = strlen(str) - 1; i > 1; i--)
        for (j = 0; j < i; j++)
            if (str[j] > str[j + 1])
            {
                tem = str[j];
                str[j] = str[j + 1];
                str[j + 1] = tem;
            }

    if ((fc = fopen("D:\\Baosight\\a.txt", "w")) == NULL)  // 合并为 C.txt
    {
        printf("error: cannot open C file!\n");
        exit(0);
    }
    fputs(str, fc);
    fclose(fc);
    system("pause");

    //or (i = 0; i < 5; i++)
    //    fprintf(fp, "%d %s %d %d %d %d\n", stu[i].ID, stu[i].name, stu[i].math, stu[i].English,
    //        stu[i].C, stu[i].avargrade);

    //fclose(fp);
}