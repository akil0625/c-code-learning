//ȥ������
#define _CRT_SECURE_NO_WARNINGS
//ͷ�ļ�
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>

//��
#define INITMAX 10

//ö�ٳ���
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


//�ṹ�嶨��
typedef struct Datach
{
	int size;
	int maxsize;
	int data[];

}Datach;

//��������
//��ʼ��
void InitData(Datach ** p);
//�˵�
void menu();
//�������
void Datadd(Datach ** p);
//չʾ����
void Datshow(Datach * p);
//ɾ������
void Datdel(Datach**p);
//��������
void Datinsert(Datach**p);
//��������
void Datsearch(Datach*p);
//�޸�����
void Datmodify(Datach*p);
//��������
void Datsort(Datach*p);