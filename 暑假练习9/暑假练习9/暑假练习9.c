#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
//int main()
//{
//	int a = 0;
//	int b = 0;
//	int c = 0;
//
//	printf("请输入数值1：\n");
//	scanf("%d", &a);
//	Sleep(500);
//	system("cls");
//	printf("请输入数值2：\n");
//	scanf("%d", &b);
//	Sleep(500);
//	system("cls");
//	printf("请输入数值3：\n");
//	scanf("%d", &c);
//	Sleep(500);
//	system("cls");
//
//	if (a > b && b > c)
//		printf("三者大小关系为：%d>%d>%d\n", a, b, c);
//	else if (a>c && c>b)
//		printf("三者大小关系为：%d>%d>%d\n", a, c, b);
//	else if (b > c && c >a)
//		printf("三者大小关系为：%d>%d>%d\n", b, c, a);
//	else if (b > a && a >c)
//		printf("三者大小关系为：%d>%d>%d\n", b, a, c);
//	else if (c > a && a >b)
//		printf("三者大小关系为：%d>%d>%d\n", c, a, b);
//	else
//		printf("三者大小关系为：%d>%d>%d\n", c, b, a);
//
//	return 0;
//}


int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	printf("请输入要比较的三个数值：\n");
	scanf("%d%d%d", &a, &b, &c);
	printf("输入成功");
	Sleep(500);
	system("cls");
	printf("处理中...");
	Sleep(3000);
	system("cls");
	printf("好难..");
	Sleep(3000);
	system("cls");
	printf("e");
	Sleep(200);
	system("cls");
	printf("em");
	Sleep(200);
	system("cls");
	printf("emm");
	Sleep(200);
	system("cls");
	printf("emmm");
	Sleep(200);
	system("cls");
	printf("emmmm");
	Sleep(200);
	system("cls");
	printf("emmmmm");
	Sleep(200);
	system("cls");
	printf("e");
	Sleep(200);
	system("cls");
	printf("em");
	Sleep(200);
	system("cls");
	printf("emm");
	Sleep(200);
	system("cls");
	printf("emmm");
	Sleep(200);
	system("cls");
	printf("emmmm");
	Sleep(200);
	system("cls");
	printf("emmmmm");
	Sleep(200);
	system("cls");
	printf("e");
	Sleep(200);
	system("cls");
	printf("em");
	Sleep(200);
	system("cls");
	printf("emm");
	Sleep(200);
	system("cls");
	printf("emmm");
	Sleep(200);
	system("cls");
	printf("emmmm");
	Sleep(200);
	system("cls");
	printf("emmmmm");
	Sleep(200);
	system("cls");
	printf("em");
	Sleep(200);
	system("cls");
	printf("emm");
	Sleep(200);
	system("cls");
	printf("emmm");
	Sleep(200);
	system("cls");
	printf("emmmm");
	Sleep(200);
	system("cls");
	printf("emmmmm");
	Sleep(200);
	system("cls");
	if (a < b)
	{
		int t1 = a;
		a = b;
		b = t1;
	}
	if (a < c)
	{
		int t2 = a;
		a = c;
		c = b;
		b = t2;
	}
	if (a >= c && c > b)
	{
		int t3 = b;
		b = c;
		c = t3;
	}
	printf("数目的大小关系为：\n%d>%d>%d\n", a, b, c);
	return 0;
}