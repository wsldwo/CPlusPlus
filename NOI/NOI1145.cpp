#include <iostream>
using namespace std;
int LEVEL[1005][1005];
int DP[1005][1005];
int R;
int max(int a,int b)
{
	return a > b ? a : b;
}
//�ݹ鷨 ���������� �� �ٶ��� �� ����Ҫ����ռ� 
int f(int x,int y)//xΪ��  yΪ�� 
{
	if(x > R)return 0;
	return LEVEL[x][y] + max(f(x + 1,y),f(x + 1,y + 1));
}
//������ ���������� �� �ٶȿ� ����Ҫ����ռ� 
int f2()
{
	for(int i = 1;i <= R;i++)//��ʼ�����һ�� 
	DP[R][i] = LEVEL[R][i];
	for(int i = R - 1;i >= 1;i--)
	{
		for(int j = 1;j <= i;j++)
		{
			DP[i][j] = LEVEL[i][j] + max(DP[i + 1][j],DP[i + 1][j + 1]);
		}
	}
	return DP[1][1];
} 
int main()
{
	cin >> R;
	for(int i = 1;i <= R;i++)
	{
		for(int j = 1;j <= i;j++)
		cin >> LEVEL[i][j];
	}
	//cout << f(1,1) << endl;
	cout << f2() << endl;
	return 0;
} 
