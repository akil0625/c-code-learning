#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void menu()
{
	printf("***********************************\n");
	printf("*****  1.��ʼ��Ϸ    0.�˳�   *****\n");
	printf("***********************************\n");
}

void game()
{
	int input = 0;
	int r = 0;
	r = rand()%100 + 1;

	for (;;)
	{
		printf("�����:>\n");
		scanf("%d", &input);
		if (input > r)
			printf("�´���\n");
		else if (input < r)
			printf("��С��\n");
		else
		{
			printf("�¶���\n");
			break;
		}
	}
	

}

int main()
{
	
	int option = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu();
		printf("�����룺(1/0)\n");
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("�������\n");
		}

	} while (option);
	return 0;
}
