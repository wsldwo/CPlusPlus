#include <iostream>
#define DATA_LENGTH 10
using namespace std;
int STATION[DATA_LENGTH + 1][DATA_LENGTH];
int N,M,SOLU = 0;//N为入口数  M为人数 
//回溯法 
//no:人的编号从1开始 
void dfs(int no)
{
	if(no <= M)
	{
		//每次分配好一个人
		for(int i = 1;i <= N;i++)
		{
			//更改 
			int amount = 0;//人数 
			while(STATION[i][amount]!=0)
			amount++;
			//当前入口已有amount人
			//插入方法有 amount + 1 种 
			//备份当前数组 
			int temp[DATA_LENGTH];
			for(int j = 0;j < DATA_LENGTH;j++)
			temp[j] = STATION[i][j];
			
			for(int j = 0;j <= amount;j++)//j为插入位置 
			{
				//更改 
				for(int k = DATA_LENGTH - 2;k >= j;k--)
				{
					//数据后移 
					STATION[i][k + 1] = STATION[i][k];
				}
				STATION[i][j] = no;
				//回溯 
				dfs(no + 1);
				//还原 
				for(int j = 0;j < DATA_LENGTH;j++)
				STATION[i][j] = temp[j];
			} 
		} 
	}
	else
	{
		SOLU += 1;
		cout<<"方案"<<SOLU<<":"<<endl; 
		//打印结果
		for(int i = 1;i <= N;i++)
		{
			if(STATION[i][0] != 0)
			{
				cout<<"入口"<<i<<":";
				int j = 0;
				while(STATION[i][j] != 0)
				{
					cout<<STATION[i][j]<<"号 "; 
					j++;
				}
				cout<<endl;
			}
		} 
	}
}
//动态规划法
//dp[i][j] = dp[i - 1][j] * (i - 1 + j)
long long cal()
{
	long long dp[DATA_LENGTH + 1][DATA_LENGTH + 1];
	for(int i = 1;i <= M;i++)
	{
		for(int j = 1;j <= N;j++)
		{
			if(i == 1)
			dp[i][j] = j;
			else
			dp[i][j] = dp[i - 1][j] * (i - 1 + j);
		}
	}
	return dp[M][N];
}

long long cal2(int m,int n)
{
	if(m == 1)
	return n;
	else
	return cal2(m - 1,n) * (m - 1 + n);
}

int main()
{
	cin>>N>>M;
	//dfs(1);
	//cout<<"cal:"<<cal()<<endl;
	cout<<cal2(M,N);
	return 0;
} 
