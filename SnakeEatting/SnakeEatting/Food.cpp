#include "Food.h"

Food::Food(int x,int y,char pic)
{
	m_cPic = pic;
}

Food::~Food()
{

}

void Food::createPos()
{
	srand((unsigned)time(0));
	m_x =(rand() % (98)) + 1;
	m_y =(rand() % (23)) + 1;
	show();
}