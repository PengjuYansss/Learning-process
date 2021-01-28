 #define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void game()
{
	char reason = 0;//接收判断输赢的返回值
	char chessboard[ROW][COL] = {0};//用二维数组来存放棋盘信息
	initialize(chessboard, ROW, COL);//将二维数组元素初始化为空格
	board(chessboard, ROW, COL);//图形化棋盘
	while (1)
	{
		player(chessboard, ROW, COL);//玩家先下棋
		board(chessboard, ROW, COL);
	    reason = iswin(chessboard, ROW, COL);//判断玩家是否输赢
		if (reason != 'c')
		{
			break;
		}
		computer(chessboard, ROW, COL);//电脑下棋
		board(chessboard, ROW, COL); 
        reason = iswin(chessboard, ROW, COL);//判断电脑是否赢
		if (reason != 'c')
		{
			break;
		}
	}
	if (reason == 'o')
		printf("玩家赢\n");
	else if (reason == 'x')
		printf("电脑赢\n");
	else
		printf("平局\n");
}
void menu()
{
	printf("**************************\n");
	printf("*       1----play        *\n");
	printf("*       0----exit        *\n");
	printf("**************************\n");
}
 void test()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();//打印菜单
		printf("请选择：\n"); 
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();//游戏算法实现
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("选择错误，请重新选择：\n");
			break;
		}
	} 
	while (input);
	{
		;
	}
}




int main()
{
	test();

	return 0;
}