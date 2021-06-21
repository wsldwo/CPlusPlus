#include <iostream> 
using namespace std;

char MAP[30][30];
char BLOCK[8] = {'\0','|','-','+','1','2','3','4'};
int R,C;
int M_X,M_Y,Z_X,Z_Y;
int START_X,START_Y;

enum direction
{
	up = 1,down = 2,left = 3,right = 4
}dire;
 
bool isBlock(char c)
{
	if(c != '.')
	return true;
	else
	return false;
}

bool test(int x , int y)//测试空白砖 
{
	for(int i = 1;i <= 7;i++)
	{
		MAP[x][y] = BLOCK[i];
		int j = START_X, k = START_Y;//j k 为当前砖块坐标
		int m = M_X, n = M_X;//m n 为上一块砖块坐标 
		while(j != Z_X || k != Z_Y)
		{
			if(MAP[m][n] == 'M')
			{
				//起点 
			}
			else if(MAP[j][k] == 'Z')
			{
				//终点 
			}
			else if(MAP[j][k] != '.')
			{
				//途中 
			}
		}
	}
	MAP[x][y] = '.';//还原 
	return false; 
}

int main()
{
	cin >> R >> C;
	for(int i = 1;i <= R;i++)
	{
		for(int j = 1;j <= C;j++)
		{
			cin >> MAP[i][j];
			if(MAP[i][j] == 'M')
			{
				M_X = i;
				M_Y = j;
			}
			if(MAP[i][j] == 'Z')
			{
				Z_X = i;
				Z_Y = j;
			}
		}
	}
	if(M_X - 1 >= 1 && isBlock(MAP[M_X - 1][M_Y]))//上方 
	{
		START_X = M_X - 1;
		START_Y = M_Y;
	}
	else if(M_X + 1 <= R && isBlock(MAP[M_X + 1][M_Y]))//下方 
	{
		START_X = M_X + 1;
		START_Y = M_Y;
	}
	else if(M_Y - 1 >= 1 && isBlock(MAP[M_X][M_Y - 1]))//左方 
	{
		START_X = M_X;
		START_Y = M_Y - 1;
	}
	else if(M_Y + 1 <= C && isBlock(MAP[M_X][M_Y + 1]))//右方 
	{
		START_X = M_X;
		START_Y = M_Y + 1;
	}
	if(START_X == 0 && START_Y == 0)//没有第一块砖 
	{
		//答案锁定在M的上下左右四块砖 
	}
	else
	{
		//答案位于断掉的空白砖 
	}
	/*
	for(int i = 1;i <= R;i++)
	{
		for(int j = 1;j <= C;j++)
		{
			cout << MAP[i][j] << " ";
		}
		cout << endl;
	}
	*/
	return 0;
}
