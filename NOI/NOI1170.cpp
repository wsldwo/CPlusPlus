#include <iostream>
#include <algorithm> 
using namespace std;
bool finished = false;
int solu[30];
bool isPrime(int num)
{
	int end = (int)sqrt(num) + 1;//素数判断优化 
	for(int i = 2; i < end; i++)
	{
		if(num % i == 0)
			return false;
	}
	return true;
}
/*
回溯法，因式分解
start:当前分解起点
n:剩余值
pos:当前分解次数，从零开始
*/
void dfs(int start,int n,int pos)
{
	if(finished)
		return;
	if(n > 1)//继续分解
	{
		//路线0 
		if(isPrime(n))
		{
			solu[pos] = n;
			dfs(n,n / n,pos + 1);
			if(finished)
				return;
			solu[pos] = 0;
		}
		//路线1，继续使用start分解
		if(n % start == 0)
		{
			solu[pos] = start;
			dfs(start,n / start,pos + 1);
			if(finished)
				return; 
			solu[pos] = 0;
		}
		//路线2，找寻下一个质数因子
		for(int i = start + 1; i <= n; i++)
		{
			if(isPrime(i) && n % i == 0)
			{
				solu[pos] = i;
				dfs(i,n / i,pos + 1);
				if(finished)
					return; 
				solu[pos] = 0;
			}
		}
	}
	else if(n == 1)//分解完成
	{
		for(int i = 0; i < pos - 1; i++)
			cout<<solu[i]<<"*";
		cout<<solu[pos - 1]<<endl;
		finished = true;
	}
}
int main()
{
	int N;
	cin>>N;
	dfs(2,N,0);
	return 0;
}
