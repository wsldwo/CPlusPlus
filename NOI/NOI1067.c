#include <stdio.h>
int abs(int n)
{
	if(n < 0)
		return -1 * n;
	else
		return n;
} 
int main()
{
	int A[100][100],B[100][100];
	int m,n,r,s;
	scanf("%d %d",&m,&n);
	for(int i = 0;i < m;i++)//mΪ���� 
		for(int j = 0;j < n;j++)//nΪ���� 
		{
			scanf("%d",&A[i][j]);//һ��һ����ȡ ,�������ȡ��ַ����"&" ,���������Բ��� 
		}
	scanf("%d %d",&r,&s);
	for(int i = 0;i < r;i++)//rΪ���� 
		for(int j = 0;j < s;j++)//sΪ���� 
		{
			scanf("%d",&B[i][j]);//һ��һ����ȡ ,�������ȡ��ַ����"&" ,���������Բ��� 
		}
	int rows = m - r + 1,cols = n - s + 1;//������������������
	int diff = 2100000000,x = 0,y = 0;//��С����ֵ,��ƥ��������ʼ���� 
	for(int i = 0;i < rows;i++)
		for(int j = 0;j < cols;j++)
		{
			int sum = 0; 
			//i,jΪ��ǰ�������Ͻ�����
			for(int p = 0;p < r;p++)
				for(int q = 0;q < s;q++)
				{
					//printf("%d - %d ",A[i + p][j + q],B[p][q]);
					sum += abs(A[i + p][j + q] - B[p][q]);
				} 
			//printf("\nsum : %d\n",sum);
			if(sum < diff)
			{
				diff = sum;
				x = i;
				y = j;
			}
		}
	int c1 = x + r,c2 = y + s;
	for(int i = x;i < c1;i++)
	{
		for(int j = y;j < c2;j++)
		{
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	return 0;
}
/*
//��ӡ����
	for(int i = 0;i < m;i++)//mΪ���� 
	{
		for(int j = 0;j < n;j++)//nΪ���� 
		{
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	for(int i = 0;i < r;i++)//rΪ���� 
	{
		for(int j = 0;j < s;j++)//sΪ���� 
		{
			printf("%d ",B[i][j]);//һ��һ����ȡ 
		}
		printf("\n");
	}
	//printf("%d %d %d",sizeof(C),sizeof(B),sizeof(A));
*/
