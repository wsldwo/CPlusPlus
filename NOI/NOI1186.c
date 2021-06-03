#include <stdio.h>
/*
���ݷ�
��Ȼֻ�������Ƚ�ǳ��һЩֵ�����ǿ�����Ϊ��̬�滮�������� 
*/
void dfs(int N,int M,int len,int *solu)//��ַ���� 
{
	if(N == 0 && len == M)
	*solu += 1;
	else if(len < M)//��֦ 
	{
		for(int i = 0;i <= N;i++)
		dfs(N - i,M,len + 1,solu);
	} 
}
/*
��̬�滮��:
dp[i][j]:��i�ֽ�Ϊj���Ǹ������ķ����� 
*/ 
long long dyp(int N,int M)
{
	long long dp[31][31];
	for(int i = 0;i <= N;i++)
	{
		for(int j = 0;j <= M;j++)
		{
			if(j == 1)
			dp[i][j] = 1;
			else if(i == 1)
			dp[i][j] = j;
			else if(j == 0)
			dp[i][j] = 0;
			else if(i == 0)
			dp[i][j] = 1; 
			else
			{
				dp[i][j] = 0;
				//���� 
				for(int k = 0;k <= i;k++)
				{
					for(int l = 0;l <= j;l++)
					{
						dp[i][j] += dp[k][l] * dp[i - k][j - l];//�ֲ���� ������� 
					}
				}
				/*
				��Ҫ����Ϊʲô������ͨ������ݷ����жԱȵó������������� 
				*/
				dp[i][j] /= (j - 1);
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
	//dfs(N,M,0,&solu);
	//printf(" %d",solu);
	return 0;
}
