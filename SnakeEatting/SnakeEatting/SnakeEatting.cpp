#include <iostream>
#include "CUnit.h"
#include "Food.h"
#include "Map.h"
#include "CSnake.h"
#include "conio.h"
#include <Windows.h>
#pragma comment(lib,"WinMM.Lib")

using namespace std;

int main()
{
    PlaySound("F:\\KuGou\\Hawk Nelson - Sold Out.WAV", NULL, SND_FILENAME | SND_ASYNC); //插入背景音乐
    char key;
    CUnit::HideCursor(); //隐藏光标
    Map control;
    control.drawGameArea();
    control.drawGameInfo();
    Food food;
    food.createPos();
    CSnake snake;
	snake.showSnake();
    while (1)
    {
        while (!_kbhit()) //没有按键就继续循环
        {
            if (snake.checkFailed())
            {
                control.gameOver();
                return 0;
            }
            if (snake.eatFood(&food))
            {
                snake.growUp();
                control.scoreUp();
                control.levelUp();
                snake.m_iSpeed -= 20; //关卡增加，蛇的速度增加
            }
            //Sleep(snake.m_iSpeed);
            //snake.eraseSnake();
            snake.move();
            //snake.showSnake();
        }
        key = _getch(); //获取键盘输入的值
        snake.changeDirection(key);
    }
    return 0;
}
