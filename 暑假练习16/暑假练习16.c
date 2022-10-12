#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//÷  ˝À——∞
int main()
{
	int m = 0;
	int n = 0;
	for (m = 100; m <= 200; m++)
	{

		for (n = m - 1; n >= 1; n--)
		{
			m%n;
			if (m%n == 0)
				break;
		}
		if (n == 1)
			printf("%d ", m);
	}
	printf("\n");
	return 0;
}