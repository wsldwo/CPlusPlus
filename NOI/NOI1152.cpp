#include <iostream>
using namespace std;
int N,MATRIX[305][305],SUM[305][305],ANS;

int e(int arr[],int size)
{//这是一个求解最大连续子序列的函数 
	 int dp[305] = {},val = 0;
	 //dp[i] 表示从arr[0](不一定是开头) 到 arr[i](一定是结尾) 的最大连续子序列的值
	 dp[0] = arr[0];
	 val = dp[0];
	 for(int i = 1;i < size;i++)
	 {
	 	if(dp[i - 1] >= 0)
		 dp[i] = dp[i - 1] + arr[i];
		else
		 dp[i] = arr[i];
		if(dp[i] > val)
		val = dp[i];
	 }
	 return val;
}

int f()
{
	//数据预处理  DP[i][j] 表示 从MATRIX[0][j]到MATRIX[i][j]的累加值
	for(int i = 0;i < N;i++)
	SUM[0][i] = MATRIX[0][i];
	for(int i = 0;i < N;i++)//列 
	{
		for(int j = 1;j < N;j++)//行
		{
			SUM[j][i] = SUM[j - 1][i] + MATRIX[j][i];//真的很容易错！！ 
		} 
	}
	//问题求解 
	for(int i = 0;i < N;i++)
	{
		for(int j = i;j < N;j++)
		{//穷举  从第i行到第j行 
			int arr[305] = {};
			for(int k = 0;k < N;k++)
				arr[k] = SUM[j][k] - SUM[i][k] + MATRIX[i][k];
			int temp = e(arr,N); 
			//int temp = sub_sum(arr,N); 
			if(temp > ANS)
			ANS = temp;
		}
	}
	return ANS;
}

int main()
{
	cin >> N;
	for(int i = 0;i < N;i++)
		for(int j = 0;j < N;j++)
			cin >> MATRIX[i][j];
	cout << f() << endl;
	return 0;
} 
