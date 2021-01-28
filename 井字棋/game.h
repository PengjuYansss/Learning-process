#include<stdio.h>
#define ROW 3
#define COL 3
#include<time.h>
#include<stdlib.h>

void initialize(char chessboard[ROW][COL], int row, int col);
void board(char chessboard[ROW][COL],int row ,int col);
void player(char chessboard[ROW][COL], int row, int col);
char iswin(char chessboard[ROW][COL], int row, int col);
void computer(char chessboard[ROW][COL], int row, int col);
int full(char chessboard[ROW][COL],int row, int col);
