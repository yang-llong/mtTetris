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
    game.Welcome();
    system("cls");
    game.DrawMap();
    game.Run();
}
