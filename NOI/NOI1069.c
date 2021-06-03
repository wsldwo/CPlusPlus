#include <stdio.h>

void dfs(int target,int start,int *solutions)//Ŀ��ֵ �� ���ֵ ,solutions��ַ���� 
{
	if(target == 1)//�ֽ���� 
	{
		*solutions += 1;
		return;//ֱ�ӷ��أ��������� 
	}
	for(int i = start;i <= target;i++)
	{
		if(target % i == 0)//��������
		{
			//���л���
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
		scanf("%d",&N[i]);//���������ü�ȡַ������������Ԫ��һ��Ҫ��ȡַ�� 
	}
	for(int i = 0;i < n;i++)
	{
		int solutions = 0;
		dfs(N[i],2,&solutions);//��ַ���ݣ����������ı�solutions��ֵ 
		printf("%d\n",solutions);
	}
	return 0;
}
