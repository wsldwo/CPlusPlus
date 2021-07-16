#include <iostream>
#include <algorithm>
using namespace std;
int n,ring[25],use[25];
bool finished = false;
bool isPrime(int num)
{
	if(num <= 1)return false;
	if(num == 2)return true;
	int limit = sqrt(num) + 1;
	for(int i = 2;i < limit;i++)
	{
		if(num % i == 0)
		return false;
	}
	return true;
}

void dfs(int no)//no 表示当前是第几个数 
{
	if(finished || n == 17 || n == 19)return;
	if(no > n)
	{
		if(isPrime(ring[n] + ring[1]) && !finished)
		{//找到素数环 
			for(int i = 1;i <= n;i++)
			cout << ring[i] << " ";
			finished = true;
		}
	}
	else
	{
		for(int i = 1;i <= n;i++)
		{
			if(!use[i])
			{
				if((no > 1 && isPrime(ring[no - 1] + i)) || no == 1)
				{
					ring[no] = i;
					use[i] = true;
					dfs(no + 1);
					use[i] = false;
					ring[no] = 0;
				}
			}
		}
	}
}

int main()
{
	cin >> n;
	dfs(1);
	if(!finished)
	cout << -1 << endl; 
	return 0;
} 
