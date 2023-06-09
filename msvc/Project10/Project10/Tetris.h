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
	void Draw(int,int,int);
	void Run();
	void ReDraw(int,int,int);
	bool Judge(int,int,int);
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

Tetris::Tetris(){
	point[0] = 0;
	point[1] = 5;
	score = 0;
	top = 25;
	clock = 0;
}

void Tetris::Turn(int num){
	switch(num)
	{
		case a1: id = a2;break;
		case a2: id = a1;break;

		case b: break;

		case c1: id = c2;break;
		case c2: id = c3;break;
		case c3: id = c4;break;
		case c4: id = c1;break;

		case d1: id = d2;break;
		case d2: id = d3;break;
		case d3: id = d4;break;
		case d4: id = d1;break;

		case e1: id = e2;break;
		case e2: id = e3;break;
		case e3: id = e4;break;
		case e4: id = e1;break;

		case f1: id = f2;break;
		case f2: id = f1;break;

		case g1: id = g2;break;
		case g2: id = g1;break;
	}
}

void SetPos(int i, int j){
	COORD pos = {i, j};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Tetris::Pause(){
	SetPos(32, 10);
	cout << "游戏暂停！" << endl;
	SetPos(30,11);
	cout << "你的分数为" << endl;
	char temp;
	while(1){
		while(1){
			if(_kbhit()){
				temp=_getch();
				break;
			}
		}
		if(temp==32)
			break;
	}

	SetPos(32, 10);
	cout << "      ";
	SetPos(30,11);
	cout << "      ";
}

void Tetris::Update()
{
	int i, flag;
	int nx, ny;
	for(i=0;i<4;i++)
	{
		nx = point[0]+sharp[id][i*2];
		ny =point[1]+sharp[id][i*2+1];
		SetPos((ny+1)*2, nx+1);
		SetColor(0);
		cout << "■";
		map[nx][ny] = 1;
	}

	if(point[0]<top)
	{
		top = point[0];
	}

	int j;

	for(i=point[0];i<point[0]+high[id];++i){
		flag = 1;

		for(j=0;j<13;++j)
		{
			if(map[i][j]==0){
				flag = 0;
				break;
			}
		}

		if(flag==1){
			clock = 0;

			SetColor(0);
			for(int tt=i;tt>=top;--tt){
				for(int t=0;t<13;++t){
					map[tt][t]=map[tt-1][t];
					if (map[tt][t]) {
						cout << "■";
					}
					else {
						cout << "  ";
					}
				}
			}
			++point[0];
			--top;

			score += 10;
			Input_score();
		}
	}

	if(clock>=1000){
		clock = 0;
		
		int tmp;
		for(int i = top;i<=24;++i){
			for(int j=0;j<13;++j){
				tmp = map[i-1][j]=map[i][j];
				SetPos((j+1)*2,i);
				if(tmp==1){
					cout << "■";
				}
				else
					cout << "    ";
			}

		}
 
		bool f = true;
		int i;
		do{
			for(i=0;i<13;++i){
				if((map[24][i]=rand()%2)==0)
					f = false;
			}
		}while(f);

		SetPos(2,25);
		for(i=0;i<13;++i){
			if(map[24][i]==1)
				cout << "■";
			else
				cout << "  ";
		}
	}

}


void Tetris::Input_score()
{
	SetColor(3);
	SetPos(30,19);
	cout << "得分：" << score;
}

void Tetris::Welcome()
{
	SetColor(1);
	char x;
	while(1)
	{
		system("cls:");
		cout << "■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "		俄罗斯方块		" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "		操作方式：" << endl;
		cout << "		↑ - 旋转" << endl;
		cout << "		↓ - 加速下移" << endl;
		cout << "		← - 左移" << endl;
		cout << "		→ - 右移" << endl;
		cout << "		空格 - 暂停" << endl;
		cout << "■■■■■■■■■■■■■■■■■■■■■" << endl;
		cout << "■ 按1—3选择难度■" << endl;
		SetPos(20,10);
		x = getchar();
		if(x<='9' && x>= '0')
		{
			rank = x-'0';
			break;
		}
	}
}


void Tetris::SetColor(int color_num)
{
	int n;
	switch(color_num)
	{
		case 0: n = 0x08;break;
		case 1: n = 0x0C;break;
		case 2: n = 0x0D;break;
		case 3: n = 0x0E;break;
		case 4: n = 0x0A;break;
	} 
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), n);
}


void Tetris::DrawMap()
{
	int i;
	SetColor(0);

	for(i=0;i<24;i++){
		SetPos(i*2, 0);
		cout << "■";
		SetPos(i*2, 26);
		cout << "■";
	}

	for(i=0;i<26;i++)
	{
		SetPos(0, i);
		cout << "■";
		SetPos(28, i);
		cout << "■";
		SetPos(46, i);
		cout << "■";
	}

	for(i=14;i<24;i++)
	{
		SetPos(i*2, 16);
		cout << "■";
	}

	SetColor(3);
	Input_score();
	SetPos(30, 21);
	cout << "难度登记：" << rank;
	SetPos(32, 2);
	cout << "下一图形";
}

void Tetris::Draw(int x, int y, int num)
{
	int nx, ny;
	for(int i=0;i<4;i++)
	{
		nx = x+sharp[num][2*i];
		ny = y+sharp[num][2*i+1];
		SetPos((ny+1)*2, nx+1);
		SetColor(i+1);
		cout << "■";
	}
}

void Tetris::ReDraw(int x, int y, int num)
{
	int nx, ny;

	for (int i=0;i<4;i++)
	{
		nx = x+sharp[num][2*i];
		ny = y+sharp[num][2*i+1];
		SetPos((ny+1)*2, nx+1);
		cout << "  ";
	}
}

bool Tetris::Judge(int x, int y, int num)
{
	int nx, ny;
	for(int i=0;i<4;i++)
	{
		nx = x+sharp[num][2*i];
		ny = y+sharp[num][2*i+1];
		if(!(nx<25 && nx>=0 && ny<13 && ny>=0 && !map[nx][ny]))
			return true;
	}
	return false;
}

void Tetris::Run()
{
	int next_id;
	srand((int)time(0));

	id = rand()%19;
	next_id = rand()%19;

	Draw(point[0],point[1],id);
	Draw(5, 16, next_id);

	int count;
	if(rank==1)
		count = 150;
	else if(rank==2)
		count = 100;
	else if(rank==3)
		count = 50;
	else
		count = 5;
	int i = 0;

	while(i)
	{
		if(!(i<count))
		{
			i = 0;
			if(Judge(point[0]+1, point[1], id))
			{
				Update();
				id = next_id;

				ReDraw(5, 16, next_id);
				next_id = rand()%19;

				point[0] = 0; point[1] = 5;
				Draw(point[0], point[1], id);
				Draw(5, 16, next_id);

				if (Judge(point[0], point[1], id))
				{
					system("cls");
					SetPos(20, 10);
					cout << "游戏结束！" << endl;
					SetPos(20, 11);
					cout << "你的分数为 " << score << endl;
					system("pause");
					exit(1);
				}
			}
			else{
				ReDraw(point[0], point[1], id);
				point[0]++;
				Draw(point[0], point[1], id);
			}
		}

		if(_kbhit())
		{
			int key, key2;
			key = _getch();
			if(key == 224)
			{
				key2 = _getch();
				if(key2 == 72)
				{
					int temp = id;
					Turn(id);
					if(Judge(point[0], point[1], id))
						id = temp;
					ReDraw(point[0], point[1], temp);
					Draw(point[0], point[1], id);
				}
				if(key2 == 80)
				{
					if(!Judge(point[0]+2, point[1], id))
					{
						ReDraw(point[0], point[1], id);
						point[0] += 2;
						Draw(point[0], point[1], id);
					}
				}
				else if(key2 == 75)
				{
					if(!Judge(point[0], point[1]-1, id))
					{
						ReDraw(point[0], point[1], id);
						point[1]--;
						Draw(point[0], point[1], id);
					}
				}
				else if(key2 == 77)
				{
					if(!Judge(point[0], point[1]+1, id))
					{
						ReDraw(point[0], point[1], id);
						point[1]++;
						Draw(point[0], point[1], id);
					}
				}

			}
			else if(key==32)
				Pause();
		}
		Sleep(1);
		i++;
		++clock;
	}
}


