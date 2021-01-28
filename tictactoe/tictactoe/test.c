 #define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"


void game()
{
	char reason = 0;//�����ж���Ӯ�ķ���ֵ
	char chessboard[ROW][COL] = {0};//�ö�ά���������������Ϣ
	initialize(chessboard, ROW, COL);//����ά����Ԫ�س�ʼ��Ϊ�ո�
	board(chessboard, ROW, COL);//ͼ�λ�����
	while (1)
	{
		player(chessboard, ROW, COL);//���������
		board(chessboard, ROW, COL);
	    reason = iswin(chessboard, ROW, COL);//�ж�����Ƿ���Ӯ
		if (reason != 'c')
		{
			break;
		}
		computer(chessboard, ROW, COL);//��������
		board(chessboard, ROW, COL); 
        reason = iswin(chessboard, ROW, COL);//�жϵ����Ƿ�Ӯ
		if (reason != 'c')
		{
			break;
		}
	}
	if (reason == 'o')
		printf("���Ӯ\n");
	else if (reason == 'x')
		printf("����Ӯ\n");
	else
		printf("ƽ��\n");
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
		menu();//��ӡ�˵�
		printf("��ѡ��\n"); 
		scanf("%d", &input);

		switch (input)
		{
		case 1:
			game();//��Ϸ�㷨ʵ��
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
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