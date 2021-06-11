#include <iostream>
using namespace std;
struct item
{
	int weight;
	int value;
}ITEMS[105];
int N,T;
long long DP[105][1005];

void cal()
{
	/*
	DP[i][j]:用前i件物品装入容量为j的背包，所能取得的最大价值 
	*/
	for(int i = 1;i <= T;i++)
	{
		for(int j = 1;j <= N;j++)
		{
			DP[i][j] = DP[i - 1][j];//初始化，第i件物品不放入背包
			if(j >= ITEMS[i].weight)//如果把第i件物品放入背包
			{
				long long temp = DP[i - 1][j - ITEMS[i].weight] + ITEMS[i].value;
				if(temp > DP[i][j])
				DP[i][j] = temp; 
			}
		}
	}
}

int main()
{
	cin >> N >> T;
	for(int i = 1;i <= T;i++)
	cin >> ITEMS[i].weight >> ITEMS[i].value;
	cal();
	cout << DP[T][N] << endl; 
	return 0;
} 
