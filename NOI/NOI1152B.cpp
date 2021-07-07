#include <iostream>
using namespace std;
int N,MATRIX[305][305],ANS;

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
	//问题求解 
	for(int i = 0;i < N;i++)
	{
		int arr[305] = {};
		for(int j = i;j < N;j++)
		{//穷举  从第i行到第j行 
			for(int k = 0;k < N;k++)
				arr[k] += MATRIX[j][k];//这个+=绝了，把累加简简单单就算出来了，根本不需要数据预处理，服了我自己 
			int temp = e(arr,N); 
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
