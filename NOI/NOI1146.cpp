#include <iostream>
using namespace std;
int N,MAX_LEN,SEQ[5005],DP[5005];
//DP[i]表示以A[i]为起点的，最长不下降子序列长度。 
int f()
{//从右向左计算DP 
	DP[N] = 1;
	for(int i = N - 1;i >= 1;i--)
	{
		DP[i] = 1;
		int maxlen = 0;
		for(int j = i + 1;j <= N;j++)
		{
			if(SEQ[j] >= SEQ[i] && DP[j] > maxlen)
			maxlen = DP[j];
		}
		DP[i] += maxlen;
		if(DP[i] > MAX_LEN)
		MAX_LEN = DP[i];
	}
	return MAX_LEN;
}
int main()
{
	cin >> N;
	for(int i = 1;i <= N;i++)
	cin >> SEQ[i];
	cout << f() << endl;
	return 0;
}
