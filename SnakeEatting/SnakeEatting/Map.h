#pragma once
#include "CSnake.h"

using namespace std;

class Map
{
public:
	/*static const int KLEFT;
	static const int KUP;
	static const int KWIDTH;
	static const int KHEIGHT;
	static const int KSCORE_OFFSET;
	static const int KLEVEL_OFFSET;*/
	enum
	{
		row = 25, //行数
		col = 100 //列数
	};
	char gameMap[row][col];
	int m_iScore; //得分
	int m_iLevel; //关卡
public:
	Map();
	~Map();
	void drawGameArea(); //初始化地图
	void drawGameInfo(); //显示地图
	void scoreUp(); //分数增加
	void levelUp(); //关卡增加
	void gameOver(); //游戏结束界面
};

