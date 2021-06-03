#include <iostream>
#include <cstring>
#define DATA_LENGTH 12
using namespace std;
int N,ANS = 0,NUMBER[DATA_LENGTH + 1],QUEUE[DATA_LENGTH + 1],ANSWER[DATA_LENGTH + 1];
//NUMBER记录数字是否被使用
//记录排列
//回溯法
//no:已入队的数字数量
void dfs(int no)
{
	if(no < N)
	{
		/*
		剪枝优化：把数字1始终放到第一个位置，则回溯从数字2开始 
		妙啊，实在是妙啊！
		*/
		for(int i = 2; i <= N; i++)
		{
			if(NUMBER[i] == 0)
			{
				NUMBER[i] = 1;
				QUEUE[no] = i;
				dfs(no + 1);
				NUMBER[i] = 0;
				QUEUE[no] = 0;
			}
		}
	}
	else
	{
		int temp = 0;
		QUEUE[N] = QUEUE[0];
		/*
		for(int i = 0;i < N;i++)
		{
			cout<<QUEUE[i]<<" ";
		}
		cout<<endl;
		*/
		for(int i = 0; i < N; i++)
		{
			temp += (QUEUE[i] - QUEUE[i + 1]) * (QUEUE[i] - QUEUE[i + 1]);
		}
		QUEUE[N] = 0;
		if(temp > ANS)
		{
			ANS = temp;
			
			for(int i = 0; i < N; i++)
			{
				ANSWER[i] = QUEUE[i];
			}
			
		}
	}
}

int main()
{
	cin>>N;
	memset(NUMBER,0,sizeof(NUMBER));//数组清零
	memset(QUEUE,0,sizeof(QUEUE));//数组清零
	memset(ANSWER,0,sizeof(ANSWER));//数组清零
	/*
	剪枝优化：把数字1始终放到第一个位置，则回溯从数字2开始 
	妙啊，实在是妙啊！ 
	*/
	NUMBER[1] = 1;
	QUEUE[0] = 1;
	dfs(1);
	
	for(int i = 0; i < N; i++)
	{
		cout<<ANSWER[i]<<" ";
	}
	cout<<endl;
	
	cout<<ANS;
	return 0;
}
