#include <iostream>
using namespace std;
struct box
{
	int x,y,z;//长宽高
} boxes[105];
int n;//箱子数目
long long dp[105];//dp[i] 表示前i个盒子可以达到的最大高度
//dp[i] = max(dp[i - 1] + 将boxes[i]进行插入, 以boxes[i]为起点的最大高度) 
void cal(int n)
{
	if(n == 1)
	{
		//x y z
		int h1 = z;
		//x z y
		int h2 = y;
		//y z x
		int h3 = x;
	}
} 
int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++)
	cin>>boxes[i].x>>boxes[i].y>>boxes[i].z;

	return 0;
}
