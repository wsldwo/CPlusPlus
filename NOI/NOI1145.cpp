#include <iostream>
using namespace std;
int LEVEL[1005][1005];
int DP[1005][1005];
int R;
int max(int a,int b)
{
	return a > b ? a : b;
}
//递归法 ，从上往下 ， 速度慢 ， 不需要额外空间 
int f(int x,int y)//x为行  y为列 
{
	if(x > R)return 0;
	return LEVEL[x][y] + max(f(x + 1,y),f(x + 1,y + 1));
}
//迭代法 ，从下往上 ， 速度快 ，需要额外空间 
int f2()
{
	for(int i = 1;i <= R;i++)//初始化最底一行 
	DP[R][i] = LEVEL[R][i];
	for(int i = R - 1;i >= 1;i--)
	{
		for(int j = 1;j <= i;j++)
		{
			DP[i][j] = LEVEL[i][j] + max(DP[i + 1][j],DP[i + 1][j + 1]);
		}
	}
	return DP[1][1];
} 
int main()
{
	cin >> R;
	for(int i = 1;i <= R;i++)
	{
		for(int j = 1;j <= i;j++)
		cin >> LEVEL[i][j];
	}
	//cout << f(1,1) << endl;
	cout << f2() << endl;
	return 0;
} 
