#include "game.h"

void menu()
{
	printf("*****************************\n");
	printf("********   1.play   *********\n");
	printf("********   0.quit   *********\n");
	printf("*****************************\n");
}

void game()
{
	int x = 0;
	int y = 0;
	int ret = 0;
	system("cls");
	printf("����������:>\n");
	char bomb[ROWS][COLS] = { 0 };
	int board[ROWS][COLS] = { 0 };
	initbomb(bomb, ROW, COL);
	initboard(board, ROW, COL);
	putbomb(bomb, ROW, COL);
	displayboard(board, ROW, COL);
	//����Ϊ�����ж�ģ��
	while (1)
	{
		do
		{
			scanf("%d%d", &x, &y);
			if (x > 0 && x <= ROW&&y > 0 && y <= COL)
			{
				if (board[x][y] != 9)
				{
					printf("�ѵ㿪\n");
					ret = 1;
			    }
				else
				ret = 0;
			}
			else
			{
				printf("������Χ\n");
				ret = 1;
			}
			
		}while (ret);
		if (bomb[x][y] == '*')
		{
			system("cls");
			printf("������\n");
			endboard(bomb, board, ROW, COL);
			break;
		}
		else if (bomb[x][y] == ' ')
		{
		look(bomb, board, x, y);
		if (isfull(board, ROW, COL))
		{
			system("cls");
			printf("��Ӯ��\n");
			endboard(bomb, board, ROW, COL);
			break;
		}
		else
		{
			system("cls");
			printf("����������:>\n");
			displayboard(board, ROW, COL);
		}
		}

	}
	/*displaybomb(bomb, ROW, COL);*/
}






int main()
{
	srand((unsigned int)time(NULL));
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������\n");
			break;


		}
	} while (input);
	return 0;
}