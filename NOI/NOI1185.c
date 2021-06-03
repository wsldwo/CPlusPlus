#include <stdio.h>
/*
���ݷ�    ȱ�㣺�ֽ��������ʱ���ݹ�̫��������� 
*/
void dfs(int N,int len,int M,int *solu)
{
	if(N == 0 && len == M)
	*solu += 1;
	else if(N > 0 && len < M && N >= M - len)
	{
		for(int i = 1;i <= N - M + len + 1;i++)
		dfs(N - i,len + 1,M,solu); 
	}
}
/*
��̬�滮����
dp[i][j]:��i�ֽ�Ϊj���������ķ����� 
dp[N][M] = dp[n1][m1] * dp[N-n1][M-m1] + dp[n2][m2] * dp[N-n2][M-m2] + ......(�ֲ���ˡ��������)
*/
long long dyp(int N,int M)
{
	long long dp[51][51];
	//dp�����ʼ��
	for(int i = 1;i <= N;i++)
	{
		for(int j = 1;j <= M;j++)
		{
			if(j == 1 || j == i)
			dp[i][j] = 1;
			else if(i < j)
			dp[i][j] = 0;//�޽�
			else
			{
				dp[i][j] = 0;
				//���м���dp[i][j] 
				for(int k = 1;k < i;k++)
				{
					for(int l = 1;l < j;l++)
					{
						dp[i][j] += dp[k][l] * dp[i - k][j - l];
					}
				}
				/*
				ͨ������ݷ���ֵ�Աȣ� �ó���������ֵ 
				*/
				dp[i][j] /= j - 1;
			}
		}
	}
	return dp[N][M];
} 
int main()
{
	int N,M,solu = 0;
	scanf("%d %d",&N,&M);
	printf("%lld",dyp(N,M));
	//dfs(N,0,M,&solu);
	//printf(" %d",solu);
	return 0;
}
