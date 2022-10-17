#define _CRT_SECURE_NO_WARNINGS


void swap(int*arr, int sz)
{
	int* left = arr;
	int* right = arr + sz-1;
	int tmp = 0;
	while (left <= right)
	{
		if ((*left)%2== 1)
		{
			left++;
		}
		if ((*right) % 2 == 0)
		{
			right--;
		}
		if (((*left) % 2 == 0) && ((*right) % 2 == 1)&&(left <= right))
		{
			tmp = (*left);
			(*left) = (*right);
			(*right) = tmp;
		}
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 0, 10, 9};
	int sz = sizeof(arr) / sizeof(arr[0]);
	swap(arr, sz);
	for (int i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	return 0;
}