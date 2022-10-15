#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char input[20] = { 0 };
	again:
	printf("警告，你的电脑将在1分钟内关机，输入'我是猪'则取消关机\n请输入：>\n");
	system("shutdown -s -t 60");
	scanf("%s", &input);
	if (strcmp(input, "我是猪") == 0)
		system("shutdown -a");
	else
		goto again;
	return 0;
}