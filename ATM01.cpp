// ATM01.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
long float m = 1000; 
int language()
{
	printf("=======================\n");
	printf("|     1.����          |\n");
	printf("|     2.English       |\n");
	printf("|     3.�˳�\\Exit     |\n");
	printf("=======================\n");
	return _getch();
	
}
void mainmenu1()
{
	printf("=======================\n");
	printf("|     1.��ѯ          |\n");
	printf("|     2.��Ǯ          |\n");
	printf("|     3.ȡǮ          |\n");
	printf("|     4.�˳�          |\n");
	printf("=======================\n");
}
void mainmenu2()
{
	system("cls");
	printf("=======================\n");
	printf("|     1.Query         |\n");
	printf("|     2.Deposit       |\n");
	printf("|     3.Withdraw      |\n");
	printf("|     4.Exit          |\n");
	printf("=======================\n");
}

void query1()
{
	system("cls");
	printf("=======================\n");
	printf("���˻��� ��%.2lf Ԫ.\n", m);
	printf("�밴���������         \n");
	printf("=======================\n");
	_getch();
	system("cls");

}
void query2()
{
	system("cls");
	printf("=========================================\n");
	printf("This account balance is �� %.2lf .\n", m);
	printf("Press any key to continue\n");
	printf("=========================================\n");
	_getch();
	system("cls");

}
void deposit1()
{
	system("cls");
	float a;
	printf("=======================\n");
	printf("��������Ҫ�����Ŀ�� �� ");
	scanf_s("%f", &a);
	m = m + a;
	printf("�밴���������\n");
	printf("=======================\n");
	_getch();
	system("cls");
}
void deposit2()
{
	system("cls");
	long float a;
	printf("================================================\n");
	printf("Please enter the amount you want to save�� �� ");
	scanf_s("%lf", &a);
	m = m + a;
	printf("Press any key to continue\n");
	printf("================================================\n");
	_getch();
	system("cls");
}
void withdraw1()
{
	system("cls");
	long float a;
	printf("=======================\n");
	printf("��������Ҫȡ����Ŀ�� �� ");
	scanf_s("%lf",&a);
	while (a>m)
	{
		printf("���㣬����������������룡");
		_getch();
		system("cls");
		printf("=======================\n");
		printf("��������Ҫȡ����Ŀ�� �� ");
		scanf_s("%lf", &a);
	}
	m = m - a;
	printf("�밴���������\n");
	printf("=======================\n");
	_getch();
	system("cls");
}
void withdraw2()
{
	system("cls");
	long float a;
	printf("=====================================================\n");
	printf("Please enter the amount you want to withdraw���� ");
	scanf_s("%lf", &a);
	while (a >= 0)
	{

	}
	while (a>m)
	{
		printf("Lack of balance, press any key to enter the amount��");
		_getch();
		system("cls");
		printf("=====================================================\n");
		printf("Please enter the amount you want to withdraw���� ");
		scanf_s("%lf", &a);
	}
	m = m - a;
	printf("Press any key to continue\n\n");
	_getch();
	system("cls");
}
void main()
{
	int bExit = 0; int in; char n = language();
	if (n == '1')
	{
		system("cls");
		while (!bExit)
		{
			mainmenu1();
			in = _getch();
			switch (in)
			{
			case '1':
				query1(); break;
			case '2':
				deposit1(); break;
			case'3':
				withdraw1(); break;
			case '4':
				bExit = 1; break;
			default:
				system("cls");
				break;
			}
		}
	}
	if (n == '2')
	{
		system("cls");
		while (!bExit)
		{
			mainmenu2();
			in = _getch();
			switch (in)
			{
			case '1':
				query2(); break;
			case '2':
				deposit2(); break;
			case'3':
				withdraw2(); break;
			case '4':
				bExit = 1; break;
			default:
				system("cls");
				break;
			}
		}
	}
}


