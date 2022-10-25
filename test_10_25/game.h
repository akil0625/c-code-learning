#define ROW 10
#define COL 10
#define jiziqi 5



#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void initboard(char board[ROW][COL], int row, int col);
void displayboard(char board[ROW][COL], int row, int col);
void playermove(char board[ROW][COL], int row, int col,int x,int y);
int iswin(char board[ROW][COL],int i,int j);
void computermove(char board[ROW][COL], int row, int col, int A, int B);