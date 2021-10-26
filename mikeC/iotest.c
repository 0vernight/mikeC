#include<stdio.h>
#include<stdlib.h>



void ftest1() {
    FILE* fp = NULL;
    char filename[25] = "D:\\Baosight\\file.txt";
    char ch;
    printf("输入你要保存到的文件的名称：\n");
    //gets(filename);
    if ((fp = fopen(filename, "w+")) == NULL)
    {
        printf("error: cannot open file!:%d\n",GetLastError());
        exit(0);
    }
    printf("现在你可以输入你要保存的一些字符，以#结束：\n");
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
            ch -= 32;   //转换为大写
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