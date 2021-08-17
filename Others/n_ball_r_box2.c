#include <stdio.h>
/*
本程序文件主要使用回溯法、动态规划法，对“n球 r盒”问题进行求解 
问题规模：1 <= r <= n <= 20 
*/

/*
问题2：n个不同球 放入 r个不同盒子 允许空盒 
no：当前球的编号，从1开始 
n：球的数量
r：盒子的数量
balls：记录球的存放处
boxes：记录盒子容纳情况 
*/ 
void dfs(int no,int n,int r,int balls[],int boxes[][20],int *solu)
{
	if(no <= n)
	{
		for(int i = 1;i <= r;i++)
		{
			int j = 0;//盒子里的球是从0号位开始存放的
			while(boxes[i][j] != 0)
			{
				j++;//找到存放位置 
			} 
			//放球 
			boxes[i][j] = no;
			balls[no] = i;
			//回溯
			dfs(no + 1,n,r,balls,boxes,solu);
			//取球，避免影响其它分支路线
			boxes[i][j] = 0;
			balls[no] = 0;
		}
		/* 
		int left_balls = n - no + 1;//剩余球的数量 
		int empty_boxes = 0;//空盒子数量 
		for(int i = 1;i <= r;i++)
		{
			if(boxes[i][0] == 0)
			empty_boxes += 1;
		} 
		if(left_balls == empty_boxes)
		{
			//每个空盒子各一个
			for(int i = 1;i <= r;i++)
			{
				if(boxes[i][0] == 0)
				{
					//放球 
					boxes[i][0] = no;
					balls[no] = i;
					//回溯
					dfs(no + 1,n,r,balls,boxes,solu);
					//取球，避免影响其它分支路线
					boxes[i][0] = 0;
					balls[no] = 0;
				}
			} 
		}
		else if(left_balls > empty_boxes)
		{
			//球还有很多可以浪
			for(int i = 1;i <= r;i++)
			{
				int j = 0;//盒子里的球是从0号位开始存放的
				while(boxes[i][j] != 0)
				{
					j++;//找到存放位置 
				} 
				//放球 
				boxes[i][j] = no;
				balls[no] = i;
				//回溯
				dfs(no + 1,n,r,balls,boxes,solu);
				//取球，避免影响其它分支路线
				boxes[i][j] = 0;
				balls[no] = 0;
			}
		} 
		*/
	}
	else
	{
		//回溯完成，打印方案 
		*solu += 1;
		printf("方案%d:  ",*solu);
		for(int i = 1;i <= r;i++)//盒子编号从1开始 
		{
			printf("box%d:{",i);
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
/*
动态规划法
dp[i][j]：把i个不同球放入j个不同盒子中 允许空盒 
dp[i][j] = dp[i - 1][j] * j 计数原理：分步相乘 分类相加 
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
			else
			{
				dp[i][j] = dp[i - 1][j] * j;
			}
		}
	}
	return dp[n][r];
} 

int main() 
{
	int n,r,solu = 0;
	scanf("%d %d",&n,&r);
	int balls[21],boxes[21][20];//球与盒子
	memset(balls,0,sizeof(balls));//初始化球数组 
	memset(boxes,0,sizeof(boxes));//初始化盒子数组 
	dfs(1,n,r,balls,boxes,&solu);//地址传递 
	printf("dp: %lld",cal(n,r));
	return 0;
}
