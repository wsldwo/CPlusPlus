#include <stdio.h>
/*
���ݷ���Ϊ����ظ����⣬��Ҫ�����ִ�С����������
����������һ�⣬ֻ���Ƚ������������У��ٽ��л��ݲŲ�������ظ����� 
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
	dfs(N,M,0,1,&solu);//��������N�ֽ��M��������
	printf("%lld",solu);
	return 0;
} 
