#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int a = 1;
	int b = 2;
	int max = 0;
	max = (a > b ? a : b);
	printf("Max = %d", max);
	return 0;
}