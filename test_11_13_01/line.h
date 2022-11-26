#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_ADDR 30





//结构体定义
typedef struct elm
{
	char name[MAX_NAME];
	char sex[MAX_SEX];
	int age;
	char addr[MAX_ADDR];
}elm;

typedef struct elmch
{
	struct elmch * next;
	elm date;
}elmch;



//函数声明
//初始化函数
void Datinit(elmch** h);

enum
{
	quit,
	add,
	del,
	search,
	modify,
	sort,
	insert,
	show
};
//程序结束时空间的回收
void endprog(elmch **);
//在末尾添加数据
void Datadd(elmch ** h);
//显示数据
void Datshow(elmch* h);
//删除数据
void Datdel(elmch**h);
//查找数据
void Datsearch(elmch **h);
//修改数据
void Datmodify(elmch**h);
//插入数据
void Datinsert(elmch**h);