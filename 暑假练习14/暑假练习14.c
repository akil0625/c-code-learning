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
	printf("���������룺\n");
	scanf("%s", &password);
	printf("���óɹ�");
	Sleep(500);
	system("cls");

	for (c = 3; c > 0; c--)
	{
		printf("���������룬��%d�λ���\n", c);
		scanf("%s", ret);
		if (strcmp(ret, password) == 0)
		{
			printf("��½�ɹ�\n");
			break;
		}
		else
		{
			printf("�������");
			Sleep(500);
			system("cls");
		}

	}
	if (c == 0)
	{
		printf("��24Сʱ������\n");
	}
	return 0;
}