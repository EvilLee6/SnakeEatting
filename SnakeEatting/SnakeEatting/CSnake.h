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
	int m_iLength; //�ߵĳ���
	int m_iHeadX; //��ͷX����
	int m_iHeadY; //��ͷY����
	int m_iSpeed; //�н��ٶ�
	int m_cPic; //�����ʾ
	Directions m_enumCurrentDirection; //�н�����
	vector<CUnit> m_vecBody; //��������
public:
	CSnake(int x = 40, int y = 10, int length = 4, Directions direction = RIGHT, int speed = 200, char pic = '@');
	~CSnake();
	void changeDirection(int vkValue); //�ı䷽��WASD
	void move(); //���ƶ�����
	bool eatFood(Food* pFood); //�ж����Ƿ�Ե���ʳ��
	void showSnake(); //չʾ��
	void eraseSnake(); //������
	void growUp(); // ������
	bool checkFailed(); //������Ƿ�����
};

