#include <iostream>
#include <algorithm> 
using namespace std;
bool finished = false;
int solu[30];
bool isPrime(int num)
{
	int end = (int)sqrt(num) + 1;//�����ж��Ż� 
	for(int i = 2; i < end; i++)
	{
		if(num % i == 0)
			return false;
	}
	return true;
}
/*
���ݷ�����ʽ�ֽ�
start:��ǰ�ֽ����
n:ʣ��ֵ
pos:��ǰ�ֽ���������㿪ʼ
*/
void dfs(int start,int n,int pos)
{
	if(finished)
		return;
	if(n > 1)//�����ֽ�
	{
		//·��0 
		if(isPrime(n))
		{
			solu[pos] = n;
			dfs(n,n / n,pos + 1);
			if(finished)
				return;
			solu[pos] = 0;
		}
		//·��1������ʹ��start�ֽ�
		if(n % start == 0)
		{
			solu[pos] = start;
			dfs(start,n / start,pos + 1);
			if(finished)
				return; 
			solu[pos] = 0;
		}
		//·��2����Ѱ��һ����������
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
	else if(n == 1)//�ֽ����
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
