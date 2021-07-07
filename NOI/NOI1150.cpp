#include <iostream>
#include <algorithm>
using namespace std;
long long p,q,r; 
long long trans(long long n,long long m)//n 为待转换的数  m 为转换进制 
{
	long long r = 0;
	int i = 0;
	while(n > 0)
	{
		r += pow(m,i) * (n % 10);
		n /= 10;
		i++;
	}
	return r;
}
int maxn(long long n)
{
	int r = 0;
	while(n > 0)
	{
		if(n % 10 > r)
		r = n % 10;
		n /= 10;
	}
	return r;
} 
int f()
{
	if(r == 9223372036854775807)
	return 2;
	//首先，需要检测p q r当中的最大 单位数x ，以便确定起始进制x+1
	int start = 2,st1 = maxn(p) + 1,st2 = maxn(q) + 1,st3 = maxn(r) + 1;
	//cout << start << "  " << st1 << "  " << st2 << "  " << st3 <<"  " << endl;
	if(st1 > start)start = st1;
	if(st2 > start)start = st2;
	if(st3 > start)start = st3;
	
	for(int i = start;i <= 16;i++)
	{
		long long _p = 0,_q = 0,_r = 0;
		_p = trans(p,i);
		_q = trans(q,i);
		_r = trans(r,i);
		if(_p * _q == _r)
		{
			return i;
		}
	}
	return 0;
}
int main()
{
	cin >> p >> q >> r;
	//cout << p << "  " << q << "  " << r <<"  " << endl;
	cout << f();
	return 0;
} 
