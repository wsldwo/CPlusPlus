#include <iostream>
using namespace std;
int N,M,M_[2505];
long long DP[2505];
long long sumM_(int end)
{
	long long r = 0;
	for(int i = 1;i <= end;i++)
	r += M_[i];
	return r;
}
/*
动态规划法
DP[i] = min(DP[j] + M + DP[i - j])
DP[i]:表示把i头奶牛送到对岸所花最少时间 
终于摸到了一点门路，这是我独立做出来的一道动态规划题 
*/
long long cal()
{
	DP[1] = M + M_[1];
	for(int i = 2;i <= N;i++)
	{
		DP[i] = DP[i - 1] + M + DP[1];//初始化
		//cout<<"init DP"<<i<<":"<<DP[i]<<endl;
		for(int j = i - 2;j >= 1;j--)
		{
			long long temp = DP[j] + M + DP[i - j];
			//cout<<j<<" "<<i - j<<" "<<temp<<endl;
			if(temp < DP[i])
			DP[i] = temp;
		}
		long long t = M + sumM_(i);
		//cout<<"t:"<<t<<endl;
		if(t < DP[i])
		DP[i] = t;
		//cout<<"final DP"<<i<<":"<<DP[i]<<endl;
	}
	return DP[N];
}
int main()
{
	cin >> N >> M;
	for(int i = 1;i <= N;i++)
	cin >> M_[i];
	cout << cal() << endl;
	return 0;
} 
