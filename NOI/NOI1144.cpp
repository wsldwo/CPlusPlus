#include <iostream>
using namespace std;
int n,m,num_hit[1001];//num_hit:��¼ÿһ�����ĳ��ִ��� 
int hit,mn;//hit:�����ִ��� mn:���� 
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
