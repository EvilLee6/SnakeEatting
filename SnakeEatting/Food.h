#pragma once
#include "CUnit.h"
#include "stdlib.h"
#include <vector>
#include <ctime>

class Food :public CUnit
{
public:
	Food(int x = 0, int y = 0, char pic = '$');
	virtual ~Food();
	void createPos(); //创建并显示食物
};

