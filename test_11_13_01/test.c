/*
线性表的单向链表实现
*/

#define _CRT_SECURE_NO_WARNINGS
#include "line.h"
int size = 0;
void menu()
{
	printf("***************************************\n");
	printf("******    1.add      2.delete    ******\n");
	printf("******    3.search   4.modify    ******\n");
	printf("******    5.sort     6.insert    ******\n");
	printf("******    7.show     0.exit      ******\n");
	printf("***************************************\n");
}

int main()
{
	elmch * h;
	//初始化函数
	Datinit(&h);
	int input = 0;
	do
	{
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch(input)
		{
		case quit:
			printf("退出成功\n");
			break;
		case add:
			Datadd(&h);
			break;
		case del:
			Datdel(&h);
			break;
		case search:
			Datsearch(&h);
			break;
		case modify:
			Datmodify(&h);
			break;
		case show:
			Datshow(h);
			break;
		case insert:
			Datinsert(&h);
			break;
		default:
			printf("输入错误\n");
			break;
		}
	} while (input);
	system("pause");
	endprog(&h);
	return 0;
}