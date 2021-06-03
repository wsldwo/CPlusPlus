#include <stdio.h>
/*
本程序文件主要使用回溯法、动态规划法，对“n球 r盒”问题进行求解
问题规模：1 <= r <= n <= 20
*/
int count(int arr[],int len,int target)
{
	int c = 0;
	for(int i = 0;i < len;i++)
	{
		if(arr[i] == target)
		c++;
	}
	return c;
}
/*
问题3：n个不同球 放入 r个相同盒子 不允许空盒
*/
void dfs(int heap_id,int n,int r,int start,int end,int balls[],int *solu)
{
	if(count(balls,n + 1,0) == 0)
	{
		for(int i = 1;i <= r;i++)
		{
			if(count(balls,n + 1,i) == 0)
				return;
		}
		for(int i = 1;i <= n;i++)
		{
			if(balls[i] > r)
				return;
		}
		*solu +=1;
		printf("方案%d:",*solu);
		for(int i = 1;i <= r;i++)
		{
			printf("{ ");
			for(int j = 1;j <= n;j++)
			{
				if(balls[j] == i)
				{
					printf("%d ",j);
				}
			}
			printf("}");
		}
		printf("\n");
		
	}
	else if(start < end)
	{
		int leader = -1;
		if(count(balls,n + 1,heap_id) == 0)
		{
			for(int i = start;i < end;i++)
			{
				if(balls[i] == 0)
				{
					leader = i;//找到堆头元素 
					balls[i] = heap_id;
					if(count(balls,n + 1,0) == 0)
					{
						dfs(heap_id,n,r,n + 1,end,balls,solu);
						balls[i] = 0;
						return;
					}
					break;
				}
			}
		}
		
		int x = 0;
		for(int i = start;i < end;i++)
			if(balls[i] == 0)
				x++;
		
		for(int i = start;i < end;i++)
		{
			if(balls[i] == 0)
			{
				//线路1 进堆
				balls[i] = heap_id;
				dfs(heap_id,n,r,i + 1,end,balls,solu);
				balls[i] = 0;
				
				//路线2 不进堆
				dfs(heap_id,n,r,i + 1,end,balls,solu);
				
				break;//解决重复路线，一次只处理一个节点 
			}
		}
		//遗失路线 
		if(x == 0)
		{
			for(int i = 1;i < start;i++)
			{
				if(balls[i] == 0)
				{
					//线路1 进堆
					balls[i] = heap_id + 1;
					dfs(heap_id + 1,n,r,i + 1,end,balls,solu);
					balls[i] = 0;
					
					break;//解决重复路线，一次只处理一个节点 
				}
			} 
		}
		
		//重置堆头元素
		if(leader != -1)
			balls[leader] = 0;//必须还原
		
	}
	else if(start >= end)
	{
		if(heap_id + 1 <= r)
		{
			int pos = 1;
			while(balls[pos] != 0)
				pos++;
			dfs(heap_id + 1,n,r,pos,end,balls,solu);
		}
	} 

}
/*
动态规划法
dp[i][j]：把i个不同球放入j个相同盒子中 不允许空盒
dp[i][j] = dp[i - 1][j] * j + dp[i - 1][j - 1]; 计数原理：分步相乘 分类相加
这种情况就是第二类斯特林数，我们来理解一下这个转移方程。
对于第i个球，如果前面的i - 1个球已经放在了j个箱子里，那么现在第i个球放在哪个箱子都是可以的，所以dp[i - 1][j] * j
如果前i - 1个球已经放在了j - 1个箱子里，那么现在第i个球必须要新开一个箱子来存放，所以dp[i - 1][j - 1]
*/
long long cal(int n,int r)
{
	long long dp[n + 1][r + 1];
	memset(dp,0,sizeof(dp));
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= r; j++)
		{
			if(j == 1)
				dp[i][j] = 1;
			else if(i == 1)
				dp[i][j] = 0;
			else
			{
				dp[i][j] = dp[i - 1][j] * j + dp[i - 1][j - 1];
			}
		}
	}
	return dp[n][r];
}

int main()
{
	int n,r,solu = 0;
	scanf("%d %d",&n,&r);
	int balls[21];//球
	memset(balls,0,sizeof(balls));//初始化球数组
	balls[0] = -1;//此位置不使用 
	dfs(1,n,r,1,n + 1,balls,&solu);//地址传递
	printf("dp: %lld",cal(n,r));
	return 0;
}
