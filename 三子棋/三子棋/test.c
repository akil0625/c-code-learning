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
		printf("����������:>");
		scanf("%d%d", &x, &y);	
		if ((y > 0 && y <= COL) && (x > 0 && x <= ROW) && board[x - 1][y - 1] != '*'&&board[x - 1][y - 1] != '#')
		{
			playermove(board, ROW, COL, x, y);
			ret = iswin(board, x - 1, y - 1);
			if(ret == 1)
			{
				printf("���Ӯ\n");
				break;
			}
			else if (ret == 3)
			{
				printf("ƽ��\n");
				break;
			}
		}
		else if (board[x - 1][y - 1] == '*'||board[x - 1][y - 1] == '#')
		{
			printf("��λ��������\n");
			goto again;
		}
		else if ((y < 0 || y > COL)|| (x < 0 && x > ROW))
		{
			printf("��������\n");
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
			printf("����Ӯ\n");
			break;
		}
		else if (ret == 3)
		{
			printf("ƽ��\n");
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
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("��ʼ��Ϸ");
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������\n");
		}
	} while (input);

	return 0;
}