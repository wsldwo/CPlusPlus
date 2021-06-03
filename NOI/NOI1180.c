#include <stdio.h>
/*
回溯法 
nodes:需要放置的节点数量
level_num:按从左到右（层序遍历 breadth first search）顺序存储的剩余节点集合 
solu:方案总数 
*/
void dfs(int nodes,int level_num,long long *solu)
{
	if(nodes == 0)
	*solu += 1;
	else if(nodes > 0)
	{
		//对于每一个节点，总是有4种选择：1、只生成左孩子；2、只生成右孩子；3、同时生成左右孩子；4、不生孩子 （第一把提交居然忘了此情况） 
		if(level_num > 0)
		{
			//每次只生成level_num中第一个元素的孩子 
			//只生成左孩子
			dfs(nodes - 1,level_num,solu);// 减一加一，level_num不变
			//只生成右孩子
			dfs(nodes - 1,level_num,solu);// 减一加一，level_num不变
			//同时生成左右孩子
			dfs(nodes - 2,level_num + 1,solu);// 减一加二，level_num加一 
			//醉了，我居然忘记了不生孩子这种情况
			//当且仅当节点不是最后一个时，可以选择不生孩子 
			if(level_num > 1)
			{
				//不生孩子
				dfs(nodes,level_num - 1,solu); 
			}
		}
		else
		{
			//先生成根节点 
			dfs(nodes - 1,level_num + 1,solu); 
		}
	}
}
/*
递推公式法（动态规划法？） 
dp[i] =  2 *dp[i - 1] + dp[i - 2] 
*/
long long cal(int n)
{
	long long num[31];
	num[0] = 1;//必须从第零项开始，而且第零项为1，从而构成卡特兰数列，服了又是卡特兰！！！ 
	num[1] = 1,num[2] = 2;
	for(int i = 3;i <= n;i++)
	{
		num[i] = 0;
		for(int j = 0,k = i - 1;j < i;j++,k--)
		{
			num[i] += num[j] * num[k];
		}
		 
	}
	return num[n];
}

int main()
{
	int n;
	scanf("%d",&n);
	/*
	for(int i = 1;i <= n;i++)
	{
	long long solu = 0;
	dfs(i,0,&solu);
	printf("n = %d : %lld  dp: %lld\n",i,solu,cal(i));
	}
	*/
	printf("%lld",cal(n));
	return 0;
} 
