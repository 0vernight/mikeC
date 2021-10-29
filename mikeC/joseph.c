#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<malloc.h>
#include<time.h>


typedef struct sailor
{
	int num;
	struct sailor* next;
}*sman,man;


struct sailor* initSailor(struct sailor *s);
sman disembark(sman s);
void main() {
	int i, j, k, l, m, n;
	int a[31] = { 0 };
	time_t start, end;
	m = 0;		//船上总共有三十个人
	j = 1;		//位数
	k = 1;		//报数
	start = time(NULL);
	while (m<15)
	{
		i = 0;

		while (i<9)
		{
			
			if (i==8&&a[j]==0)
			{
				a[j] = m+1;
				printf("第%2d号下船序号为%2d\n", j, a[j]);
				//printf("第%2d号数了%2d下船了\n", j, k);
			}
			else if (a[j]!=0)
			{
				j++;
				if (j >= 30)
				{
					j = 1;
				}
				continue;
			}
			
			if (k>=30)
			{
				k = 0;
			}
			if (j>=30)
			{
				j = 0;
			}
			i++;
			j++;
			k++;
		}
		m++;
	}
	end = time(NULL);
	

	// 输出执行时间
	printf("时间间隔为 %6.3f\n", difftime(end, start));

	int c = 0;
	i = 1;
	j = 0;
	int d[31] = { 0 };
	int b[31] = { 0 };
	start = time(NULL);
	while (i <= 31)
	{
		if (i >= 31)
		{
			i = 1;
		}
		else if (c == 15)
		{
			break;
		}
		else
		{
			if (b[i] != 0)
			{
				i++;
				continue;
			}
			else
			{
				j++;
				if (j != 9)
				{
					i++;
					continue;
				}
				else
				{
					b[i] = 1;
					d[i] = j;
					j = 0;
					printf("第%d号下船了\n", i);
					i++;
					c++;
				}
			}
		}
	}
	end = time(NULL);
	
	// 输出执行时间
	printf("时间间隔为 %6.3f\n", difftime(end, start));

	start = time(NULL);
	sman s = NULL;
	s = initSailor(s);
	s = disembark(s);
	end = time(NULL);
	printf("时间间隔为 %6.3f\n", difftime(end, start));
}
sman disembark(sman s) {
	int i, j, k, t, m;
	m = 1;
	k = 1;
	sman p, q;
	p = s;
	while (m <= 15)		//总共要15个人要下船
	{
		for (i = 1; i < 10;i++)		//数数
		{
			q = p;		//用q保存上一个报数的人，保存现场
			p = p->next;		//p为报数为i的人
			if (i == 9)		//报数为9，删除p位置的人，返回现场
			{
				printf("------------->[%d号--%d-->%d]\n", i, k, p->num);
				/*p = p->next;
				q->next = p;*/
				q->next = q->next->next;		//删除了9号后，数数清零，下次进来时下船人后面的开始数数
				p = q;		//返回现场
				
			}
			printf("%d号--%d-->%d\n", i, k, p->num);
			if (p->next==NULL)
			{
				k = 0;
				p = s;
			}
			
			k++;
		}
		printf("第%d轮数数当中，%d号后面的人下了船\n", m, p->num);
		m++;
	}
	printf("********留在了的如下*******\n");
	m = 0;
	p = s;
	while (m < 15)
	{
		p = p->next;
		printf("%2d:第%2d号位人\n", m, p->num);
		m++;
	}
	return s;
}
sman initSailor(struct sailor *s) {
	int i, j, k;
	sman q, h, p;
	h = NULL;
	
	h = (sman)malloc(sizeof(man));
	if (h==0)		//!h
	{
		printf("error m size!\n");
		return 0;
	}
	q = h;
	i = 0;
	while (i<30)
	{
		p = (sman)malloc(sizeof(man));
		if (!p)return 0;
		p->num = ++i;
		p->next = NULL;
		q->next = p;
		q = p;
	}

	return h;
}