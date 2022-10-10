#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <Windows.h>
#include <stdlib.h>
#include <string.h>
int main()
{
	int c = 3;
	char password[20] = { 0 };
	char ret[20] = { 0 };
	printf("请设置密码：\n");
	scanf("%s", &password);
	printf("设置成功");
	Sleep(500);
	system("cls");

	for (c = 3; c > 0; c--)
	{
		printf("请输入密码，有%d次机会\n", c);
		scanf("%s", ret);
		if (strcmp(ret, password) == 0)
		{
			printf("登陆成功\n");
			break;
		}
		else
		{
			printf("输入错误");
			Sleep(500);
			system("cls");
		}

	}
	if (c == 0)
	{
		printf("请24小时后重试\n");
	}
	return 0;
}