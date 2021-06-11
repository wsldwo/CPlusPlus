#include <iostream>
using namespace std;
struct item
{
	int weight;
	int value;
}ITEMS[105];
int N,T;
long long DP[105][1005];//DP[i][j]��ʾ��ǰi����Ʒ��װ����Ϊj�ı������ܻ�õ�����ֵ 
/*
NICE��һ��ͨ�����������⣬�ƺ����Ƕ�άDP����һά��ʾǰi����Ʒ���ڶ�ά��ʾ�������� 
*/
void cal()
{
	for(int i = 1;i <= T;i++)
	{
		for(int j = 1;j <= N;j++)
		{
			DP[i][j] = DP[i - 1][j];//��ʼ������i����Ʒ�����뱳���� 
			//�����Ҫ�����i����Ʒ�����з���1����2����...
			int limit = j / ITEMS[i].weight;
			for(int k = 1;k <= limit;k++)
			{
				long long temp = DP[i][j - ITEMS[i].weight * k] + ITEMS[i].value * k;
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
	cout<<DP[T][N]<<endl;
	return 0;
}
