#include <stdio.h>
/*
�������ļ���Ҫʹ�û��ݷ�����̬�滮�����ԡ�n�� r�С����������� 
�����ģ��1 <= r <= n <= 20 
*/

/*
����7��n����ͬ�� ���� r����ͬ���� �������պ� 
�����ϱ�������ķֽ����� 3 = 1 + 2 
resolve:�ֽ���� ,��ʼֵΪ0, ��Ӧ�ó���������r 
start:��ǰ�ֽ���� ,��Ϊ�������պ��ӣ���ʼֵΪ1
*/ 
void dfs(int resolve,int start,int n,int r,int heaps[],int *solu)
{
	if(resolve < r)
	{
		for(int i = start;i <= n;i++)
		{
			//һ��װ��һ������ 
			heaps[resolve] = i;//װ��i���� 
			dfs(resolve + 1,i,n - i,r,heaps,solu);
			heaps[resolve] = 0;//ȡ��i���򣬱���Ӱ������·�� 
		}
	}
	else if(n == 0)
	{
		*solu += 1;
		printf("����%d:",*solu);
		for(int i = 0;i < r;i++)
		{
			printf("{ %d } ",heaps[i]);
		}
		printf("\n");
	} 
}
/*
����f(n, m)Ϊ  n����ͬ�� ���� m����ͬ���� �����պ�  �ķŷ���Ŀ��
�� n < m , ���ܻ���m-n�����ӿ��ţ�ȥ�����Ƕ��ܵķŷ�������Ӱ�죬�� if(m > n) f(n, m) = f(n, n)
�� n >= m, �ɷ����������    
1���������к��Ӷ�����������һ�����ӿ��ţ��õ�һ���պ��Ӳ�Ӱ���ܵķŷ����� f(n, m) = f(n, m-1);    
2�����к��Ӷ��������ǿ��Դ�ÿ���������õ�һ�������Ӱ���ܵķŷ����� f(n, m) = f(n-m, m);
���Զ���m<=n��������� f(n, m)=f(n, m-1) + f(n-m, m)
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
��̬�滮��
dp[i][j]��i����ͬ�� ���� j����ͬ���� �������պ� 
dp[i][j] = dp[i - j][j](�����պ�); ����ÿ�����������1����Ȼ��ʣ��i - j�����ˣ��Ӳ��պ�ת��Ϊ�պ� 
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
				dp[i][j] = cal_empty(i - j,j);//�Ӳ��պ�����ת��Ϊ�պ����� 
			}
		}
	}
	return dp[n][r];
} 

int main() 
{
	int n,r,solu = 0;
	scanf("%d %d",&n,&r);
	int heaps[21];//�� 
	memset(heaps,0,sizeof(heaps));//��ʼ�������� 
	dfs(0,1,n,r,heaps,&solu);//��ַ���� 
	printf("dp: %lld",cal_no_empty(n,r));
	return 0;
}