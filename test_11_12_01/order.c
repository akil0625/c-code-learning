#define _CRT_SECURE_NO_WARNINGS
#include "order.h"





//函数定义

//初始化顺序表
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

//菜单
void menu()
{
	printf("***********************************\n");
	printf("******1.add        2.del     ******\n");
	printf("******3.insert     4.serach  ******\n");
	printf("******5.modify     6.show    ******\n");
	printf("******7.sort       0.exit    ******\n");
	printf("***********************************\n");


}

//动态维护顺序表大小
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

//添加数据
void Datadd(Datach ** p)
{
	cheaksize(p);
	printf("请输入第%d个数据:>", (*p)->size+1);
	scanf("%d", &(*p)->data[(*p)->size]);
	(*p)->size++;
}

//展示数据
void Datshow(Datach * p)
{
	int i;

	for (i = 0; i < p->size; i++)
	{
		printf("%-3d->	%-3d\n", i + 1, p->data[i]);
	}

}
//查找数据
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


//删除数据
void Datdel(Datach**p)
{
	int pos = -1;
	int num = 0;
	printf("请问您要删除？\n");
	scanf("%d", &num);
	pos = findbynum(*p, num);
	if (pos == -1)
	{
		printf("未找到要删除的数据\n");
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
		printf("删除成功\n");
	}
	cheaksize(p);
}
//插入数据
void Datinsert(Datach**p)
{
	int pos = -1;
	int elm = -1;
		printf("请问您要在几号位置插入数据？\n");
		scanf("%d", &pos);
		pos--;
		if (pos<(*p)->size&&pos>-1)
		{
			int i = 0;
			for (i = (*p)->size; i > pos; i--)
			{
				(*p)->data[i] = (*p)->data[i - 1];
			}
			printf("请问您要插入什么数据？\n");
			scanf("%d", &elm);
			(*p)->data[pos] = elm;
		}
		else
		{
			cheaksize(p);
			printf("请问您要插入什么数据？\n");
			scanf("%d", &(*p)->data[(*p)->size]);
			(*p)->size++;
		}
}
//查找数据
void Datsearch(Datach*p)
{
	int num = -1;
	int pos = -1;
	printf("请问您要查找？\n");
	scanf("%d", &num);
	pos = findbynum(p,num);
	if (pos == -1)
	{
		printf("未找到您要查找的数据\n");
	}
	else
	{
		printf("%-3d-> %-3d\n", pos + 1, p->data[pos]);
	}
}
//修改数据
void Datmodify(Datach*p)
{
	int num = -1;
	int pos = -1;
	printf("请问您要修改？\n");
	scanf("%d", &num);
	pos = findbynum(p,num);
	if (pos == -1)
	{
		printf("您要修改的数据不存在\n");
	}
	else
	{
		printf("您要修改为多少？\n");
		scanf("%d", &p->data[pos]);
		printf("修改成功\n");
	}
}
//排序数据
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
	printf("*****1.从大到小 2.从小到大*****\n");
	printf("*******************************\n");
	printf("请选择:>");
	while (1)
	{
		scanf("%d", &input);
		if (input != 1 && input != 2)
		{
			printf("无此选项请重新输入:>");
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
