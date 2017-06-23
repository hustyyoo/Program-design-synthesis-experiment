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
	printf("输入学生信息：\n");
	while (1)
	{
		printf("学号：");
		scanf("%s", p1->ID);
		if (strlen(p1->ID) != 4)
			printf("输入非法：学号必须是4位，请重新输入！\n");
		else
			break;
	}
	printf("姓名：");
	scanf("%s", p1->name); 
	printf("成绩：");
	scanf("%d", &p1->score); 
	printf("请按任意键继续\n");
	_getch();
	return (paixu(h, p1));
}
void chaxun(struct stu *h)
{
	struct stu *p;
	p = h->next;
	char a[5];
	int fl = 1;
	printf("输入学生学号：\n");
	while (fl)
	{
		printf("学号：");
		scanf("%s", &a);
		if (strlen(a) == 4)
		{
			if (strcmp(p->ID, a) == 0)
			{
				while (p!=0)
				{
					printf("学号为%s的学生信息：姓名（%s），分数（%d）\n", p->ID, p->name, p->score);
					p = p->next;
				}
			}
			else
				printf("没有找到该学生，请确认学号输入是否正确！");

			fl = 0;
		}
		else
			printf("输入非法：学号必须是4位，请重新输入！\n");
	}
}
void edit(struct stu *h)
{
	struct stu *p;
	p = h->next;
	int fl = 1;
	printf("输入学生学号：\n");
	while (fl)
	{
		printf("学号：");
		char a[5];
		scanf("%s", &a);
		if (strlen(a) == 4)
		{
			if (strcmp(p->ID, a) == 0)
			{
				
				while ((p->ID) != a)
					p = p->next;
				printf("学号为%s的学生信息：姓名（%s），分数（%d）", p->ID, p->name, p->score);
			}
			else
				printf("没有找到学生信息！");
			fl = 0;
		}
		else
			printf("输入非法：学号必须是4位，请重新输入！");
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
	printf("所有学生信息：\n");
	while (p!=0)
	{
		i++;
		printf("%d,学号：%s，姓名：%s，成绩：%d\n", i, p->ID, p->name, p->score);
		p = p->next;
	}
}
void sum()
{
	printf("学生人数：%d\n", n);
}
void mm()
{
	printf("========================\n");
	printf("|	1. 添加学生		|\n");
	printf("|	2. 查询学生		|\n");
	printf("|	3. 编辑学生		|\n");
	printf("|	4. 删除学生		|\n");
	printf("|	5. 打印全部		|\n");
	printf("|	6. 总人数		|\n");
	printf("|	7. 退出系统		|\n");
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

