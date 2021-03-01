#include "Map.h"

Map::Map()
{
	m_iScore = 0;
	m_iLevel = 0;
}

Map::~Map()
{

}

void Map::drawGameArea()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (i == 0 || j == 0 || i == row - 1 || j == col - 1)
			{
				gameMap[i][j] = '#';
			}
			else
			{
				gameMap[i][j] = ' ';
			}
		}
	}
}

void Map::drawGameInfo()
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			cout << gameMap[i][j];
		}
		if (i == 4)
		{
			cout << " 版本：1.0";
		}
		if (i == 5)
		{
			cout << " 制作人：李雨哲";
		}
		if (i == 6)
		{
			cout << " a:向左";
		}
		if (i == 7)
		{
			cout << " d:向右";
		}
		if (i == 8)
		{
			cout << " w:向上";
		}
		if (i == 9)
		{
			cout << " s:向下";
		}
		if (i == 10)
		{
			cout << " 得分：" << m_iScore;
		}
		if (i == 11)
		{
			cout << " 关卡：" << m_iLevel;
		}
		cout << endl;
	}
}

void Map::scoreUp()
{
	m_iScore += 10;
	CUnit::gotoxy(107,10);
	cout << ' ';
	CUnit::gotoxy(107, 10);
	cout << m_iScore;
}

void Map::levelUp()
{
	m_iLevel++;
	CUnit::gotoxy(107, 11);
	cout << ' ';
	CUnit::gotoxy(107, 11);
	cout << m_iLevel;
}

void Map::gameOver()
{
	char k;
	CUnit::gotoxy(40, 10);
	cout << "游戏结束！最终得分：" << m_iScore;
}