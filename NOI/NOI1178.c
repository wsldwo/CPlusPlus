#include <stdio.h>
void dfs(int no,int n,int r,int boxes[20][20],long long *solu)
{
	if(no <= n)
	{
		int balls = n - no + 1;//剩余球的数量
		int empty_boxes = 0;//剩余空盒子数量 
		for(int i = 0;i < r;i++)
		{
			if(boxes[i][0] == 0)
			empty_boxes += 1;
		}
		for(int i = 0;i < r;i++)
		{
			if(balls < empty_boxes)
			{
				//不满足要求了 
			}
			else if(balls == empty_boxes)
			{
				//一个空盒子一个球
				if(boxes[i][0] == 0)
				{
					boxes[i][0] = no;//装球 
					dfs(no + 1,n,r,boxes,solu);
					boxes[i][0] = 0;//数据回退，以免影响其它分支路线 
				}
			}
			else
			{
				//分配球的过程
				int j = 0;
				while(boxes[i][j] != 0)
				j++;
				boxes[i][j] = no;//装球 
				dfs(no + 1,n,r,boxes,solu);
				boxes[i][j] = 0;//数据回退，以免影响其它分支路线 
			} 
			
			
		}
	}
	else
	{
		*solu += 1; 
		printf("方案%d:\n",*solu);
		for(int i = 0;i < r;i++)
		{
			printf("{");
			int j = 0;
			while(boxes[i][j] != 0)
			{
				printf(" %d",boxes[i][j]);
				j++;
			}
			printf(" }  ");
		}
		printf("\n");
	} 
}
long long factor(int n)
{
	if(n == 1 || n == 0)
	{
		return 1;
	}
	else
	{
		return n * factor(n - 1);
	}
}
long long dp(int n,int r)
{
	//n为行 r为列 dp[n][r]表示把n个球装进r个盒子的方法数
	long long dp[n + 1][r + 1];
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= r;j++)
		{
			if(j == 1)
			dp[i][j] = 1;
			else if(i == 1)
			dp[i][j] = 0;
			else
			{
				//S(x,y)=S(x-1,y)*y+S(x-1,y-1).
				/*
				因为把X个球放入Y个箱子,相当于先把X-1个球放好再放最后一个.
				最后一个有两种放法：放入前面已经有球的箱子或者独占一个箱子.
				前者对应S(x-1,y)*y (放入每一个不同的箱子都是一种不同的放法,因为箱子内原来的球不同),后者对应S(x-1,y-1).
				*/
				dp[i][j] = dp[i - 1][j] * j + dp[i - 1][j - 1];
			}
		}
	}
	return dp[n][r];
}
int main()
{
	int n,r;
	scanf("%d %d",&n,&r);
	long long solu = 0;
	int boxes[20][20];//盒子  
	memset(boxes,0,sizeof(boxes));//memset可以直接初始化一维、二维数组 
	/* 
	for(int i = 0;i < 20;i++)
	{
		//memset(boxes[i],0,sizeof);
		for(int j = 0;j < 20;j++)
		{
			printf("%d ",boxes[i][j]);
		}
	} 
	*/
	dfs(1,n,r,boxes,&solu);
	//printf("%lld",solu / factor(r));
	printf("%lld",dp(n,r));
	return 0;
} 
