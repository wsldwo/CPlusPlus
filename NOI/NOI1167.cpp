#include <iostream>
#define LEN 10
using namespace std;

int N,SOLU = 0;
int board[LEN + 1][LEN + 1];

void dfs(int x,int y)
{
	if(x == 0 && y == N - 1)//xΪ�� yΪ�� 
	{
		SOLU += 1;
	}
	else
	{
		//����1 ����
		if(x - 1 >= 0 && y - 1 >= 0 && board[x - 1][y - 1] == 0)
		{
			board[x - 1][y - 1] = 1;
			dfs(x - 1,y - 1);
			board[x - 1][y - 1] = 0;
		}
		//����2 ��
		if(x - 1 >= 0 && board[x - 1][y] == 0)
		{
			board[x - 1][y] = 1;
			dfs(x - 1,y);
			board[x - 1][y] = 0;
		}
		//����3 ����
		if(x - 1 >= 0 && y + 1 < N && board[x - 1][y + 1] == 0)
		{
			board[x - 1][y + 1] = 1;
			dfs(x - 1,y + 1);
			board[x - 1][y + 1] = 0;
		}
		//����4 ��
		if(y + 1 < N && board[x][y + 1] == 0)
		{
			board[x][y + 1] = 1;
			dfs(x,y + 1);
			board[x][y + 1] = 0;
		}
		//����5 ����
		if(x + 1 < N && y + 1 < N && board[x + 1][y + 1] == 0)
		{
			board[x + 1][y + 1] = 1;
			dfs(x + 1,y + 1);
			board[x + 1][y + 1] = 0;
		}
		//����6 ��
		if(x + 1 < N && board[x + 1][y] == 0)
		{
			board[x + 1][y] = 1;
			dfs(x + 1,y);
			board[x + 1][y] = 0;
		}
		//����7 ����
		if(x + 1 < N && y - 1 >= 0 && board[x + 1][y - 1] == 0)
		{
			board[x + 1][y - 1] = 1;
			dfs(x + 1,y - 1);
			board[x + 1][y - 1] = 0;
		}
		//����8 ��
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
