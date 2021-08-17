#include <stdio.h>
/*
�������ļ���Ҫʹ�û��ݷ�����̬�滮�����ԡ�n�� r�С����������� 
�����ģ��1 <= r <= n <= 20 
*/

/*
����5��n����ͬ�� ���� r����ͬ���� �������պ� 
id�����ӱ�ţ���1��ʼ 
n��ʣ���������
r�����ӵ�����
boxes����¼����������� 
*/ 
void dfs(int id,int n,int r,int boxes[],int *solu)
{
	if(n > 0 && id <= r)
	{
		for(int i = 1;i <= n;i++)
		{
			//һ��װ��һ������ 
			boxes[id] = i;//װ��i���� 
			dfs(id + 1,n - i,r,boxes,solu);
			boxes[id] = 0;//ȡ��i���򣬱���Ӱ������·�� 
		}
	}
	else if(n == 0 && id == r + 1)
	{
		*solu += 1;
		printf("����%d:",*solu);
		for(int i = 1;i <= r;i++)
		{
			printf("box%d:{ %d } ",i,boxes[i]);
		}
		printf("\n");
	} 
} 
/*
��̬�滮��
dp[i][j]����i����ͬ�����j����ͬ������ �������պ� 
dp[i][j] = dp[i - 1][j - 1] + dp[i - 2][j - 1] + ... + dp[1][j - 1] ; ����ԭ�����ֲ���� ������� 
*/
long long cal(int n,int r)
{
	long long dp[n + 1][r + 1];
	memset(dp,0,sizeof(dp));
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
				int k = i - 1;
				while(k >= 1)
				{
					dp[i][j] += dp[k][j - 1];
					k--;
				}
			}
		}
	}
	return dp[n][r];
} 

int main() 
{
	int n,r,solu = 0;
	scanf("%d %d",&n,&r);
	int boxes[21];//����
	memset(boxes,0,sizeof(boxes));//��ʼ���������� 
	dfs(1,n,r,boxes,&solu);//��ַ���� 
	printf("dp: %lld",cal(n,r));
	return 0;
}