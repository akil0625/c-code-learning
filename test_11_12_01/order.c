#define _CRT_SECURE_NO_WARNINGS
#include "order.h"





//��������

//��ʼ��˳���
void InitData(Datach ** p)
{
	*p = (Datach*)malloc(2*sizeof(int) + INITMAX*sizeof(int));
	if (*p == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	else
	{
		int i = 0;
		for (i = 0; i < INITMAX; i++)
		{
			(*p)->data[i] = 0;
			(*(*p)).maxsize = INITMAX;
			(*p)->size = 0;
		}
	}
}

//�˵�
void menu()
{
	printf("***********************************\n");
	printf("******1.add        2.del     ******\n");
	printf("******3.insert     4.serach  ******\n");
	printf("******5.modify     6.show    ******\n");
	printf("******7.sort       0.exit    ******\n");
	printf("***********************************\n");


}

//��̬ά��˳����С
void cheaksize(Datach **p)
{
	if ((*p)->maxsize - (*p)->size >= 10 && (*p)->maxsize - (*p)->size <= 50)
	{
		return;
	}
	else if((*p)->maxsize - (*p)->size < 10)
	{
		*p = (Datach*)realloc(*p,((*p)->size)*sizeof(int)+40*sizeof(int));
		if (*p == NULL)
		{
			printf("%s", strerror(errno));
			return;
		}
		else
		{
			(*p)->maxsize = (*p)->size+40;
		}
	}
	else if ((*p)->maxsize - (*p)->size > 50)
	{

		*p = (Datach*)realloc(*p, ((*p)->maxsize)*sizeof(int)+40 * sizeof(int));
		if (*p == NULL)
		{
			printf("%s", strerror(errno));
			return;
		}
		else
		{
			(*p)->maxsize = (*p)->size+40;
		}
	}
}

//�������
void Datadd(Datach ** p)
{
	cheaksize(p);
	printf("�������%d������:>", (*p)->size+1);
	scanf("%d", &(*p)->data[(*p)->size]);
	(*p)->size++;
}

//չʾ����
void Datshow(Datach * p)
{
	int i;

	for (i = 0; i < p->size; i++)
	{
		printf("%-3d->	%-3d\n", i + 1, p->data[i]);
	}

}
//��������
int findbynum(Datach * p, int num)
{
	int i = 0;
	for (i = 0; i < p->size; i++)
	{
		if (p->data[i] == num)
		{
			return i;
		}
	}
	return -1;
}


//ɾ������
void Datdel(Datach**p)
{
	int pos = -1;
	int num = 0;
	printf("������Ҫɾ����\n");
	scanf("%d", &num);
	pos = findbynum(*p, num);
	if (pos == -1)
	{
		printf("δ�ҵ�Ҫɾ��������\n");
		return;
	}
	else
	{
		int i = 0;
		for (i = pos; i < (*p)->size - 1; i++)
		{
			(*p)->data[i] = (*p)->data[i + 1];
		}
		(*p)->size--;
		printf("ɾ���ɹ�\n");
	}
	cheaksize(p);
}
//��������
void Datinsert(Datach**p)
{
	int pos = -1;
	int elm = -1;
		printf("������Ҫ�ڼ���λ�ò������ݣ�\n");
		scanf("%d", &pos);
		pos--;
		if (pos<(*p)->size&&pos>-1)
		{
			int i = 0;
			for (i = (*p)->size; i > pos; i--)
			{
				(*p)->data[i] = (*p)->data[i - 1];
			}
			printf("������Ҫ����ʲô���ݣ�\n");
			scanf("%d", &elm);
			(*p)->data[pos] = elm;
		}
		else
		{
			cheaksize(p);
			printf("������Ҫ����ʲô���ݣ�\n");
			scanf("%d", &(*p)->data[(*p)->size]);
			(*p)->size++;
		}
}
//��������
void Datsearch(Datach*p)
{
	int num = -1;
	int pos = -1;
	printf("������Ҫ���ң�\n");
	scanf("%d", &num);
	pos = findbynum(p,num);
	if (pos == -1)
	{
		printf("δ�ҵ���Ҫ���ҵ�����\n");
	}
	else
	{
		printf("%-3d-> %-3d\n", pos + 1, p->data[pos]);
	}
}
//�޸�����
void Datmodify(Datach*p)
{
	int num = -1;
	int pos = -1;
	printf("������Ҫ�޸ģ�\n");
	scanf("%d", &num);
	pos = findbynum(p,num);
	if (pos == -1)
	{
		printf("��Ҫ�޸ĵ����ݲ�����\n");
	}
	else
	{
		printf("��Ҫ�޸�Ϊ���٣�\n");
		scanf("%d", &p->data[pos]);
		printf("�޸ĳɹ�\n");
	}
}
//��������
void Mm(Datach*p)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	int ret = 0;
	for (j = p->size; j > 0;j--)
	{
		for (i = 0; i < j - 1; i++)
		{
			if (p->data[i] < p->data[i + 1])
			{
				tmp = p->data[i];
				p->data[i] = p->data[i + 1];
				p->data[i + 1] = tmp;
			}
		}
	}
}
void mM(Datach*p)
{
	int i = 0;
	int j = 0;
	int tmp = 0;
	int ret = 0;
	for (j = p->size; j > 0; j--)
	{
		for (i = 0; i < j - 1; i++)
		{
			if (p->data[i] > p->data[i + 1])
			{
				tmp = p->data[i];
				p->data[i] = p->data[i + 1];
				p->data[i + 1] = tmp;
			}
		}
	}
}
void Datsort(Datach*p)
{
	int input = -1;
	printf("*******************************\n");
	printf("*****1.�Ӵ�С 2.��С����*****\n");
	printf("*******************************\n");
	printf("��ѡ��:>");
	while (1)
	{
		scanf("%d", &input);
		if (input != 1 && input != 2)
		{
			printf("�޴�ѡ������������:>");
		}
		else
			break;
	}
	switch (input)
	{
	case 1:
		Mm(p);
		break;
	case 2:
		mM(p);
		break;
	}
}
