/*
��̬˳����cʵ��
*/


//ͷ�ļ�
#include "order.h"


int main()
{
	Datach * p = NULL;
	//��ʼ��
	InitData(&p);
	int input = -1;
	
	
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
		case add:
			Datadd(&p);
			break;
		case show:
			Datshow(p);
			break;
		case del:
			Datdel(&p);
			break;
		case insert:
			Datinsert(&p);
			break;
		case search:
			Datsearch(p);
			break;
		case modify:
			Datmodify(p);
			break;
		case sort:
			Datsort(p);
			break;
		default:
			printf("��������\n");
			break;
		}
	} while (input);



	system("pause");
	free(p);
	p = NULL;
	return 0;
}

