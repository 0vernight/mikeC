#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct LNode {
    int          data;
    struct LNode* next;
}LNode, * LinkList;


typedef struct Person {
    int age;
    char name[20];
    char sex[2];
    double score;
    struct Person* next;
}Person,*person;

person InitPerson(int n);
void printPerson(person h);
LinkList CreateList(int n);
void printLinklist(LinkList h);
int main()
{
    LinkList Head = NULL;
    person head = NULL;
    int n;
    /*printf("size=%d\n", sizeof(LNode));
    scanf("%d", &n);
    Head = CreateList(n);
    
    printf("刚刚建立的各个链表元素的值为：\n");
    printLinklist(Head);
    printf("\n\n");*/

    
    printf("输入人数\n");
    scanf("%d", &n);
    head = InitPerson(n);
    printPerson(head);

    printf("\n\n");
    system("pause");
    return 0;
}
person InitPerson(int n) {
    person p, q, l;
    l = (Person*)malloc(sizeof(Person));//失败了分配空间失败了会返回0，返回空指针NULL(0)。
    if (!l)return 0;
    l->next = NULL;//相当于头部
    q = l;//q相当于身体
    for (size_t i = 0; i < n; i++)
    {
        p = (Person*)malloc(sizeof(Person));//p相当于增长的部分
        if (!p)return 0;
        printf("输入第%d个人的信息：", i+1);
        scanf("%d %s %s %lf",&(p->age),(p->name),(p->sex),&(p->score));
        q->next = p;
        q = p;
    }
    return l;
}
void printPerson(person h)
{
    person p = h->next;
    while (p != NULL) {
        printf("%d %s %s %lf \n", p->age,p->name,p->sex,p->score);
        p = p->next;
    }
}
LinkList CreateList(int n)
{
    //链表   三生万物，三个指针搞定一个单链表。
    LinkList L, p, q;
    int i;
    L = (LNode*)malloc(sizeof(LNode));
    if (!L)return 0;
    L->next = NULL;
    q = L;
    for (i = 1; i <= n; i++)
    {
        p = (LinkList)malloc(sizeof(LNode));
        printf("请输入第%d个元素的值:", i);
        scanf("%d", &(p->data));
        p->next = NULL;
        q->next = p;
        q = p;
    }
    return L;
}
void printLinklist(LinkList h)
{
    LinkList p = h->next;
    while (p != NULL) {
        printf("%d ", p->data);
        p = p->next;
    }
}