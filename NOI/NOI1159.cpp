#include <iostream>
using namespace std;
struct item
{
	int weight;
	int value;
}ITEMS[105];
int N,T;
long long DP[105][1005];

void cal()
{
	/*
	DP[i][j]:��ǰi����Ʒװ������Ϊj�ı���������ȡ�õ�����ֵ 
	*/
	for(int i = 1;i <= T;i++)
	{
		for(int j = 1;j <= N;j++)
		{
			DP[i][j] = DP[i - 1][j];//��ʼ������i����Ʒ�����뱳��
			if(j >= ITEMS[i].weight)//����ѵ�i����Ʒ���뱳��
			{
				long long temp = DP[i - 1][j - ITEMS[i].weight] + ITEMS[i].value;
				if(temp > DP[i][j])
				DP[i][j] = temp; 
			}
		}
	}
}

int main()
{
	cin >> N >> T;
	for(int i = 1;i <= T;i++)
	cin >> ITEMS[i].weight >> ITEMS[i].value;
	cal();
	cout << DP[T][N] << endl; 
	return 0;
} 
