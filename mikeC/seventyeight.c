#include<stdio.h>
#include<stdlib.h>
struct man {
    char name[20];
    int  age;
}*mai,
person[5] = { "li",18,"wang",25,"sun",22,"wang",25,"wang",25 };

int main4()
{
    struct man * p,*q;
    int i,c=0, m = 0;
    p = person;
    char s[] = "cabcd";
    char ss[] = "bbcd";

    printf("%d\n",strcmp(ss, s));
    for(i = 0; i < 5; i++)
    {
        if (m <= p->age)
        {
            m = p->age; printf("%d", m);
            q = p;
            q++;
            c++;
        }
        p++;
    }
    --q;
    while (c--)
    {
        printf("%p-%p\n", p, q);
		printf("%s %d\n", q->name, q->age);
        q--;
        --p;
    }
    return 0;
}