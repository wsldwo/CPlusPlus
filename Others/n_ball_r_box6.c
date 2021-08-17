#include <stdio.h>
/*
本程序文件主要使用回溯法、动态规划法，对“n球 r盒”问题进行求解 
问题规模：1 <= r <= n <= 20 
*/

/*
问题6：n个相同球 放入 r个不同盒子 允许空盒 
id：盒子编号，从1开始 
n：剩余球的数量
r：盒子的数量
boxes：记录盒子容纳情况 
*/ 
void dfs(int id,int n,int r,int boxes[],int *solu)
{
	if(n > 0 && id <= r)
	{
		for(int i = 0;i <= n;i++)//可装入0个 
		{
			//一次装填一个盒子 
			boxes[id] = i;//装入i个球 
			dfs(id + 1,n - i,r,boxes,solu);
			boxes[id] = 0;//取出i个球，避免影响其它路线 
		}
	}
	else if(n == 0)
	{
		*solu += 1;
		printf("方案%d:",*solu);
		for(int i = 1;i <= r;i++)
		{
			if(boxes[i] > 0) 
			printf("box%d:{ %d } ",i,boxes[i]);
			else
			printf("box%d:{  } ",i);
		}
		printf("\n");
	} 
} 
/*
动态规划法
dp[i][j]：把i个相同球放入j个不同盒子中 允许空盒 
dp[i][j] = dp[i - 1][j] + dp[i][j - 1]; 计数原理：分步相乘 分类相加 
*/
long long cal(int n,int r)
{
	long long dp[n + 1][r + 1];
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= r;j++)
		{
			if(i == 1)
			dp[i][j] = j;
			else if(j == 1)
			dp[i][j] = 1;
			else
			{
				dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
			}
		}
	}
	return dp[n][r];
} 

int main() 
{
	int n,r,solu = 0;
	scanf("%d %d",&n,&r);
	int boxes[21];//盒子
	memset(boxes,0,sizeof(boxes));//初始化盒子数组 
	dfs(1,n,r,boxes,&solu);//地址传递 
	printf("dp: %lld",cal(n,r));
	return 0;
}
