#include <iostream>
using namespace std;
int N,MATRIX[305][305],SUM[305][305],ANS;

int e(int arr[],int size)
{//����һ�����������������еĺ��� 
	 int dp[305] = {},val = 0;
	 //dp[i] ��ʾ��arr[0](��һ���ǿ�ͷ) �� arr[i](һ���ǽ�β) ��������������е�ֵ
	 dp[0] = arr[0];
	 val = dp[0];
	 for(int i = 1;i < size;i++)
	 {
	 	if(dp[i - 1] >= 0)
		 dp[i] = dp[i - 1] + arr[i];
		else
		 dp[i] = arr[i];
		if(dp[i] > val)
		val = dp[i];
	 }
	 return val;
}

int f()
{
	//����Ԥ����  DP[i][j] ��ʾ ��MATRIX[0][j]��MATRIX[i][j]���ۼ�ֵ
	for(int i = 0;i < N;i++)
	SUM[0][i] = MATRIX[0][i];
	for(int i = 0;i < N;i++)//�� 
	{
		for(int j = 1;j < N;j++)//��
		{
			SUM[j][i] = SUM[j - 1][i] + MATRIX[j][i];//��ĺ����״��� 
		} 
	}
	//������� 
	for(int i = 0;i < N;i++)
	{
		for(int j = i;j < N;j++)
		{//���  �ӵ�i�е���j�� 
			int arr[305] = {};
			for(int k = 0;k < N;k++)
				arr[k] = SUM[j][k] - SUM[i][k] + MATRIX[i][k];
			int temp = e(arr,N); 
			//int temp = sub_sum(arr,N); 
			if(temp > ANS)
			ANS = temp;
		}
	}
	return ANS;
}

int main()
{
	cin >> N;
	for(int i = 0;i < N;i++)
		for(int j = 0;j < N;j++)
			cin >> MATRIX[i][j];
	cout << f() << endl;
	return 0;
} 
