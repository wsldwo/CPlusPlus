#include <iostream>
#define LEN 20
using namespace std;
int N,M,SOLU = 0,FRAME[LEN + 1][LEN + 1];//全局数组自动初始化 

void dfs(int x,int y)
{
	if(x < N)
	{
		//走左边
		if(FRAME[x + 1][y] == 0 || x + 1 == N)//小花招，如果最后一层是陷阱，也可以走，算做通关 
		dfs(x + 1,y); 
		//走右边
		if(FRAME[x + 1][y + 1] == 0 || x + 1 == N)//小花招，如果最后一层是陷阱，也可以走，算做通关 
		dfs(x + 1,y + 1);
	}
	else
	SOLU += 1;
}

int main()
{
	cin>>N>>M;
	int x,y;
	for(int i = 0; i < M; i++)
	{
		cin>>x>>y;
		FRAME[x][y] = 1;//第x行的第y个“交叉”点是“陷阱”。
	}
	dfs(1,1);
	cout<<SOLU; 
	return 0;
}
