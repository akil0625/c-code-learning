#define _CRT_SECURE_NO_WARNINGS
#include "game.h"

void initboard(char board[ROW][COL],int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] =  ' ' ;
		}
	}
}
void displayboard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf(" %c ", board[i][j]);
			if(j < COL - 1)
				printf("|");
		}	
		printf("\n");
		if (i < ROW - 1)
		for (j = 0; j < COL; j++)
		{
			printf("---");
			if(j < COL - 1)
			printf("|");
		}
		printf("\n");
	}
}

void playermove(char board[ROW][COL], int row, int col, int x, int y)
{
	board[x - 1][y - 1] = '*';
	system("cls");
	displayboard(board, ROW, COL);
}
int iswin(char board[ROW][COL],int i,int j)
{
	int m = 0;
	int n = 0;
	int t = 0;
	int l = 0;
	l = board[i][j];
	//------
	for (m = i+1, n = j,t = 1; (m >= -1 && m <= ROW)&&(n >= -1 && n <= ROW);m++)
	{
		if (board[m][n] == l&&m != -1 && n != -1 && m != ROW && n != COL)
			t++;
		else if (board[m][n] != l || m == -1 || n == -1 || m == ROW || n == COL)
			break;
	}
	for (m = i - 1, n = j; (m >= -1 && m <= ROW) && (n >= -1 && n <= ROW); m--)
	{
		if (board[m][n] == l&&m != -1 && n != -1 && m != ROW && n != COL)
			t++;
		else if (board[m][n] != l||m == -1||n ==-1||m == ROW||n ==COL )
		{
			if (t >= jiziqi)
				return 1;
			else
				break;
		}

	}
	for (m = i, n = j + 1, t = 1; (m >= -1 && m <= ROW) && (n >= -1 && n <= ROW); n++)
	{
		if (board[m][n] == l&&m != -1 && n != -1 && m != ROW && n != COL)
			t++;
		else if (board[m][n] != l || m == -1 || n == -1 || m == ROW || n == COL)
			break;
	}
	for (m = i, n = j - 1; ((m >= -1 && m <= ROW) && (n >= -1 && n <= ROW)); n--)
	{
		if (board[m][n] == l&&m != -1 && n != -1 && m != ROW && n != COL)
			t++;
		else if (board[m][n] != l || m == -1 || n == -1 || m == ROW || n == COL)
		{
			if (t >= jiziqi)
				return 1;
			else
				break;
		}
	}
	for (m = i + 1, n = j + 1, t = 1; (m >= -1 && m <= ROW) && (n >= -1 && n <= ROW); m++, n++)
	{
		if (board[m][n] == l&&m != -1 && n != -1 && m != ROW && n != COL)
			t++;
		else if (board[m][n] != l || m == -1 || n == -1 || m == ROW  || n == COL)
			break;
	}
	for (m = i - 1, n = j - 1; (m >= -1 && m <= ROW) && (n >= -1 && n <= ROW); m--, n--)
	{
		if (board[m][n] == l&&m != -1 && n != -1 && m != ROW && n != COL)
			t++;
		else if (board[m][n] != l || m == -1|| n == -1 || m == ROW  || n == COL )
		{
			if (t >= jiziqi)
				return 1;
			else
				break;
		}
	}
	for (m = i - 1, n = j + 1, t = 1; (m >= -1 && m <= ROW) && (n >= -1 && n <= ROW); m--, n++)
	{
		if (board[m][n] == l&&m != -1 && n != -1 && m != ROW && n != COL)
			t++;
		else if (board[m][n] != l || m == -1 || n == -1 || m == ROW || n == COL )
			break;
	}
	for (m =i+1, n =j -1; (m >= -1 && m <= ROW) && (n >= -1 && n <= ROW); m++, n--)
	{
		if (board[m][n] == l&&m != -1 && n != -1 && m != ROW && n != COL)
			t++;
		else if (board[m][n] != l || m == -1 || n == -1 || m == ROW  || n == COL )
		{
			if (t >= jiziqi)
				return 1;
			else
				break;
		}
	}
	for (m = 0; m < ROW; m++)
	{
		for (n = 0; n < COL; n++)
		{
			if (board[m][n] == ' ')
				return 0;
		}
	}
	return 3;
}
void computermove(char board[ROW][COL], int row, int col, int A, int B)
{
	printf("电脑正在思考\n");
	Sleep(500);
	board[A][B] = '#';
	system("cls");
	displayboard(board, ROW, COL);
}


