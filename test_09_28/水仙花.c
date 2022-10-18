#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

int isflower(int num)
{
	int len = 0;
	int num1 = num;
	int h = 0;
	int m = 0;
	int add = 0;
	while (num1)
	{
		len++;
		num1 /= 10;
	}
	for (int i = 0, h = num; i < len; i++, h /= 10)
	{
		m = 1;
		for (int j = 0; j < len; j++)
		{
			m *= (h % 10);
		}
		add += m;

	}
	if (add == num)
		return 1;
	else
		return 0;
}


int main()
{
	int i = 0;
	for (i = 1; i < 10000; i++)
	{
		if (isflower(i))
			printf("%d\n", i);
	}
	return 0;
}