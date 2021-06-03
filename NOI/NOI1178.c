#include <stdio.h>
void dfs(int no,int n,int r,int boxes[20][20],long long *solu)
{
	if(no <= n)
	{
		int balls = n - no + 1;//ʣ���������
		int empty_boxes = 0;//ʣ��պ������� 
		for(int i = 0;i < r;i++)
		{
			if(boxes[i][0] == 0)
			empty_boxes += 1;
		}
		for(int i = 0;i < r;i++)
		{
			if(balls < empty_boxes)
			{
				//������Ҫ���� 
			}
			else if(balls == empty_boxes)
			{
				//һ���պ���һ����
				if(boxes[i][0] == 0)
				{
					boxes[i][0] = no;//װ�� 
					dfs(no + 1,n,r,boxes,solu);
					boxes[i][0] = 0;//���ݻ��ˣ�����Ӱ��������֧·�� 
				}
			}
			else
			{
				//������Ĺ���
				int j = 0;
				while(boxes[i][j] != 0)
				j++;
				boxes[i][j] = no;//װ�� 
				dfs(no + 1,n,r,boxes,solu);
				boxes[i][j] = 0;//���ݻ��ˣ�����Ӱ��������֧·�� 
			} 
			
			
		}
	}
	else
	{
		*solu += 1; 
		printf("����%d:\n",*solu);
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
	//nΪ�� rΪ�� dp[n][r]��ʾ��n����װ��r�����ӵķ�����
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
				��Ϊ��X�������Y������,�൱���Ȱ�X-1����ź��ٷ����һ��.
				���һ�������ַŷ�������ǰ���Ѿ���������ӻ��߶�ռһ������.
				ǰ�߶�ӦS(x-1,y)*y (����ÿһ����ͬ�����Ӷ���һ�ֲ�ͬ�ķŷ�,��Ϊ������ԭ������ͬ),���߶�ӦS(x-1,y-1).
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
	int boxes[20][20];//����  
	memset(boxes,0,sizeof(boxes));//memset����ֱ�ӳ�ʼ��һά����ά���� 
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
