#include<stdio.h>
#include<stdlib.h>



void ftest1() {
    FILE* fp = NULL;
    char filename[25] = "D:\\Baosight\\file.txt";
    char ch;
    printf("������Ҫ���浽���ļ������ƣ�\n");
    //gets(filename);
    if ((fp = fopen(filename, "w+")) == NULL)
    {
        printf("error: cannot open file!:%d\n",GetLastError());
        exit(0);
    }
    printf("���������������Ҫ�����һЩ�ַ�����#������\n");
    getchar();
    while ((ch = getchar()) != '#') {
        fputc(ch, fp);
    }
    fclose(fp);
    system("pause");
}


void ftest2() {
    char path[28] = "D:\\Baosight\\mike.txt";
    char *ch="";

    FILE* fp = NULL;
    if ((fp=fopen(path,"w"))==NULL)
    {
        printf("error!");
        return;
    }
    while ((ch=getchar())!='#')
    {
        if (ch>'a')     //ch>97
        {
            ch -= 32;   //ת��Ϊ��д
        }
		printf("%c", ch);
        //fputs(ch, fp);
        fprintf(fp, "%c", ch);

    }
    fclose(fp);
}
int main12()
{
    //ftest1();
    ftest2();
    return 0;
}