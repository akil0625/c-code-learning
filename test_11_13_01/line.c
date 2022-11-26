#define _CRT_SECURE_NO_WARNINGS

#include "line.h"
extern int size;
//line.c内部函数声明
elmch* findbypos(elmch*h, int * pos);
elmch* findbyname(elmch*h, int * pos);
elmch* findbyage(elmch*h, int * pos);
elmch* findbyaddr(elmch*h, int * pos);

//函数定义
//初始化数据
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
//程序结束时空间的回收
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
//查找数据(找到后返回前一个数据的地址和位次(传址形式))*返回值为NULL时表明该数据未找到*
//查找数据类型选择
elmch * Datfind(elmch**h, int * pos)
{
	if ((*h) == NULL)
	{
		printf("无数据\n");
		return NULL;
	}
	int input;
	elmch* p = NULL;
	printf("**************************************\n");
	printf("******    1.位数      2.姓名    ******\n");
	printf("******    3.年龄      4.地址    ******\n");
	printf("**************************************\n");
	printf("请问您要按什么找到该数据:\n");
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
//按位数
elmch* findbypos(elmch*h,int * pos)
{
	int i = 0;
	int ipos = 0;
	printf("请输入位数:\n");
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
//按姓名
elmch* findbyname(elmch*h, int * pos)
{
	int i = 0;
	char iname[MAX_NAME] = {0};
	printf("请输入姓名:\n");
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
//按年龄
elmch* findbyage(elmch*h, int * pos)
{
	int i = 0;
	int iage = 0;
	printf("请输入年龄:\n");
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
//按地址
elmch* findbyaddr(elmch*h, int * pos)
{
	int i = 0;
	char iaddr[MAX_ADDR] = { 0 };
	printf("请输入地址:\n");
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
//删除数据
void datdel(elmch* p)
{
	if (p == NULL)
	{
		printf("您要删除的数据不存在\n");
		return;
	}
	else
	{
		elmch * tmp = NULL;
		tmp = p->next->next;
		free(p->next);
		p->next = tmp;
		printf("删除成功\n");
	}
}


//在末尾添加数据
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
		printf("请输入对方姓名:\n");
		scanf("%s", &p->next->date.name);
		printf("请输入对方性别:\n");
		scanf("%s", &p->next->date.sex);
		printf("请输入对方年龄:\n");
		scanf("%d", &p->next->date.age);
		printf("请输入对方地址:\n");
		scanf("%s", &p->next->date.addr);
		p->next->next = NULL;
	}
	printf("录入信息成功\n");
	size++;
}
//显示数据
void Datshow(elmch* h)
{
	int i = 0;
	elmch* p = h;
	printf("%-5s\t%-20s\t%-5s\t%-5s\t%-30s\n","位数", "姓名","性别", "年龄", "地址" );
	while (p->next != NULL)
	{
		p = p->next;
		i++;
		printf("%d->\t%-20s\t%-5s\t%-5d\t%-30s\n", i, p->date.name, p->date.sex, p->date.age, p->date.addr);
	}
}
//删除数据
void Datdel(elmch**h)
{
	elmch* p = NULL;
	int pos = 0;
	p = Datfind(h, &pos);
	datdel(p);
	size--;
}
//查找数据
void Datsearch(elmch **h)
{
	elmch* p = NULL;
	int pos = 0;
	p = Datfind(h, &pos);
	if (p == NULL)
	{
		printf("该数据不存在\n");
		return;
	}
	printf("%-5s\t%-20s\t%-5s\t%-5s\t%-30s\n", "位数", "姓名", "性别", "年龄", "地址");
	printf("%d->\t%-20s\t%-5s\t%-5d\t%-30s\n", pos+1, p->next->date.name, p->next->date.sex, p->next->date.age, p->next->date.addr);
}
//修改数据
void Datmodify(elmch**h)
{
	elmch* p = NULL;
	int pos = 0;
	p = Datfind(h, &pos);
	if (p == NULL)
	{
		printf("该数据不存在\n");
		return;
	}
	printf("请输入对方姓名:\n");
	scanf("%s", &p->next->date.name);
	printf("请输入对方性别:\n");
	scanf("%s", &p->next->date.sex);
	printf("请输入对方年龄:\n");
	scanf("%d", &p->next->date.age);
	printf("请输入对方地址:\n");
	scanf("%s", &p->next->date.addr);
	printf("信息修改成功\n");
}
//插入数据
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
			printf("请输入对方姓名:\n");
			scanf("%s", &p->next->date.name);
			printf("请输入对方性别:\n");
			scanf("%s", &p->next->date.sex);
			printf("请输入对方年龄:\n");
			scanf("%d", &p->next->date.age);
			printf("请输入对方地址:\n");
			scanf("%s", &p->next->date.addr);
			printf("信息修改成功\n");

		}

	}
	else if (pos - size == 1)
	{
		Datadd(h);
	}
	else
	{
		printf("该位置无数据存在\n");
		return;
	}
	printf("插入成功\n");
	size++;
}

