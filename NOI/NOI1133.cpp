#include <iostream>
#include <algorithm>
using namespace std;
int n,k,color[100005],dp[100005],ans;
void f()
{
	//≥ı ºªØdp[1]
	for(int i = 1,k1 = k; i <= n; i++)
	{
		if(color[i] == 0 && k1 == 0)break;
		if(color[i] == 0 && k1 > 0)dp[1] += 1,k1 -= 1;
		if(color[i] == 1)dp[1] += 1;
	}
	ans = dp[1];
	//cout << "dp[1]:" << dp[1] << endl;
	for(int i = 2; i <= n; i++)
	{
		if(color[i - 1] == 1)
			dp[i] = dp[i - 1] - 1;
		else if(color[i - 1] == 0)
		{
			dp[i] = (dp[i - 1] - 1) < 0 ? 0 : dp[i - 1] - 1;
			for(int j = (i - 1 + dp[i - 1]) < i ? i : (i - 1 + dp[i - 1]),k1 = k > 0 ? 1 : 0; j <= n; j++)
			{
				if(color[j] == 0 && k1 == 0)break;
				if(color[j] == 0 && k1 > 0)dp[i] += 1,k1 -= 1;
				if(color[j] == 1)dp[i] += 1;
			}
		}
		//cout << "dp[" << i << "]:" << dp[i] << endl;
		if(dp[i] > ans)ans = dp[i];
	}
	cout << ans << endl;
}
int main()
{
	cin >> n >> k;
	for(int i = 1; i <= n; i++)
		cin >> color[i];
	f();
	return 0;
}
