#include "CUnit.h"

CUnit::CUnit(int x, int y, char pic)
{
	m_x = x;
	m_y = y;
	m_cPic = pic;
}

CUnit::~CUnit()
{

}

void CUnit::show()
{
	gotoxy(m_x,m_y);
	cout << m_cPic << endl;
}

void CUnit::erase()
{
	gotoxy(m_x, m_y);
	cout << ' ' << endl;
}

void CUnit::gotoxy(int x, int y) //将光标移动到x，y位置
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;    // position 是一个 COORD 结构
	position.X = x; //设置列在屏幕中心附近
	position.Y = y; //设置行在屏幕中心附近
	//将光标放在那里
	SetConsoleCursorPosition(screen, position);
}

void CUnit::HideCursor() //隐藏光标
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}