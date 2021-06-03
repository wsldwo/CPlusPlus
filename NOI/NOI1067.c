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
	for(int i = 0;i < m;i++)//m为行数 
		for(int j = 0;j < n;j++)//n为列数 
		{
			scanf("%d",&A[i][j]);//一个一个读取 ,必须加上取地址符号"&" ,数组名可以不加 
		}
	scanf("%d %d",&r,&s);
	for(int i = 0;i < r;i++)//r为行数 
		for(int j = 0;j < s;j++)//s为列数 
		{
			scanf("%d",&B[i][j]);//一个一个读取 ,必须加上取地址符号"&" ,数组名可以不加 
		}
	int rows = m - r + 1,cols = n - s + 1;//遍历行数、遍历列数
	int diff = 2100000000,x = 0,y = 0;//最小差异值,最匹配矩阵的起始坐标 
	for(int i = 0;i < rows;i++)
		for(int j = 0;j < cols;j++)
		{
			int sum = 0; 
			//i,j为当前矩阵左上角坐标
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
//打印测试
	for(int i = 0;i < m;i++)//m为行数 
	{
		for(int j = 0;j < n;j++)//n为列数 
		{
			printf("%d ",A[i][j]);
		}
		printf("\n");
	}
	for(int i = 0;i < r;i++)//r为行数 
	{
		for(int j = 0;j < s;j++)//s为列数 
		{
			printf("%d ",B[i][j]);//一个一个读取 
		}
		printf("\n");
	}
	//printf("%d %d %d",sizeof(C),sizeof(B),sizeof(A));
*/
