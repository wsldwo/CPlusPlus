#include <iostream>
#define DATA_LENGTH 10
using namespace std;
int STATION[DATA_LENGTH + 1][DATA_LENGTH];
int N,M,SOLU = 0;//NΪ�����  MΪ���� 
//���ݷ� 
//no:�˵ı�Ŵ�1��ʼ 
void dfs(int no)
{
	if(no <= M)
	{
		//ÿ�η����һ����
		for(int i = 1;i <= N;i++)
		{
			//���� 
			int amount = 0;//���� 
			while(STATION[i][amount]!=0)
			amount++;
			//��ǰ�������amount��
			//���뷽���� amount + 1 �� 
			//���ݵ�ǰ���� 
			int temp[DATA_LENGTH];
			for(int j = 0;j < DATA_LENGTH;j++)
			temp[j] = STATION[i][j];
			
			for(int j = 0;j <= amount;j++)//jΪ����λ�� 
			{
				//���� 
				for(int k = DATA_LENGTH - 2;k >= j;k--)
				{
					//���ݺ��� 
					STATION[i][k + 1] = STATION[i][k];
				}
				STATION[i][j] = no;
				//���� 
				dfs(no + 1);
				//��ԭ 
				for(int j = 0;j < DATA_LENGTH;j++)
				STATION[i][j] = temp[j];
			} 
		} 
	}
	else
	{
		SOLU += 1;
		cout<<"����"<<SOLU<<":"<<endl; 
		//��ӡ���
		for(int i = 1;i <= N;i++)
		{
			if(STATION[i][0] != 0)
			{
				cout<<"���"<<i<<":";
				int j = 0;
				while(STATION[i][j] != 0)
				{
					cout<<STATION[i][j]<<"�� "; 
					j++;
				}
				cout<<endl;
			}
		} 
	}
}
//��̬�滮��
//dp[i][j] = dp[i - 1][j] * (i - 1 + j)
long long cal()
{
	long long dp[DATA_LENGTH + 1][DATA_LENGTH + 1];
	for(int i = 1;i <= M;i++)
	{
		for(int j = 1;j <= N;j++)
		{
			if(i == 1)
			dp[i][j] = j;
			else
			dp[i][j] = dp[i - 1][j] * (i - 1 + j);
		}
	}
	return dp[M][N];
}

long long cal2(int m,int n)
{
	if(m == 1)
	return n;
	else
	return cal2(m - 1,n) * (m - 1 + n);
}

int main()
{
	cin>>N>>M;
	//dfs(1);
	//cout<<"cal:"<<cal()<<endl;
	cout<<cal2(M,N);
	return 0;
} 
