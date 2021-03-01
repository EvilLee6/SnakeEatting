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
		row = 25, //����
		col = 100 //����
	};
	char gameMap[row][col];
	int m_iScore; //�÷�
	int m_iLevel; //�ؿ�
public:
	Map();
	~Map();
	void drawGameArea(); //��ʼ����ͼ
	void drawGameInfo(); //��ʾ��ͼ
	void scoreUp(); //��������
	void levelUp(); //�ؿ�����
	void gameOver(); //��Ϸ��������
};

