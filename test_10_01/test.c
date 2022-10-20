#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


void lcircle(char* arr, int sz, int t)
{
	t = t%sz;
	char* left = arr;
	char* right = arr + t - 1;
	char tmp = '0';
	while (left < right)
	{
		tmp = (*left);
		(*left) = (*right);
		(*right) = tmp;
		left++;
		right--;
	}

	left = arr + t;
	right = arr + sz - 1;
	while (left < right)
	{
		tmp = (*left);
		(*left) = (*right);
		(*right) = tmp;
		left++;
		right--;
	}

	left = arr;
	right = arr + sz - 1;
	while (left < right)
	{
		tmp = (*left);
		(*left) = (*right);
		(*right) = tmp;
		left++;
		right--;
	}
}


int main()
{
	char arr[6] = { "abcdef" };
	int sz = sizeof(arr) / sizeof(arr[0]);
	int t = 0;
	printf("Ðý×ª¶àÉÙÈ¦:>");
	scanf("%d", &t);
	lcircle(arr, sz, t);
	for (int i = 0; i < sz; i++)
	{
		printf("%c", arr[i]);
	}
	printf("\n");
	return 0;
}