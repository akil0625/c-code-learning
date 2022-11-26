#define _CRT_SECURE_NO_WARNINGS

#include "line.h"
extern int size;
//line.c�ڲ���������
elmch* findbypos(elmch*h, int * pos);
elmch* findbyname(elmch*h, int * pos);
elmch* findbyage(elmch*h, int * pos);
elmch* findbyaddr(elmch*h, int * pos);

//��������
//��ʼ������
void Datinit(elmch** h)
{
	*h = (elmch*)malloc(sizeof(elmch));
	if (*h == NULL)
		printf("%s", strerror(errno));
	else
	{
		(*h)->next = NULL;
	}
}
//�������ʱ�ռ�Ļ���
void endprog(elmch ** h)
{
	elmch *p;
	p = *h;
	while (p != NULL)
	{
		elmch *tmp;
		tmp = p->next;
		free(p);
		p = tmp;
	}
}
//��������(�ҵ��󷵻�ǰһ�����ݵĵ�ַ��λ��(��ַ��ʽ))*����ֵΪNULLʱ����������δ�ҵ�*
//������������ѡ��
elmch * Datfind(elmch**h, int * pos)
{
	if ((*h) == NULL)
	{
		printf("������\n");
		return NULL;
	}
	int input;
	elmch* p = NULL;
	printf("**************************************\n");
	printf("******    1.λ��      2.����    ******\n");
	printf("******    3.����      4.��ַ    ******\n");
	printf("**************************************\n");
	printf("������Ҫ��ʲô�ҵ�������:\n");
	scanf("%d", &input);
	switch (input)
	{
	case 1:
		p = findbypos(*h, pos);
		break;
	case 2:
		p = findbyname(*h, pos);
		break;
	case 3:
		p = findbyage(*h, pos);
		break;
	case 4:
		p = findbyaddr(*h, pos);
		break;
	}
	return p;
}
//��λ��
elmch* findbypos(elmch*h,int * pos)
{
	int i = 0;
	int ipos = 0;
	printf("������λ��:\n");
	scanf("%d", &ipos);
	elmch* p = h;
	while (i != ipos-1 && p->next!= NULL)
	{
		p = p->next;
		i++;
	}
	*pos = i;
	if (p->next == NULL)
	{
		i = -1;
		p = NULL;
	}
	return p;
}
//������
elmch* findbyname(elmch*h, int * pos)
{
	int i = 0;
	char iname[MAX_NAME] = {0};
	printf("����������:\n");
	scanf("%s", &iname);
	elmch* p = h;
	while (p->next != NULL&&strcmp(p->next->date.name, iname))
	{
		p = p->next;
		i++;
	}
	*pos = i;
	if (p->next == NULL)
	{
		p = NULL;
		*pos = -1;
	}
	return p;
}
//������
elmch* findbyage(elmch*h, int * pos)
{
	int i = 0;
	int iage = 0;
	printf("����������:\n");
	scanf("%d", &iage);
	elmch* p = h;
	while (p->next != NULL&&p->next->date.age!=iage)
	{
		p = p->next;
		i++;
	}
	*pos = i;
	if (p->next == NULL)
	{
		p = NULL;
		*pos = -1;
	}
	return p;
}
//����ַ
elmch* findbyaddr(elmch*h, int * pos)
{
	int i = 0;
	char iaddr[MAX_ADDR] = { 0 };
	printf("�������ַ:\n");
	scanf("%s", &iaddr);
	elmch* p = h;
	while (p->next != NULL&&strcmp(p->next->date.addr, iaddr))
	{
		p = p->next;
		i++;
	}
	*pos = i;
	if (p->next == NULL)
	{
		p = NULL;
		*pos = -1;
	}
	return p;
}
//ɾ������
void datdel(elmch* p)
{
	if (p == NULL)
	{
		printf("��Ҫɾ�������ݲ�����\n");
		return;
	}
	else
	{
		elmch * tmp = NULL;
		tmp = p->next->next;
		free(p->next);
		p->next = tmp;
		printf("ɾ���ɹ�\n");
	}
}


//��ĩβ�������
void Datadd(elmch ** h)
{
	elmch * p = *h;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = (elmch*)malloc(sizeof(elmch));
	if (p->next == NULL)
	{
		printf("%s", strerror(errno));
		return;
	}
	else
	{
		printf("������Է�����:\n");
		scanf("%s", &p->next->date.name);
		printf("������Է��Ա�:\n");
		scanf("%s", &p->next->date.sex);
		printf("������Է�����:\n");
		scanf("%d", &p->next->date.age);
		printf("������Է���ַ:\n");
		scanf("%s", &p->next->date.addr);
		p->next->next = NULL;
	}
	printf("¼����Ϣ�ɹ�\n");
	size++;
}
//��ʾ����
void Datshow(elmch* h)
{
	int i = 0;
	elmch* p = h;
	printf("%-5s\t%-20s\t%-5s\t%-5s\t%-30s\n","λ��", "����","�Ա�", "����", "��ַ" );
	while (p->next != NULL)
	{
		p = p->next;
		i++;
		printf("%d->\t%-20s\t%-5s\t%-5d\t%-30s\n", i, p->date.name, p->date.sex, p->date.age, p->date.addr);
	}
}
//ɾ������
void Datdel(elmch**h)
{
	elmch* p = NULL;
	int pos = 0;
	p = Datfind(h, &pos);
	datdel(p);
	size--;
}
//��������
void Datsearch(elmch **h)
{
	elmch* p = NULL;
	int pos = 0;
	p = Datfind(h, &pos);
	if (p == NULL)
	{
		printf("�����ݲ�����\n");
		return;
	}
	printf("%-5s\t%-20s\t%-5s\t%-5s\t%-30s\n", "λ��", "����", "�Ա�", "����", "��ַ");
	printf("%d->\t%-20s\t%-5s\t%-5d\t%-30s\n", pos+1, p->next->date.name, p->next->date.sex, p->next->date.age, p->next->date.addr);
}
//�޸�����
void Datmodify(elmch**h)
{
	elmch* p = NULL;
	int pos = 0;
	p = Datfind(h, &pos);
	if (p == NULL)
	{
		printf("�����ݲ�����\n");
		return;
	}
	printf("������Է�����:\n");
	scanf("%s", &p->next->date.name);
	printf("������Է��Ա�:\n");
	scanf("%s", &p->next->date.sex);
	printf("������Է�����:\n");
	scanf("%d", &p->next->date.age);
	printf("������Է���ַ:\n");
	scanf("%s", &p->next->date.addr);
	printf("��Ϣ�޸ĳɹ�\n");
}
//��������
void Datinsert(elmch**h)
{
	int pos = 0;
	elmch*p=NULL;
	elmch*tmp = NULL;
	p = findbypos(*h, &pos);
	pos++;
	if (pos <= size&&pos>0)
	{
		tmp = p->next;
		p->next = (elmch*)malloc(sizeof(elmch));
		if (p == NULL)
		{
			p->next = tmp;
			printf("%s", strerror(errno));
			return;
		}
		else
		{
			p->next->next = tmp;
			printf("������Է�����:\n");
			scanf("%s", &p->next->date.name);
			printf("������Է��Ա�:\n");
			scanf("%s", &p->next->date.sex);
			printf("������Է�����:\n");
			scanf("%d", &p->next->date.age);
			printf("������Է���ַ:\n");
			scanf("%s", &p->next->date.addr);
			printf("��Ϣ�޸ĳɹ�\n");

		}

	}
	else if (pos - size == 1)
	{
		Datadd(h);
	}
	else
	{
		printf("��λ�������ݴ���\n");
		return;
	}
	printf("����ɹ�\n");
	size++;
}

