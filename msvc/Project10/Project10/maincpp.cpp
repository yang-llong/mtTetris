#include<iostream>
#include<string>
#include<cstdlib>
#include<windows.h>
#include<ctime>
#include<conio.h>
#include<cstdio>
#include "Tetris.h"

int main()
{
	Tetris game;
	game.Welocme();
	system("cls");				//�����ӭ����
	game.DrawMap();
	game.Run();
}
