#include <stdio.h>
/*
�������ļ���Ҫʹ�û��ݷ�����̬�滮�����ԡ�n�� r�С����������� 
�����ģ��1 <= r <= n <= 20 
*/

/*
����2��n����ͬ�� ���� r����ͬ���� ����պ� 
no����ǰ��ı�ţ���1��ʼ 
n���������
r�����ӵ�����
balls����¼��Ĵ�Ŵ�
boxes����¼����������� 
*/ 
void dfs(int no,int n,int r,int balls[],int boxes[][20],int *solu)
{
	if(no <= n)
	{
		for(int i = 1;i <= r;i++)
		{
			int j = 0;//����������Ǵ�0��λ��ʼ��ŵ�
			while(boxes[i][j] != 0)
			{
				j++;//�ҵ����λ�� 
			} 
			//���� 
			boxes[i][j] = no;
			balls[no] = i;
			//����
			dfs(no + 1,n,r,balls,boxes,solu);
			//ȡ�򣬱���Ӱ��������֧·��
			boxes[i][j] = 0;
			balls[no] = 0;
		}
		/* 
		int left_balls = n - no + 1;//ʣ��������� 
		int empty_boxes = 0;//�պ������� 
		for(int i = 1;i <= r;i++)
		{
			if(boxes[i][0] == 0)
			empty_boxes += 1;
		} 
		if(left_balls == empty_boxes)
		{
			//ÿ���պ��Ӹ�һ��
			for(int i = 1;i <= r;i++)
			{
				if(boxes[i][0] == 0)
				{
					//���� 
					boxes[i][0] = no;
					balls[no] = i;
					//����
					dfs(no + 1,n,r,balls,boxes,solu);
					//ȡ�򣬱���Ӱ��������֧·��
					boxes[i][0] = 0;
					balls[no] = 0;
				}
			} 
		}
		else if(left_balls > empty_boxes)
		{
			//���кܶ������
			for(int i = 1;i <= r;i++)
			{
				int j = 0;//����������Ǵ�0��λ��ʼ��ŵ�
				while(boxes[i][j] != 0)
				{
					j++;//�ҵ����λ�� 
				} 
				//���� 
				boxes[i][j] = no;
				balls[no] = i;
				//����
				dfs(no + 1,n,r,balls,boxes,solu);
				//ȡ�򣬱���Ӱ��������֧·��
				boxes[i][j] = 0;
				balls[no] = 0;
			}
		} 
		*/
	}
	else
	{
		//������ɣ���ӡ���� 
		*solu += 1;
		printf("����%d:  ",*solu);
		for(int i = 1;i <= r;i++)//���ӱ�Ŵ�1��ʼ 
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
��̬�滮��
dp[i][j]����i����ͬ�����j����ͬ������ ����պ� 
dp[i][j] = dp[i - 1][j] * j ����ԭ���ֲ���� ������� 
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
	int balls[21],boxes[21][20];//�������
	memset(balls,0,sizeof(balls));//��ʼ�������� 
	memset(boxes,0,sizeof(boxes));//��ʼ���������� 
	dfs(1,n,r,balls,boxes,&solu);//��ַ���� 
	printf("dp: %lld",cal(n,r));
	return 0;
}
