#include <stdio.h>
/*
len_a:5元队伍人数
len_b:10元队伍人数
shop_5:商店5元数量 
此函数把a队、b队的人当成完全相同的(完全一样的)人来处理，
最终结果需要乘以 n!（a队全排列） * n! （b队全排列）
*/
int factorial(int n)
{
	if(n == 0 || n == 1)return 1;
	else return factorial(n - 1) * n;
}
void dfs(int len_a,int len_b,int shop_5,long long *solutions)
{
	if(len_a == 0 && len_b == 0)
	{
		*solutions += 1;
	}
	else
	{
		if(shop_5 > 0 && len_b > 0)
			dfs(len_a,len_b - 1,shop_5 - 1,solutions);//10元进场
		if(len_a > 0)
			dfs(len_a - 1,len_b,shop_5 + 1,solutions);//5元进场 
	} 
}
int main()
{
	int n;
	scanf("%d",&n);
	long long ans,solutions = 0;
	dfs(n,n,0,&solutions);
	//printf("%lld   %d   ",solutions,factorial(n));
	/*
	// n = 9 , n = 10 溢出 解决办法
	要使最终结果保留为long long，那么参与计算的变量都必须强制类型转换为long long 
	*/
	ans = (long long)factorial(n) * (long long)factorial(n) * solutions;//n!（a队全排列） * n! （b队全排列）
	printf("%lld",ans);
	return 0;
}
