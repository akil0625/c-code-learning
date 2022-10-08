#define _CRT_SECURE_NO_WARNINGS

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int k = 0;
	printf("请输入需要查找的值\n");
	scanf("%d", &k);
	int sz = sizeof(arr) / sizeof(arr[0]);
	int left = 0;
	int right = sz - 1;
	int mid = (left + right) / 2;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (arr[mid] < k)
		{
			left = mid + 1;
		}
		else if (arr[mid] > k)
		{
			right = mid - 1;
		}
		else if (arr[mid] == k)
		{
			printf("找到了，下标是%d", mid);
			break;
		}
	}
	if (left > right)
		printf("未找到");
	return 0;
}