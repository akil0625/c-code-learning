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
//	printf("<����������>\n");
//	scanf("%s", &password);
//	printf("��ȷ��(Y/N)\n");
//	while ((ch = getchar()) != '\n')
//	{
//		;
//	}
//	ret = getchar();
//	if (ret == 'Y')
//	{
//		printf("ȷ�ϳɹ�\n");
//	}
//	else if(ret == 'N')
//	{
//		printf("����ȷ��\n");
//	}
//  else
//  printf("�������\n");
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
