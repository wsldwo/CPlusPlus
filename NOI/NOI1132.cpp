#include <iostream>
#include <algorithm>
using namespace std;
long long n,m,tc[100005],ans;
/*
二分法，枚举所画时间 
*/
void f(long long l,long long r)
{
	if(l <= r)
	{
		long long middle = (l + r) / 2,pc = 0;
		for(int i = 1; i <= n; i++)
		{
			pc += middle / tc[i];
			if(middle < tc[i])
				break;
		}
		if(pc >= m)
		{
			f(l,middle - 1);
			if(middle < ans)
				ans = middle;
		}
		else 
			f(middle + 1,r);
	}
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
		cin >> tc[i];
	sort(tc + 1,tc + 1 + n);
	ans = tc[n] * m;
	f(1,tc[n] * m);
	cout << ans << endl;
	return 0;
}
