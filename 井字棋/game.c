 #define _CRT_SECURE_NO_WARNINGS 1

#include"game.h"
int full(char chessboard[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (chessboard[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}
void initialize(char chessboard[ROW][COL],int row,int col)//���ñ����ķ�ʽ������Ԫ�س�ʼ��Ϊ�ո�
{
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			chessboard[i][j] = ' ';
		}
	}
}
void board(char chessboard[ROW][COL], int row, int col)
{
//              |   |   
//           ---|---|---
//              |   |       <������---������ʽ
//           ---|---|---
//              |   |
	int i = 0;
	int j = 0;
	for (i = 0; i < row; i++)
	{
			for (j = 0; j < col; j++)
			{
				printf(" %c ", chessboard[i][j]);
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
			if (i < row - 1)
			{
				for (j = 0; j < col; j++)
				{
					printf("---");
					if (j < col - 1)
						printf("|");
				}
				printf("\n");
			}	
	}
}
void player(char chessboard[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	printf("����ߣ�\n");
	while (1)
	{
		printf("������Ҫ�µ����꣺\n");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (chessboard[x - 1][y - 1] == ' ')
			{
				chessboard[x - 1][y - 1] = 'o';
				break;
			}
			else
				printf("�����걻ռ�ã����������룺 \n");
		}
		else
			printf("����Ƿ������������룺\n");
	}
}
char iswin(char chessboard[ROW][COL], int row, int col)
{
	//���ص��������
	//o:���Ӯ
	//x:����Ӯ
	//f:ƽ��
	//c:����
	int i = 0;
	int j = 0;
	for (i = 0; i < col; i++)
	{
		//������
		if (chessboard[i][0] == chessboard[i][1] && chessboard[i][1] == chessboard[i][2] && chessboard[i][1] != ' ')
			return chessboard[i][1];
	}
	for (j = 0; j < row; j++)
	{
		//������
		if (chessboard[0][j] == chessboard[1][j] && chessboard[1][j] == chessboard[2][j] && chessboard[1][j] != ' ')
			return chessboard[1][j];
	}
	//б����
	if (chessboard[0][0] == chessboard[1][1] && chessboard[1][1] == chessboard[2][2] && chessboard[1][1] != ' ')
		return chessboard[1][1];
	if (chessboard[0][2] == chessboard[1][1] && chessboard[1][1] == chessboard[2][0] && chessboard[1][1] != ' ')
		return chessboard[1][1];
	//�ж��Ƿ�������
	if (1 == full(chessboard, row, col))
	{
		return 'f';
	}
	return 'c';
}
void computer(char chessboard[ROW][COL], int row, int col)
{
	printf("�����ߣ� \n");
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
			if (chessboard[x][y] == ' ')
			{
				chessboard[x][y] = 'x';
				break;
			}
	}
}