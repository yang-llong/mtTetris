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
	system("cls");				//Çå³ý»¶Ó­½çÃæ
	game.DrawMap();
	game.Run();
}
