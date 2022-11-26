#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME 20
#define MAX_SEX 5
#define MAX_ADDR 30





//�ṹ�嶨��
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



//��������
//��ʼ������
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
//�������ʱ�ռ�Ļ���
void endprog(elmch **);
//��ĩβ�������
void Datadd(elmch ** h);
//��ʾ����
void Datshow(elmch* h);
//ɾ������
void Datdel(elmch**h);
//��������
void Datsearch(elmch **h);
//�޸�����
void Datmodify(elmch**h);
//��������
void Datinsert(elmch**h);