#include <iostream>
using namespace std;
int d,n,value,count,map[1030][1030],dp[1030][1030];//dp为当前点到左上角的价值总值 
void cal()
{
	//第一步，数据预处理。
	dp[0][0] = map[0][0];
	for(int i = 1; i < 1025; i++)
	{
		dp[0][i] = dp[0][i - 1] + map[0][i];
		dp[i][0] = dp[i - 1][0] + map[i][0];
	}
	for(int i = 1; i < 1025; i++)
		for(int j = 1; j < 1025; j++)
		{
			dp[i][j] = dp[i - 1][j] + dp[i][j - 1] + map[i][j] - dp[i - 1][j - 1];
		}
	//第二步，找到价值最大点 
	int left = 0,top = 0,right = 1024,bottom = 1024,v = 0;
	for(int i = 0; i < 1025; i++)
	{
		for(int j = 0; j < 1025; j++)
		{//穷举炸弹投放点(i,j)
			left = j - d < 0 ? 0 : j - d;
			right = j + d > 1024 ? 1024 : j + d;
			top = i - d < 0 ? 0 : i - d;
			bottom = i + d > 1024 ? 1024 : i + d;
			if(left > 0 && top > 0)v = dp[bottom][right] - dp[top - 1][right] - dp[bottom][left - 1] + dp[top - 1][left - 1];
			else if(left == 0 && top > 0)v = dp[bottom][right] - dp[top - 1][right];
			else if(left > 0 && top == 0)v = dp[bottom][right] - dp[bottom][left - 1];
			else v = dp[bottom][right];
			if(v > value)
			{
				value = v;
				count = 1;
			}
			else if(v == value)
			count += 1;
		}	
	}
	cout << count << " " << value << endl;
}
int main()
{
	cin >> d >> n;
	int x,y;
	for(int i = 0; i < n; i++)
	{
		cin >> x >> y;
		cin >> map[x][y];
	}
	cal();
	return 0;
}
