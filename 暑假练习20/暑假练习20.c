#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

//Add(int x , int y)
//{
//	int z = 0;
//	z = x + y;
//	return z;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	int sum = Add(a, b);
//	printf("%d\n", sum);
//	return 0;
//}


//int main()
//{
//	char arr1[] = "bit";
//	char arr2[20] = "##########";
//	strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//	return 0;
//}


//int main()
//{
//	char a = '*';
//	char arr1[] = "hello word\n";
//	memset( arr1, a, 5);
//	printf("%s", arr1);
//	return 0;
//}


//int Max(int x, int y)
//{
//	if (x < y)
//		x = y;
//	return x;
//}
//
//int main()
//{
//	int a = 0;
//	int b = 0;
//	scanf("%d", &a);
//	scanf("%d", &b);
//	int c = Max(a, b);
//	printf("%d\n", a);
//	return 0;
//}

Swap(int* x, int* y)
{
	int k;
	k = *x;
	*x = *y;
	*y = k;
}



int main()
{
	int a = 0;
	scanf("%d", &a);
	int b = 0;
	scanf("%d", &b);
	printf("a = %d b = %d\n", a, b);
	Swap(&a, &b);
	printf("a = %d b = %d\n", a, b);

	return 0;
}