#include <stdio.h>
/*
���ݷ� 
nodes:��Ҫ���õĽڵ�����
level_num:�������ң�������� breadth first search��˳��洢��ʣ��ڵ㼯�� 
solu:�������� 
*/
void dfs(int nodes,int level_num,long long *solu)
{
	if(nodes == 0)
	*solu += 1;
	else if(nodes > 0)
	{
		//����ÿһ���ڵ㣬������4��ѡ��1��ֻ�������ӣ�2��ֻ�����Һ��ӣ�3��ͬʱ�������Һ��ӣ�4���������� ����һ���ύ��Ȼ���˴������ 
		if(level_num > 0)
		{
			//ÿ��ֻ����level_num�е�һ��Ԫ�صĺ��� 
			//ֻ��������
			dfs(nodes - 1,level_num,solu);// ��һ��һ��level_num����
			//ֻ�����Һ���
			dfs(nodes - 1,level_num,solu);// ��һ��һ��level_num����
			//ͬʱ�������Һ���
			dfs(nodes - 2,level_num + 1,solu);// ��һ�Ӷ���level_num��һ 
			//���ˣ��Ҿ�Ȼ�����˲��������������
			//���ҽ����ڵ㲻�����һ��ʱ������ѡ�������� 
			if(level_num > 1)
			{
				//��������
				dfs(nodes,level_num - 1,solu); 
			}
		}
		else
		{
			//�����ɸ��ڵ� 
			dfs(nodes - 1,level_num + 1,solu); 
		}
	}
}
/*
���ƹ�ʽ������̬�滮������ 
dp[i] =  2 *dp[i - 1] + dp[i - 2] 
*/
long long cal(int n)
{
	long long num[31];
	num[0] = 1;//����ӵ����ʼ�����ҵ�����Ϊ1���Ӷ����ɿ��������У��������ǿ����������� 
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
