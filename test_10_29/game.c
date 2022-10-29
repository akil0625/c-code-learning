#include "game.h"


void initbomb(char bomb[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			bomb[i][j] = ' ';
		}
	}

}

void initboard(int board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROWS; i++)
	{
		for (j = 0; j < COLS; j++)
		{
			board[i][j] = 9;
		}
	}
}

void putbomb(char bomb[ROWS][COLS], int row, int col)
{
	int i = 0;
	int m = 0;
	int n = 0;

	for (i = 0; i < bombnum; i++)
	{
		while (1)
		{
			m = rand() % ROW + 1;
			n = rand() % COL + 1;
			if (bomb[m][n] != '*')
			{
				bomb[m][n] = '*';
				break;
			}
		}
	}
}

void displayboard(int board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= ROW; i++)
	{
		if (i<10)
		printf(" %d ", i);
		else if (i>=0)
		printf("%d ", i);
		if (i<=ROW-1)
		printf("|");
	}
	printf("\n");
	for (i = 0; i <= ROW; i++)
	{
		printf("---");
		if (i<=ROW - 1)
			printf("|");
	}
	printf("\n");
	for (i = 1; i <= ROW; i++)
	{
		if (i<10)
		printf(" %d |", i);
		else if (i>=10)
		printf("%d |", i);
		for (j = 1; j <= COL; j++)
		{
			if (board[i][j]==9)
			printf("   ");
			else
			printf(" %d ", board[i][j]);
			if (j<=COL-1)
			printf("|");
		}
		printf("\n");
		if (i<=ROW-1)
		for (j = 0; j <= COL; j++)
		{
			printf("---");
			if (j<=COL-1)
			printf("|");
		}
		printf("\n");
	}

}
void displaybomb(char bomb[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= ROW; i++)
	{
		if (i<10)
			printf(" %d ", i);
		else if (i >= 0)
			printf("%d ", i);
		if (i <= ROW - 1)
			printf("|");
	}
	printf("\n");
	for (i = 0; i <= ROW; i++)
	{
		printf("---");
		if (i <= ROW - 1)
			printf("|");
	}
	printf("\n");
	for (i = 1; i <= ROW; i++)
	{
		if (i<10)
			printf(" %d |", i);
		else if (i >= 10)
			printf("%d |", i);
		for (j = 1; j <= COL; j++)
		{
				printf(" %c ", bomb[i][j]);
			if (j <= COL - 1)
				printf("|");
		}
		printf("\n");
		if (i <= ROW - 1)
		for (j = 0; j <= COL; j++)
		{
			printf("---");
			if (j <= COL - 1)
				printf("|");
		}
		printf("\n");
	}
}

void look(char bomb[ROWS][COLS], int board[ROWS][COLS], int x, int y)
{
	int t = 0;
	{
		if (bomb[x - 1][y - 1] == '*')//左上
			t++;
		if (bomb[x - 1][y] == '*')//上
			t++;
		if (bomb[x - 1][y + 1] == '*') // 右上
			t++;
		if (bomb[x][y + 1] == '*')//右
			t++;
		if (bomb[x + 1][y + 1] == '*')//右下
			t++;
		if (bomb[x + 1][y] == '*')//下
			t++;
		if (bomb[x + 1][y - 1] == '*')//左下
			t++;
		if (bomb[x][y - 1] == '*')//左
			t++;
		board[x][y] = t;
		if (t == 0)
		{
			if (x-1 != 0 && y-1 != 0 && x-1 != ROWS - 1 && y-1 != COLS - 1 && board[x-1][y-1] == 9)
			look(bomb, board, x - 1, y - 1);
			if (x -1!= 0 && y != 0 && x-1 != ROWS - 1 && y != COLS - 1 && board[x-1][y] == 9)
			look(bomb, board, x - 1, y);
			if (x -1!= 0 && y+1 != 0 && x-1 != ROWS - 1 && y+1 != COLS - 1 && board[x-1][y+1] == 9)
			look(bomb, board, x - 1, y + 1);
			if (x != 0 && y+1 != 0 && x != ROWS - 1 && y+1 != COLS - 1 && board[x][y+1] == 9)
			look(bomb, board, x, y + 1);
			if (x + 1 != 0 && y + 1 != 0 && x + 1 != ROWS - 1 && y + 1 != COLS - 1 && board[x + 1][y + 1] == 9)
			look(bomb, board, x + 1, y + 1);
			if (x + 1 != 0 && y != 0 && x + 1 != ROWS - 1 && y != COLS - 1 && board[x + 1][y] == 9)
			look(bomb, board, x + 1, y);
			if (x+1 != 0 && y-1 != 0 && x+1 != ROWS - 1 && y-1 != COLS - 1 && board[x+1][y-1] == 9)
			look(bomb, board, x + 1, y - 1);
			if (x != 0 && y-1 != 0 && x != ROWS - 1 && y-1 != COLS - 1 && board[x][y-1] == 9)
			look(bomb, board, x, y - 1);
		}
	}
}

int isfull(int board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	int n = 0;
	for (i = 1; i <= row; i++)
	{
		for (j = 1; j <= col; j++)
		{
			if (board[i][j] == 9)
				n++;
		}
	}
	if (n == bombnum)
		return 1;
	else
		return 0;
}

void endboard(char bomb[ROWS][COLS], int board[ROWS][COLS], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i <= ROW; i++)
	{
		if (i<10)
			printf(" %d ", i);
		else if (i >= 0)
			printf("%d ", i);
		if (i <= ROW - 1)
			printf("|");
	}
	printf("\n");
	for (i = 0; i <= ROW; i++)
	{
		printf("---");
		if (i <= ROW - 1)
			printf("|");
	}
	printf("\n");
	for (i = 1; i <= ROW; i++)
	{
		if (i<10)
			printf(" %d |", i);
		else if (i >= 10)
			printf("%d |", i);
		for (j = 1; j <= COL; j++)
		{
			if (bomb[i][j] == '*')
				printf(" * ");
			else
			{
				if (board[i][j] == 9)
					printf("   ");
				else
				printf(" %d ", board[i][j]);
			}
			if (j <= COL - 1)
				printf("|");
		}
		printf("\n");
		if (i <= ROW - 1)
		for (j = 0; j <= COL; j++)
		{
			printf("---");
			if (j <= COL - 1)
				printf("|");
		}
		printf("\n");
	}

}