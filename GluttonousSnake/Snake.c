#include "snacke.h"

int score = 0;
int sleepSecond = 400;
int kx = 0;
int ky = 0;
int tailx = 0;
int taily = 0;


int main(void) {
	//printf("snacke start!\n");
	//ȥ�����  
	CONSOLE_CURSOR_INFO coni;
	coni.dwSize = sizeof(coni);
	coni.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &coni);
	srand(time(NULL));
	initSnacke();
	initFood();
	initWall();
	initUI();
	startGame();

	printf("your score is =%d!\n",score);
	system("pause");
	return 0;
}
//�����ʼ���ߺ��� 
void initSnacke(void) {

	snacke.size = 3;
	snacke.body[0].x = WIDE / 2;//��ͷ
	snacke.body[0].y = HIGH / 2;
	snacke.body[1].x = WIDE / 2-1;//������
	snacke.body[1].y = HIGH / 2;
	snacke.body[2].x = WIDE / 2-2;
	snacke.body[2].y = HIGH / 2;

}
//��ǽ
void initWall(void) {
	for (size_t i = 0; i <=HIGH; i++)
	{
		for (size_t j = 0; j <=WIDE; j++)
		{
			if (j==WIDE)
			{
				printf("|");
			}
			else if (i==HIGH)
			{
				printf("-");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}
//��ʼ������
void initUI(void) {
	COORD coord = { 0 };
	//����
	for (size_t i = 0; i < snacke.size; i++)
	{
		coord.X = snacke.body[i].x;
		coord.Y = snacke.body[i].y;
		//printf("x=%d,y=%d\n", coord.X, coord.Y);
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		if (i==0)
		{
			putchar('@');
		}
		else
		{
			putchar('*');
		}
	}
	//ȥ��β��
	coord.X = tailx;
	coord.Y = taily;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar(' ');
	//��ʳ��
	coord.X = food.x;
	coord.Y = food.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar('#');

	coord.X = 0;
	coord.Y = HIGH+1;
	//printf("x=%d,y=%d\n", coord.X, coord.Y);
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	
}
//������ʳ��
void initFood(void) {
	food.x = rand() % WIDE;
	food.y = rand() % HIGH;
}
void startGame(void) {
	char tem='d', k = 'd';
	while (snacke.body[0].x>=0&&snacke.body[0].x<WIDE&&snacke.body[0].y>=0&&snacke.body[0].y<HIGH)
	{
		//initWall();
		initUI();
		if (_kbhit())
		{
			k=_getch();
		}
		switch (k)
		{
		case 'w':kx = 0; ky = -1; break;
		case 's':kx = 0; ky = 1; break;
		case 'a':kx = -1; ky = 0; break;
		case 'd':kx = 1; ky = 0; break;
		default:
			break;
		}
		for (size_t i = 1; i < snacke.size; i++)
		{
			if (snacke.body[0].x==snacke.body[i].x&&snacke.body[0].y==snacke.body[i].y)
			{
				return;
			}
		}
		if (snacke.body[0].x==food.x&&snacke.body[0].y==food.y)
		{
			initFood();
			snacke.size++;
			score++;
			sleepSecond -= 10;//����
		}
		tailx = snacke.body[snacke.size - 1].x;
		taily = snacke.body[snacke.size - 1].y;
		//���ƶ�ǰһ�ڸ���һ�ڸ�ֵ
		for (size_t i = snacke.size-1; i >0; i--)
		{
			snacke.body[i].x = snacke.body[i - 1].x;
			snacke.body[i].y = snacke.body[i - 1].y;
		}
		snacke.body[0].x += kx;
		snacke.body[0].y += ky;
		Sleep(sleepSecond);
		//system("cls");
	}
	return;
}