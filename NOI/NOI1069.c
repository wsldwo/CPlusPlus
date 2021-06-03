#include <stdio.h>

void dfs(int target,int start,int *solutions)//目标值 和 起点值 ,solutions地址传递 
{
	if(target == 1)//分解完成 
	{
		*solutions += 1;
		return;//直接返回，函数结束 
	}
	for(int i = start;i <= target;i++)
	{
		if(target % i == 0)//可以整除
		{
			//进行回溯
			dfs(target / i,i,solutions);
		} 
	}
} 
int main()
{
	int n,N[100];
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&N[i]);//数组名不用加取址符，但是数组元素一定要加取址符 
	}
	for(int i = 0;i < n;i++)
	{
		int solutions = 0;
		dfs(N[i],2,&solutions);//地址传递，可以真正改变solutions的值 
		printf("%d\n",solutions);
	}
	return 0;
}
