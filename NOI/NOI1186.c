#include <stdio.h>
/*
回溯法
虽然只能求解深度较浅的一些值，但是可以作为动态规划法的依据 
*/
void dfs(int N,int M,int len,int *solu)//地址传递 
{
	if(N == 0 && len == M)
	*solu += 1;
	else if(len < M)//剪枝 
	{
		for(int i = 0;i <= N;i++)
		dfs(N - i,M,len + 1,solu);
	} 
}
/*
动态规划法:
dp[i][j]:将i分解为j个非负整数的方案数 
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
				//待续 
				for(int k = 0;k <= i;k++)
				{
					for(int l = 0;l <= j;l++)
					{
						dp[i][j] += dp[k][l] * dp[i - k][j - l];//分步相乘 分类相加 
					}
				}
				/*
				不要问我为什么，这是通过与回溯法进行对比得出来的数据修正 
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
