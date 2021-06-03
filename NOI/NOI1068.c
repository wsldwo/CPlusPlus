#include <stdio.h>
void matrix_copy(int origin[][100],int destin[][100],int m,int n)
{
	for(int i = 0;i < m;i++)
		for(int j = 0;j < n;j++)
			origin[i][j] = destin[i][j];
}
//矩阵打印 
/*
将二维数组当作参数的时候，必须指明所有维数大小或者省略第一维的，
但是不能省略第二维或者更高维的大小，这是由编译器原理限制的
*/
void print(int M[][100],int m,int n)
{
	//printf("m:%d n:%d\n",m,n);
	for(int i = 0;i < m;i++)
	{
		for(int j = 0;j < n;j++)
		{
			printf("%d ",M[i][j]); 
		}
		printf("\n");
	}
	//printf("---------------------\n");
}
//顺时针90° 
void clockwise_90d(int M[][100],int N[][100],int *m,int *n)//地址传递，C语言没有引用传递int &m，C++才有 
{
	//第一列翻转后变第一行 ... 
	//列变行，行变列 
	for(int i = 0;i < *n;i++)
		for(int j = 0;j < *m;j++)
		{
			N[i][j] = M[*m - 1 - j][i];
		}
	//交换行列数值 
	int temp = *m;
	*m = *n;
	*n = temp;
	//矩阵拷贝 
	matrix_copy(M,N,*m,*n);
	//print(M,*m,*n);
}
//逆时针90° 
void counterclockwise_90d(int M[][100],int N[][100],int *m,int *n)
{
	//最后一列变第一行 
	//列变行，行变列 
	for(int i = 0;i < *n;i++)
		for(int j = 0;j < *m;j++)
		{
			N[i][j] = M[j][*n - 1 - i];
		}
	//交换行列数值 
	int temp = *m;
	*m = *n;
	*n = temp;
	//矩阵拷贝 
	matrix_copy(M,N,*m,*n);
	//print(M,*m,*n);
}
//左右翻转 
void flip(int M[][100],int m,int n)
{ 
	//行列不变 
	for(int i = 0,j = n - 1;i < j;i++,j--)
	{
		for(int k = 0;k < m;k++)
		{
			int temp = M[k][i];
			M[k][i] = M[k][j];
			M[k][j] = temp;
		}
	}
	//print(M,m,n);
}
//上下翻转 
void upsidedown(int M[][100],int m,int n)
{
	//行列不变 
	for(int i = 0,j = m - 1;i < j;i++,j--)
	{
		for(int k = 0;k < n;k++)
		{
			int temp = M[i][k];
			M[i][k] = M[j][k];
			M[j][k] = temp;
		}
	}
	//print(M,m,n);
}

int main()
{
	int m,n,M[100][100],N[100][100];//M原矩阵，N中间结果矩阵
	scanf("%d %d",&m,&n);
	for(int i = 0;i < m;i++)//m为行数 
	{
		for(int j = 0;j < n;j++)//n为列数 
		{
			scanf("%d",&M[i][j]);//一个一个读取 ,必须加上取地址符号"&" ,数组名可以不加 
			//printf("%d\n",M[i][j]);
		}
	}
	//为何没有往下走？ 因为二维数组传参不对，导致程序异常 
	//print(M,m,n);
	char operate[100];
	scanf("%s",operate);
	//printf("---------------------\n");
	//printf("%s",operate);
	int pos = 0;
	while(operate[pos] != '\0')
	{
		//print(M,m,n);
		if(operate[pos] == 'A')
			clockwise_90d(M,N,&m,&n);
		else if(operate[pos] == 'B')
			counterclockwise_90d(M,N,&m,&n);
		else if(operate[pos] == 'C')
			flip(M,m,n);
		else if(operate[pos] == 'D')
			upsidedown(M,m,n);
		pos++;
	}
	print(M,m,n);
	return 0;
}
