#pragma once
#include "Windows.h"
#include <iostream>

using namespace std;

class CUnit
{
public:
	int m_x;
	int m_y;
	char m_cPic;
public:
	CUnit(int x = 0, int y = 0, char pic = '#');
	virtual ~CUnit();
	void show(); //չʾ��
	void erase(); //������
	static void gotoxy(int x, int y); //��λ���
	static void HideCursor(); //���ع��
};

