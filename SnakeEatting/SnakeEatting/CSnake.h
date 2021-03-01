#pragma once
#include "Food.h"

using namespace std;

typedef enum
{
	UP,
	DOWN,
	LEFT,
	RIGHT
}Directions;

class CSnake
{
public:
	int m_iLength; //蛇的长度
	int m_iHeadX; //蛇头X坐标
	int m_iHeadY; //蛇头Y坐标
	int m_iSpeed; //行进速度
	int m_cPic; //蛇身表示
	Directions m_enumCurrentDirection; //行进方向
	vector<CUnit> m_vecBody; //蛇身数组
public:
	CSnake(int x = 40, int y = 10, int length = 4, Directions direction = RIGHT, int speed = 200, char pic = '@');
	~CSnake();
	void changeDirection(int vkValue); //改变方向WASD
	void move(); //蛇移动函数
	bool eatFood(Food* pFood); //判断蛇是否吃到了食物
	void showSnake(); //展示蛇
	void eraseSnake(); //擦除蛇
	void growUp(); // 蛇增长
	bool checkFailed(); //检测蛇是否死亡
};

