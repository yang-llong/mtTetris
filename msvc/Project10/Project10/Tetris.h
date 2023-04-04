#include<iostream>
#include<string>
#include<cstdlib>
#include<windows.h>
#include<ctime>
#include<conio.h>
#include<cstdio>
using namespace std;

class Tetris
{
private:
	int rank;
	int score;
	int id;
	int point[2];
	int top;
	double clock;

public:
	Tetris();
	void DrawMap();
	void SetColor(int);
	void Dra(int,int,int);
	void Run();
	void ReDraw(int,int,int);
	void Judge(int,int,int);
	void Turn(int);
	void Update();
	void Pause();
	void Input_score();
	void Welcome();
};


const int sharp[19][8]={
	//条形
{0,0,1,0,2,0,3,0},{0,0,0,1,0,2,0,3},     
//方块
{0,0,1,0,0,1,1,1},  
//L形
{0,0,1,0,1,1,1,2},{0,1,1,1,2,0,2,1},{0,0,0,1,0,2,1,2},{0,0,0,1,1,0,2,0},
//J形
{1,0,1,1,1,2,0,2},{0,0,0,1,1,1,2,1},{0,0,0,1,0,2,1,0},{0,0,1,0,2,0,2,1},
//T形
{1,0,0,1,1,1,2,1},{1,0,1,1,1,2,0,1},{0,0,1,0,2,0,1,1},{0,0,0,1,0,2,1,1},
//S形
{1,0,2,0,1,1,0,1},{0,0,0,1,1,1,1,2},
//Z形
{0,0,1,0,1,1,2,1},{1,0,1,1,0,1,0,2}
};

const int high[19]={ 4,1,2,2,3,2,3,2,3,2,3,2,3,2,3,2,3,2,3 };

int map[28][16]{};

#define a1 0
#define a2 1

#define b 2

#define c1 3
#define c2 4
#define c3 5 
#define c4 6

#define d1 7
#define d2 8
#define d3 9
#define d4 10

#define e1 11
#define e2 12
#define e3 13
#define e4 14

#define f1 15
#define f2 16

#define g1 17
#define g2 18







