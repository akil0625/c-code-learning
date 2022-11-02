#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int fib(int x)
{
	int i = 0;
	int c = 0;
	int d = 1;
	int m = 0;
	for (i = 1;i < x;i++)
	{
		m = c + d;
		c = d;
		d = m;
	}
	return d;
}

int main()
{
	int a = 0;
	int b = 0;
	scanf("%d", &a);
	b = fib(a);
	printf("%d\n", b);
	return 0;
}