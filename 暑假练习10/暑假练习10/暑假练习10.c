#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main()
{
	int ch = 0;
	while ((ch = getchar()) != EOF)
		putchar(ch);
	return 0;
}
//int main()
//{
//	int ch = 0;
//	int ret = 0;
//	char password[20] = { 0 };
//	printf("<请输入密码>\n");
//	scanf("%s", &password);
//	printf("请确认(Y/N)\n");
//	while ((ch = getchar()) != '\n')
//	{
//		;
//	}
//	ret = getchar();
//	if (ret == 'Y')
//	{
//		printf("确认成功\n");
//	}
//	else if(ret == 'N')
//	{
//		printf("放弃确认\n");
//	}
//  else
//  printf("输入错误\n");
//	return 0;
//}
//int main()
//{
//	int ch = 0;
//	while ((ch = getchar()) != EOF)
//	{
//		if (ch <'0' || ch>'9')
//			continue;
//		putchar(ch);
//
//	}
//
//	return 0;
//}
