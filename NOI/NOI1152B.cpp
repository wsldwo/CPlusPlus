#include <iostream>
using namespace std;
int N,MATRIX[305][305],ANS;

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
	//������� 
	for(int i = 0;i < N;i++)
	{
		int arr[305] = {};
		for(int j = i;j < N;j++)
		{//���  �ӵ�i�е���j�� 
			for(int k = 0;k < N;k++)
				arr[k] += MATRIX[j][k];//���+=���ˣ����ۼӼ�򵥵���������ˣ���������Ҫ����Ԥ�����������Լ� 
			int temp = e(arr,N); 
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
