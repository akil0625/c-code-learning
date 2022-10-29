#define _CRT_SECURE_NO_WARNINGS
#define ROW 10
#define COL 10
#define ROWS ROW+2
#define COLS COL+2
#define bombnum 10

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void initbomb(char bomb[ROWS][COLS], int row, int col);
void initboard(int board[ROWS][COLS], int row, int col);
void putbomb(char bomb[ROWS][COLS], int row, int col);
void displayboard(int board[ROWS][COLS], int row, int col);
void displaybomb(char bomb[ROWS][COLS], int row, int col);
void look(char bomb[ROWS][COLS], int board[ROWS][COLS],int x,int y);
int isfull(int board[ROWS][COLS], int row, int col);
void endboard(char bomb[ROWS][COLS], int board[ROWS][COLS], int row, int col);