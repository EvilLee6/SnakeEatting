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
	void show(); //展示点
	void erase(); //擦除点
	static void gotoxy(int x, int y); //定位光标
	static void HideCursor(); //隐藏光标
};

