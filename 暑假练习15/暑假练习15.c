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
//	printf("请输入第一个值\n");
//	scanf("%d", &a);
//	printf("输入成功");
//	Sleep(500);
//	system("cls");
//	printf("请输入第二个值\n");
//	scanf("%d", &b);
//	printf("输入成功");
//	Sleep(500);
//	system("cls");
//	printf("请输入第三个值\n");
//	scanf("%d", &c);
//	printf("输入成功");
//	Sleep(500);
//	system("cls");
//	printf("计算中");
//	Sleep(3000);
//	system("cls");
//
//	if (a < b)
//	{
//		int t1 = a;
//		a = b;
//		b = t1;
//	}
//	if (a < c)
//	{
//		int t2 = a;
//		a = c;
//		c = t2;
//	}
//	if (b < c);
//	{
//		int t3 = b;
//		b = c;
//		c = t3;
//	}
//	printf("%d>%d>%d", a, b, c);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	for (i = 1; i <= 100; i++)
//	{
//		if (i % 3 == 0)
//			printf("%d ", i);
//	}
//	return 0;
//}

//int main()
//{
//	int m = 0;
//	int n = 0;
//	int i = 0;
//	
//	printf("请输入值1\n");
//	scanf("%d", &m);
//	system("cls");
//	printf("输入成功");
//	Sleep(500);
//	system("cls");
//	printf("请输入值2\n");
//	scanf("%d", &n);
//	system("cls");
//	printf("输入成功");
//	Sleep(500);
//	system("cls");
//
//	if (m < n)
//	{
//		int t = m;
//		m = n;
//		n = t;
//	}
//	for (i = m;; i--)
//	{
//		if (m % i == 0 && n % i == 0)
//			break;
//	}
//	printf("最大公约数为%d\n", i);
//
//	return 0;
//}

//int main()
//{
//	int m = 0;
//	int n = 0;
//	int t = 0;
//	int i = 0;
//	
//	printf("请输入值1\n");
//	scanf("%d", &m);
//	system("cls");
//	printf("输入成功");
//	Sleep(500);
//	system("cls");
//	printf("请输入值2\n");
//	scanf("%d", &n);
//	system("cls");
//	printf("输入成功");
//	Sleep(500);
//	system("cls");
//
//	if (m < n)
//	{
//		int t = m;
//		m = n;
//		n = t;
//	}
//
//	for (;;)
//	{
//		i = m % n;
//		if (i == 0)
//			break;
//		else
//		{
//			m = n;
//			n = i;
//		}
//	}
//		printf("最大公约数为%d\n", n);
//
//	return 0;
//}

int main()
{
	int count = 0;
	int y = 0;

	for (y = 1000; y <= 2000; y++)
	{
		if (y % 4 == 0 && y % 100 != 0)
		{
			printf("%d ", y);
			count++;
		}
		else if (y % 400 == 0)
		{
			printf("%d ", y);
			count++;
		}
	}

	printf("\n有%d个闰年\n", count);

	return 0;
}