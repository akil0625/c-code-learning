#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//创建结构体
struct stu
{
	char name[20];
	int age;
};

//自定义冒泡函数调换模块
void exchange(char* a, char*b, int sz)
{
	for (int i = 0; i < sz; i++)
	{
		char tmp = '0';
		tmp = *a;
		*a = *b;
		*b = tmp;
		a++;
		b++;
	}
}

//自定义冒泡函数主体
void my_bubble(void* base, int num,int sz, int (*cmp)(void*a, void*b))
{
	int i = 0;
	int j = 0;
	int h = 0;
	
	for (i = 0; i < num - 1; i++)
	{
		for (j = 0, h = 0; j < num - 1 - i; j++)
		{
			if (cmp((char*)base+j*sz, (char*)base + (j+1)*sz)>0)
			{
				exchange((char*)base + j*sz, (char*)base + (j + 1)*sz, sz);
				h++;
			}
		}
		if (h == 0)
			break;
	}



}



//比较函数:

//字符串比较
int change_char(void*a, void*b)
{
	return  (int)(*(char*)a - *(char*)b);
}
//数组比较
int change_int(void*a, void*b)
{
	return *(int*)a - *(int*)b;
}
//结构体按名字比较
int change_by_name(void*a,void*b)
{
	return strcmp(((struct stu*)a)->name, ((struct stu*)b)->name);
}
//结构体按年龄比较
int change_by_age(void*a, void*b)
{
	return ((struct stu*)a)->age - ((struct stu*)b)->age;
}






int main()
{

	//排序字符串
	printf("排序字符串:\n"); 
	char arr1[26] = { "zxcvbnmasdfghjklqwertyuio" };
	my_bubble(arr1, sizeof(arr1) / sizeof(arr1[0]), sizeof(arr1[0]), change_char);
	for (int i = 0; i < 26; i++)
	{
		printf("%c", arr1[i]);
	}
	printf("\n\n"); 

	//排序数组
	printf("排序数组:\n");
	int arr[10] = {6,8,5,9,7,3,2,4,1,0};
	my_bubble(arr, 10, sizeof(arr[0]), change_int);
	for (int i = 0; i < 10; i++)
	{
			printf("%d", arr[i]);
	}
	printf("\n\n");

	//结构体按名字排序
	printf("结构体按名字排序:\n");
	struct stu arr2[4] = { { "yuling", 20 }, { "zhangsan", 10 }, { "lisi", 40 }, { "wangwu", 30 } };
	my_bubble(arr2, sizeof(arr2) / sizeof(arr2[0]), sizeof(arr2[0]), change_by_name);
	for (int i = 0; i < 4; i++)
	{
		printf("name:%s   age:%d\n", arr2[i].name, arr2[i].age);
	}
	printf("\n");

	//结构体按年龄排序
	printf("结构体按年龄排序:\n");
	my_bubble(arr2, sizeof(arr2) / sizeof(arr2[0]), sizeof(arr2[0]), change_by_age);
	for (int i = 0; i < 4; i++)
	{
		printf("name:%s   age:%d\n", arr2[i].name, arr2[i].age);
	}
	printf("\n");

	return 0;
}