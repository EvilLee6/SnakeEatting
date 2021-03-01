#include "CSnake.h"

CSnake::CSnake(int x, int y, int length, Directions direction, int speed, char pic)
{
	m_iHeadX = x;
	m_iHeadY = y;
	m_iLength = length;
	m_enumCurrentDirection = direction;
	m_iSpeed = speed;
	m_cPic = pic;
	for (int i = 0;i < m_iLength;i++) //创建蛇头和蛇身
	{
		CUnit point(0, 0, '@');
		m_vecBody.push_back(point);
		switch (m_enumCurrentDirection)
		{
		case UP:
			m_vecBody[i].m_x = m_iHeadX;
			m_vecBody[i].m_y = m_iHeadY + i;
			break;
		case DOWN:
			m_vecBody[i].m_x = m_iHeadX;
			m_vecBody[i].m_y = m_iHeadY - i;
			break;
		case LEFT:
			m_vecBody[i].m_x = m_iHeadX + i;
			m_vecBody[i].m_y = m_iHeadY;
			break;
		case RIGHT:
			m_vecBody[i].m_x = m_iHeadX - i;
			m_vecBody[i].m_y = m_iHeadY;
			break;
		default:
			break;
		}
	}
}

CSnake::~CSnake()
{

}

void CSnake::changeDirection(int vkValue)
{
	switch (vkValue) {
	case 'w':
	case 'W':
		if (m_enumCurrentDirection != DOWN)  //防止缩头
			m_enumCurrentDirection = UP;
		break;
	case 's':
	case 'S':
		if (m_enumCurrentDirection != UP)
			m_enumCurrentDirection = DOWN;
		break;
	case 'a':
	case 'A':
		if (m_enumCurrentDirection != RIGHT)
			m_enumCurrentDirection = LEFT;
		break;
	case 'd':
	case 'D':
		if (m_enumCurrentDirection != LEFT)
			m_enumCurrentDirection = RIGHT;
		break;
	default:
		break;
	}

}

void CSnake::move()
{
	Sleep(m_iSpeed);
	eraseSnake();
	for (int i = m_iLength - 1;i > 0;i--) //蛇的前一节坐标赋给后一节
	{
		m_vecBody[i].m_x = m_vecBody[i - 1].m_x;
		m_vecBody[i].m_y = m_vecBody[i - 1].m_y;
	}
	switch (m_enumCurrentDirection)
	{
	case UP:
		m_vecBody[0].m_y--;
		break;
	case DOWN:
		m_vecBody[0].m_y++;
		break;
	case LEFT:
		m_vecBody[0].m_x--;
		break;
	case RIGHT:
		m_vecBody[0].m_x++;
		break;
	default:
		break;
	}
	showSnake();
}

bool CSnake::eatFood(Food* pFood)
{
	if (pFood->m_x == m_vecBody[0].m_x && pFood->m_y == m_vecBody[0].m_y) //如果蛇头的坐标和食物的坐标重合，说明吃到食物，将食物擦除重新显示
	{
		pFood->erase();
		pFood->createPos();
		return true;
	}
	else 
	{
		return false;
	}
}

void CSnake::showSnake()
{
	for (int i = 0;i < m_iLength;i++)
	{
		m_vecBody[i].show();
	}
}

void CSnake::eraseSnake()
{
	for (int i = 0;i < m_iLength;i++)
	{
		m_vecBody[i].erase();
	}
}

void CSnake::growUp()
{
	m_iLength++;
	CUnit point(0, 0, '@');
	m_vecBody.push_back(point);
}

bool CSnake::checkFailed()
{
	if ((m_vecBody[0].m_x == 0) || (m_vecBody[0].m_x == 99) || (m_vecBody[0].m_y == 0) || (m_vecBody[0].m_y == 24)) //检测边界
	{
		return true;
	}
	for (int i = 4; i < m_iLength; i++) //检测自身
	{
		if ((m_vecBody[i].m_x == m_vecBody[0].m_x) && (m_vecBody[i].m_y == m_vecBody[0].m_y))
		{
			return true;
		}
	}
	return false;
}