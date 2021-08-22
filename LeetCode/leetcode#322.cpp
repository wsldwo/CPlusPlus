#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <unordered_set>
using namespace std;
//coins:硬币数组 amount:剩余金额 c_index:硬币索引 count:当前已使用硬币数量 ans:本题答案
void coinChange(vector<vector<int>>& vi, vector<int>& coins, int amount, int c_index, int count, int& ans)
{
	if (amount == 0)
	{
		ans = min(ans, count);
		return;
	}
	if (c_index == coins.size()) return;
	if (vi[amount][c_index] <= count) return;

	for (int k = amount / coins[c_index]; k >= 0 && k + count < ans; k--)//硬币从大到小，数量从多到少，进行枚举
	{
		int nextAmount = amount - k * coins[c_index];
		coinChange(vi, coins, nextAmount, c_index + 1, count + k, ans);
	}
	vi[amount][c_index] = min(vi[amount][c_index], count);
}

int coinChange_dfs(vector<int>& coins, int amount)
{
	if (amount == 0) return 0;
	sort(coins.rbegin(), coins.rend());
	int ans = INT_MAX;
	vector<vector<int>> vi = vector<vector<int>>(amount + 1, vector<int>(coins.size(), INT_MAX));
	coinChange(vi, coins, amount, 0, 0, ans);
	return ans == INT_MAX ? -1 : ans;
}


int coinChange_bfs(vector<int>& coins, int amount)
{
	int least_coins = 0;
	sort(coins.begin(), coins.end());
	deque <int> q;
	unordered_set <int> s;//记录已入队节点
	if (amount > 0)
		q.push_back(amount);
	while (!q.empty())
	{
		least_coins += 1;
		for (int i = q.size(); i > 0; i--)
		{
			int node = q.front();
			q.pop_front();
			for (int j = 0; j < coins.size(); j++)
			{
				if (coins[j] == node)
				{
					return least_coins;
				}
				else if (coins[j] < node)
				{
					if (s.find(node - coins[j]) == s.end()) //避免重复访问  s.count(node - coins[j]) == 0
					{
						q.push_back(node - coins[j]);
						s.insert(node - coins[j]);
					}
				}
				else
					break;
			}
		}
	}
	return amount == 0 ? 0 : -1;
}

int coinChange_dp(vector<int>& coins, int amount)
{
	sort(coins.begin(), coins.end());
	vector<int> dp(10005, 9999999); //dp[i] 表示金额i对应的最少数量
	dp[0] = 0;
	for (int i = 1; i <= amount; i++)
	{
		for (int j = 0; j < coins.size(); j++)
		{
			if (coins[j] <= i)
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			else break;
		}
	}
	return dp[amount] == 9999999 ? -1 : dp[amount];
}

int main()
{
	vector<int> coins{411, 412, 413, 414, 415, 416, 417, 418, 419, 420, 421, 422};
	cout << coinChange_dfs(coins, 9864) << endl;
	return 0;
}
