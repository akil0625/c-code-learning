#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int Max(int x, int y)
{
	if (x > y)
		return x;
	else
		return y;
}
int main()
{
	int max = Max(90, 80);
	printf("%d", max);
	return 0;
}