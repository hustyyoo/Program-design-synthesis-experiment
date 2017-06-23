#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "conio.h"
#define LEN sizeof(struct stu)

struct stu
{
	char ID[5];
	char name[5];
	int score;
	struct stu *next;
};
int n;
struct stu *paixu(struct stu *h, struct stu *p)
{
	struct stu *p0, *p1, *p2;
	p0 = 0;
	p1 = p;
	p2 = h->next;
	if (p2 == 0)
	{
		h->next = p1;p1->next = 0;
	}
	else
	{
		printf("==1=====\n");
		if (atoi(p1->ID)<atoi(p2->ID))
		{
			h->next = p1;p1->next = p2;
		}
		else
		{
			while (atoi(p1->ID) >= atoi(p2->ID))
			{
				printf("==2=====\n");
				p0 = p2; p2 = p2->next;
				if (p2 == 0)
					break;
			}
			p1->next = p2;
			p0->next = p1;
		}
	}
	n++;
	return (h);
}
struct stu *add(struct stu *h)
{
	struct stu  *p1;
	p1 = (struct stu *)malloc(LEN);
	printf("����ѧ����Ϣ��\n");
	while (1)
	{
		printf("ѧ�ţ�");
		scanf("%s", p1->ID);
		if (strlen(p1->ID) != 4)
			printf("����Ƿ���ѧ�ű�����4λ�����������룡\n");
		else
			break;
	}
	printf("������");
	scanf("%s", p1->name); 
	printf("�ɼ���");
	scanf("%d", &p1->score); 
	printf("�밴���������\n");
	_getch();
	return (paixu(h, p1));
}
void chaxun(struct stu *h)
{
	struct stu *p;
	p = h->next;
	char a[5];
	int fl = 1;
	printf("����ѧ��ѧ�ţ�\n");
	while (fl)
	{
		printf("ѧ�ţ�");
		scanf("%s", &a);
		if (strlen(a) == 4)
		{
			if (strcmp(p->ID, a) == 0)
			{
				while (p!=0)
				{
					printf("ѧ��Ϊ%s��ѧ����Ϣ��������%s����������%d��\n", p->ID, p->name, p->score);
					p = p->next;
				}
			}
			else
				printf("û���ҵ���ѧ������ȷ��ѧ�������Ƿ���ȷ��");

			fl = 0;
		}
		else
			printf("����Ƿ���ѧ�ű�����4λ�����������룡\n");
	}
}
void edit(struct stu *h)
{
	struct stu *p;
	p = h->next;
	int fl = 1;
	printf("����ѧ��ѧ�ţ�\n");
	while (fl)
	{
		printf("ѧ�ţ�");
		char a[5];
		scanf("%s", &a);
		if (strlen(a) == 4)
		{
			if (strcmp(p->ID, a) == 0)
			{
				
				while ((p->ID) != a)
					p = p->next;
				printf("ѧ��Ϊ%s��ѧ����Ϣ��������%s����������%d��", p->ID, p->name, p->score);
			}
			else
				printf("û���ҵ�ѧ����Ϣ��");
			fl = 0;
		}
		else
			printf("����Ƿ���ѧ�ű�����4λ�����������룡");
	}
}
void delect(struct stu *h)
{

}
void print(struct stu *h)
{
	struct stu *p;
	p = h->next;
	int i = 0;
	printf("����ѧ����Ϣ��\n");
	while (p!=0)
	{
		i++;
		printf("%d,ѧ�ţ�%s��������%s���ɼ���%d\n", i, p->ID, p->name, p->score);
		p = p->next;
	}
}
void sum()
{
	printf("ѧ��������%d\n", n);
}
void mm()
{
	printf("========================\n");
	printf("|	1. ���ѧ��		|\n");
	printf("|	2. ��ѯѧ��		|\n");
	printf("|	3. �༭ѧ��		|\n");
	printf("|	4. ɾ��ѧ��		|\n");
	printf("|	5. ��ӡȫ��		|\n");
	printf("|	6. ������		|\n");
	printf("|	7. �˳�ϵͳ		|\n");
	printf("========================\n");
}
void main()
{
	printf("Hello World!\n");
	struct stu *h;
	h = (struct stu *)malloc(LEN);
	h->next = 0;
	int Ex = 1;
	while (Ex)
	{
		mm();
		switch (_getch())
		{
		case '1':
			h = add(h); break;
		case '2':
			chaxun(h); break;
		case '3':
			edit(h); break;
		case '5':
			print(h); break;
		case '6':
			sum(); break;
		case '7':
			Ex = 0; break;
		}
	}

}

