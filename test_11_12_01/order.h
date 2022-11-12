//去除警报
#define _CRT_SECURE_NO_WARNINGS
//头文件
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//宏
#define INITMAX 10

//枚举常量
enum
{
	quit,
	add,
	del,
	insert,
	search,
	modify,
	show,
	sort
};


//结构体定义
typedef struct Datach
{
	int size;
	int maxsize;
	int data[];

}Datach;

//函数声明
//初始化
void InitData(Datach ** p);
//菜单
void menu();
//添加数据
void Datadd(Datach ** p);
//展示数据
void Datshow(Datach * p);
//删除数据
void Datdel(Datach**p);
//插入数据
void Datinsert(Datach**p);
//查找数据
void Datsearch(Datach*p);
//修改数据
void Datmodify(Datach*p);
//排序数据
void Datsort(Datach*p);