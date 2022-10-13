#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void menu()
{
	printf("***********************************\n");
	printf("*****  1.开始游戏    0.退出   *****\n");
	printf("***********************************\n");
}

void game()
{
	int input = 0;
	int r = 0;
	r = rand()%100 + 1;

	for (;;)
	{
		printf("请猜数:>\n");
		scanf("%d", &input);
		if (input > r)
			printf("猜大了\n");
		else if (input < r)
			printf("猜小了\n");
		else
		{
			printf("猜对了\n");
			break;
		}
	}
	

}

int main()
{
	
	int option = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("请输入：(1/0)\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n");
		}

	} while (option);
	return 0;
}
