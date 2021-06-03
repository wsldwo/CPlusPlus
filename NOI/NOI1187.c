#include <stdio.h>
/*
回溯法，为解决重复问题，需要将数字从小到大进行输出
想起力扣上一题，只有先将数据升序排列，再进行回溯才不会出现重复例子 
*/
void dfs(int N,int M,int len,int last_num,long long *solu)
{
	if(N == 0 && M == len)
	*solu += 1;
	else if(M > len && N > 0)
	{
		for(int i = last_num;i <= N;i++)
		{
			dfs(N - i,M,len + 1,i,solu);
		}
	}
}
int main()
{
	int N,M;
	long long solu = 0;
	scanf("%d %d",&N,&M);
	dfs(N,M,0,1,&solu);//把正整数N分解成M个正整数
	printf("%lld",solu);
	return 0;
} 
