#include <iostream>
#include <algorithm>
using namespace std;
/*
这个射击问题或许可以转化成为背包问题：
1、每件物品重量均为1，且数量无限。
2、背包容量为4，价值存在上限，超过上限变成0
背包问题：dp[i][j]从前i件物品中取若干件放入容量为j的背包中所能取得的最大价值
*/
/*
int n,m,s[1005],dp[1005][5],maxv;
void cal()
{
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= 4;j++)
		{
			dp[i][j] = dp[i - 1][j] > m ? 0 : dp[i - 1][j];//第i件物品不放入，初始化
			for(int k = 1,v = 0;k <= j;k++)//第i件物品如果放入，则最多放入j次
			{
				 v = dp[i - 1][j - k] + s[i] * k;
			     v = v > m ? 0 : v;
			     if(v > dp[i][j])dp[i][j] = v;
			}
			if(dp[i][j] > maxv)maxv = dp[i][j];
		}
	}
	cout << maxv << endl;
}
*/
/*
网上说这题存在后效性，所以不能用背包解法，暂时还没搞懂原因
网上的解题思路：射4次每次都可以在N个里面找一个，所以我们先将N个数任意2个相加的情况都求出来
1、先将N个数任意2个相加的情况都求出来；
2、然后我们排序一下去用一个指针去做：
3、一个从小到大枚举一个从大到小枚举
4、找一个2个数+2个数的最大的不超过M的组合
*/
int n,m,s[1005],h[1002021],ans;
void f()
{
	int k = 0;
	for(int i = 0; i <= n; i++)//任意两次射击成绩相加，包含可能的单枪成绩，故从0开始
	{
		for(int j = 0; j <= n; j++)
		{
			h[k] = s[i] + s[j];
			k++;
		}
	}
	sort(h,h + (n + 1) * (n + 1));//sort(start,start+size,compare)
	int i = 0,j = (n + 1) * (n + 1) - 1;
	while(i <= j)
	{
		if(h[i] + h[j] > m)j--;
		else
		{
			if(h[i] + h[j] > ans)
				ans = h[i] + h[j];
			i++;
		}
	}
	cout << ans << endl;
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> s[i];
	f();
	return 0;
}
