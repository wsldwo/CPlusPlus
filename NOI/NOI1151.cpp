#include <iostream>
using namespace std;
int N,MAXSUM,NUM[1000005],DP[1000005];//题目说了 1≤n≤100000，测试样例结果给我整个735003个数据 
void f()
{
	DP[N - 1] = NUM[N - 1];
	MAXSUM = DP[N - 1];
	for(int i = N - 2;i >= 0;i--)
	{
		DP[i] = DP[i + 1] > 0 ? NUM[i] + DP[i + 1] : NUM[i];
		if(DP[i] > MAXSUM)
		MAXSUM = DP[i];
	}
}
int main()
{
	cin >> N;
	for(int i = 0;i < N;i++)
	cin >> NUM[i];
	f();
	cout << MAXSUM << endl;
	return 0;
} 
