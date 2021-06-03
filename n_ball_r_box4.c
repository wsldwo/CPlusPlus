#include <stdio.h>
/*
�������ļ���Ҫʹ�û��ݷ�����̬�滮�����ԡ�n�� r�С�����������
�����ģ��1 <= r <= n <= 20
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
����4��n����ͬ�� ���� r����ͬ���� ����պ�
*/
void dfs(int heap_id,int n,int r,int start,int end,int balls[],int *solu)
{
	if(count(balls,n + 1,0) == 0)
	{
		/* ����պ��� 
		for(int i = 1;i <= r;i++)
		{
			if(count(balls,n + 1,i) == 0)
				return;
		}
		*/
		for(int i = 1;i <= n;i++)
		{
			if(balls[i] > r)
				return;
		}
		*solu +=1;
		printf("����%d:",*solu);
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
					leader = i;//�ҵ���ͷԪ�� 
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
				//��·1 ����
				balls[i] = heap_id;
				dfs(heap_id,n,r,i + 1,end,balls,solu);
				balls[i] = 0;
				
				//·��2 ������
				dfs(heap_id,n,r,i + 1,end,balls,solu);
				
				break;//����ظ�·�ߣ�һ��ֻ����һ���ڵ� 
			}
		}
		//��ʧ·�� 
		if(x == 0)
		{
			for(int i = 1;i < start;i++)
			{
				if(balls[i] == 0)
				{
					//��·1 ����
					balls[i] = heap_id + 1;
					dfs(heap_id + 1,n,r,i + 1,end,balls,solu);
					balls[i] = 0;
					
					break;//����ظ�·�ߣ�һ��ֻ����һ���ڵ� 
				}
			} 
		}
		
		//���ö�ͷԪ��
		if(leader != -1)
			balls[leader] = 0;//���뻹ԭ
			
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
��̬�滮��
dp[i][j]����i����ͬ�����j����ͬ������ ����պ�
�ڶ���˹������  dp[i][j] = dp[i - 1][j] * j + dp[i - 1][j - 1];
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
/*
sigma dp[i][x],0<=x<=j,dp[i][x]Ϊ�ڶ���˹������
�ۼӵڶ���˹���������������û�뵽���� 
*/
long long cal2(int n,int r)
{
	long long ans = 0;
	int i = 1;
	while(i <= r)
	{
		ans += cal(n,i);
		i++; 
	}	
	return ans;
}

int main()
{
	int n,r,solu = 0;
	scanf("%d %d",&n,&r);
	int balls[21];//��
	memset(balls,0,sizeof(balls));//��ʼ��������
	balls[0] = -1;//��λ�ò�ʹ�� 
	dfs(1,n,r,1,n + 1,balls,&solu);//��ַ����
	printf("dp: %lld",cal2(n,r));
	return 0;
}
