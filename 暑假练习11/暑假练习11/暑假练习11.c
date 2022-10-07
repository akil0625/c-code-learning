#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
//1至n的累加
int main()
{
	int s = 0;
	int i = 0;
	int n = 0;
	int t = 0;
	printf("请输入n值\n");
	scanf("%d", &n);
	for (;n >= 1;n--)
	{
		for (s = 1,i = 1; i <= n; i++)
		{
			s = s*i;
		}

		t = t + s;
	}
	printf("%d\n", t);
	return 0;
}