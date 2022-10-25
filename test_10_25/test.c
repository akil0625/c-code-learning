#define _CRT_SECURE_NO_WARNINGS



#include "game.h"

void menu()
{
	printf("**********************************\n");
	printf("********* 1.play 0.quit **********\n");
	printf("**********************************\n");
}


void game()
{
	int a = 0;
	int b = 0;
	int x = 0;
	int y = 0;
	int ret = 0;
	system("cls");
	char board[ROW][COL] = {0};
	initboard(board,ROW,COL);
	displayboard(board,ROW,COL);
	while (1)
	{
		again:
		printf("请输入坐标:>");
		scanf("%d%d", &x, &y);	
		if ((y > 0 && y <= COL) && (x > 0 && x <= ROW) && board[x - 1][y - 1] != '*'&&board[x - 1][y - 1] != '#')
		{
			playermove(board, ROW, COL, x, y);
			ret = iswin(board, x - 1, y - 1);
			if(ret == 1)
			{
				printf("玩家赢\n");
				break;
			}
			else if (ret == 3)
			{
				printf("平局\n");
				break;
			}
		}
		else if (board[x - 1][y - 1] == '*'||board[x - 1][y - 1] == '#')
		{
			printf("该位置已有棋\n");
			goto again;
		}
		else if ((y < 0 || y > COL)|| (x < 0 && x > ROW))
		{
			printf("超出棋盘\n");
			goto again;
		}
		
		while (1)
		{
			a = rand() % ROW;
			b = rand() % COL;
			if (board[a][b] == ' ')
			{
				computermove(board, ROW, COL, a, b);
				break;
			}
		}
		
		ret = iswin(board, a, b);
		if (ret == 1)
		{
			printf("电脑赢\n");
			break;
		}
		else if (ret == 3)
		{
			printf("平局\n");
			break;
		}
	}
}

int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("开始游戏");
			game();
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误\n");
		}
	} while (input);

	return 0;
}