#include <stdio.h>
/*
本程序文件主要使用回溯法、动态规划法，对“n球 r盒”问题进行求解 
问题规模：1 <= r <= n <= 20 
*/

/*
问题7：n个相同球 放入 r个相同盒子 不允许空盒 
本质上变成了数的分解问题 3 = 1 + 2 
resolve:分解次数 ,初始值为0, 不应该超过盒子数r 
start:当前分解起点 ,因为不允许空盒子，初始值为1
*/ 
void dfs(int resolve,int start,int n,int r,int heaps[],int *solu)
{
	if(resolve < r)
	{
		for(int i = start;i <= n;i++)
		{
			//一次装填一个盒子 
			heaps[resolve] = i;//装入i个球 
			dfs(resolve + 1,i,n - i,r,heaps,solu);
			heaps[resolve] = 0;//取出i个球，避免影响其它路线 
		}
	}
	else if(n == 0)
	{
		*solu += 1;
		printf("方案%d:",*solu);
		for(int i = 0;i < r;i++)
		{
			printf("{ %d } ",heaps[i]);
		}
		printf("\n");
	} 
}
/*
定义f(n, m)为  n个相同球 放入 m个相同盒中 允许空盒  的放法数目。
当 n < m , 则总会有m-n个盒子空着，去掉他们对总的放法不产生影响，即 if(m > n) f(n, m) = f(n, n)
当 n >= m, 可分两种情况：    
1、不是所有盒子都有球，至少有一个盒子空着，拿掉一个空盒子不影响总的放法，则 f(n, m) = f(n, m-1);    
2、所有盒子都有球，我们可以从每个盒子中拿掉一个球而不影响总的放法，则 f(n, m) = f(n-m, m);
所以对于m<=n的情况，有 f(n, m)=f(n, m-1) + f(n-m, m)
*/
long long cal_empty(int n,int r)
{
	if(n == 0 || r == 1)
	return 1;
	if(n < r)
	return cal_empty(n,n);
	return cal_empty(n,r - 1) + cal_empty(n - r,r);
} 
/*
动态规划法
dp[i][j]：i个相同球 放入 j个相同盒子 不允许空盒 
dp[i][j] = dp[i - j][j](允许空盒); 先在每个箱子里面放1个球，然后还剩下i - j个球了，从不空盒转化为空盒 
*/
long long cal_no_empty(int n,int r)
{
	long long dp[n + 1][r + 1];
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= r;j++)
		{
			if(j == 1 || i == j)
			dp[i][j] = 1;
			else if(i < j)
			dp[i][j] = 0;
			else
			{
				dp[i][j] = cal_empty(i - j,j);//从不空盒问题转化为空盒问题 
			}
		}
	}
	return dp[n][r];
} 

int main() 
{
	int n,r,solu = 0;
	scanf("%d %d",&n,&r);
	int heaps[21];//堆 
	memset(heaps,0,sizeof(heaps));//初始化堆数组 
	dfs(0,1,n,r,heaps,&solu);//地址传递 
	printf("dp: %lld",cal_no_empty(n,r));
	return 0;
}
