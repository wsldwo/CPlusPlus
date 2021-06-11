#include <iostream>
#define LEN 10
using namespace std;

int N,SOLU = 0;
int board[LEN + 1][LEN + 1];

void dfs(int x,int y)
{
	if(x == 0 && y == N - 1)//x为行 y为列 
	{
		SOLU += 1;
	}
	else
	{
		//方向1 左上
		if(x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1] == 0)
		{
			board[x - 1][y - 1] = 1;
			dfs(x - 1,y - 1);
			board[x - 1][y - 1] = 0;
		}
		//方向2 上
		if(x - 1 >= 0 && board[x - 1][y] == 0)
		{
			board[x - 1][y] = 1;
			dfs(x - 1,y);
			board[x - 1][y] = 0;
		}
		//方向3 右上
		if(x - 1 >= 0 && y + 1 < N && board[x - 1][y + 1] == 0)
		{
			board[x - 1][y + 1] = 1;
			dfs(x - 1,y + 1);
			board[x - 1][y + 1] = 0;
		}
		//方向4 右
		if(y + 1 < N && board[x][y + 1] == 0)
		{
			board[x][y + 1] = 1;
			dfs(x,y + 1);
			board[x][y + 1] = 0;
		}
		//方向5 右下
		if(x + 1 < N && y + 1 < N && board[x + 1][y + 1] == 0)
		{
			board[x + 1][y + 1] = 1;
			dfs(x + 1,y + 1);
			board[x + 1][y + 1] = 0;
		}
		//方向6 下
		if(x + 1 < N && board[x + 1][y] == 0)
		{
			board[x + 1][y] = 1;
			dfs(x + 1,y);
			board[x + 1][y] = 0;
		}
		//方向7 左下
		if(x + 1 < N && y - 1 >= 0 && board[x + 1][y - 1] == 0)
		{
			board[x + 1][y - 1] = 1;
			dfs(x + 1,y - 1);
			board[x + 1][y - 1] = 0;
		}
		//方向8 左
		if(y - 1 >= 0 && board[x][y - 1] == 0)
		{
			board[x][y - 1] = 1;
			dfs(x,y - 1);
			board[x][y - 1] = 0;
		} 
		
	}
}



int main()
{
	cin>>N;
	for(int i = 0;i < N;i++)
	{
		for(int j = 0;j < N;j++)
		{
			cin>>board[i][j];
		}
	}
	board[0][0] = 1;
	dfs(0,0);
	cout<<SOLU<<endl;
	return 0;
}
