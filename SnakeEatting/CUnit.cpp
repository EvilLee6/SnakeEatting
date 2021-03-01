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

void CUnit::gotoxy(int x, int y) //������ƶ���x��yλ��
{
	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD position;    // position ��һ�� COORD �ṹ
	position.X = x; //����������Ļ���ĸ���
	position.Y = y; //����������Ļ���ĸ���
	//������������
	SetConsoleCursorPosition(screen, position);
}

void CUnit::HideCursor() //���ع��
{
	CONSOLE_CURSOR_INFO cursor_info = { 1, 0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}