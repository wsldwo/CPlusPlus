#include <stdio.h>
/*
回溯法    缺点：分解次数过多时，递归太深，出不来了 
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
动态规划法：
dp[i][j]:将i分解为j个正整数的方案数 
dp[N][M] = dp[n1][m1] * dp[N-n1][M-m1] + dp[n2][m2] * dp[N-n2][M-m2] + ......(分步相乘、分类相加)
*/
long long dyp(int N,int M)
{
	long long dp[51][51];
	//dp数组初始化
	for(int i = 1;i <= N;i++)
	{
		for(int j = 1;j <= M;j++)
		{
			if(j == 1 || j == i)
			dp[i][j] = 1;
			else if(i < j)
			dp[i][j] = 0;//无解
			else
			{
				dp[i][j] = 0;
				//进行计算dp[i][j] 
				for(int k = 1;k < i;k++)
				{
					for(int l = 1;l < j;l++)
					{
						dp[i][j] += dp[k][l] * dp[i - k][j - l];
					}
				}
				/*
				通过与回溯法数值对比， 得出来的修正值 
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
