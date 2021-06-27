#include <iostream>
using namespace std;
int n,m,num_hit[1001];//num_hit:记录每一个数的出现次数 
int hit,mn;//hit:最大出现次数 mn:众数 
int main()
{
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		cin >> m;
		num_hit[m] += 1;
		if(num_hit[m] > hit || (num_hit[m] == hit && m < mn))
		{
			hit = num_hit[m];
			mn = m; 
		} 
	}
	cout << mn << endl;
	return 0;
} 
