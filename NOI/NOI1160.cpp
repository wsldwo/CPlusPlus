#include <iostream>
using namespace std;
struct item
{
	int weight;
	int value;
}ITEMS[105];
int N,T;
long long DP[105][1005];//DP[i][j]表示用前i个物品填装容量为j的背包所能获得的最大价值 
/*
NICE！一次通过，背包问题，似乎都是二维DP，第一维表示前i个物品，第二维表示背包容量 
*/
void cal()
{
	for(int i = 1;i <= T;i++)
	{
		for(int j = 1;j <= N;j++)
		{
			DP[i][j] = DP[i - 1][j];//初始化，第i件物品不放入背包中 
			//如果需要放入第i件物品，则有放入1件、2件、...
			int limit = j / ITEMS[i].weight;
			for(int k = 1;k <= limit;k++)
			{
				long long temp = DP[i][j - ITEMS[i].weight * k] + ITEMS[i].value * k;
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
	cout<<DP[T][N]<<endl;
	return 0;
}
