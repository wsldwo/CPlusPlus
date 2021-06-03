#include <stdio.h>
void matrix_copy(int origin[][100],int destin[][100],int m,int n)
{
	for(int i = 0;i < m;i++)
		for(int j = 0;j < n;j++)
			origin[i][j] = destin[i][j];
}
//�����ӡ 
/*
����ά���鵱��������ʱ�򣬱���ָ������ά����С����ʡ�Ե�һά�ģ�
���ǲ���ʡ�Եڶ�ά���߸���ά�Ĵ�С�������ɱ�����ԭ�����Ƶ�
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
//˳ʱ��90�� 
void clockwise_90d(int M[][100],int N[][100],int *m,int *n)//��ַ���ݣ�C����û�����ô���int &m��C++���� 
{
	//��һ�з�ת����һ�� ... 
	//�б��У��б��� 
	for(int i = 0;i < *n;i++)
		for(int j = 0;j < *m;j++)
		{
			N[i][j] = M[*m - 1 - j][i];
		}
	//����������ֵ 
	int temp = *m;
	*m = *n;
	*n = temp;
	//���󿽱� 
	matrix_copy(M,N,*m,*n);
	//print(M,*m,*n);
}
//��ʱ��90�� 
void counterclockwise_90d(int M[][100],int N[][100],int *m,int *n)
{
	//���һ�б��һ�� 
	//�б��У��б��� 
	for(int i = 0;i < *n;i++)
		for(int j = 0;j < *m;j++)
		{
			N[i][j] = M[j][*n - 1 - i];
		}
	//����������ֵ 
	int temp = *m;
	*m = *n;
	*n = temp;
	//���󿽱� 
	matrix_copy(M,N,*m,*n);
	//print(M,*m,*n);
}
//���ҷ�ת 
void flip(int M[][100],int m,int n)
{ 
	//���в��� 
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
//���·�ת 
void upsidedown(int M[][100],int m,int n)
{
	//���в��� 
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
	int m,n,M[100][100],N[100][100];//Mԭ����N�м�������
	scanf("%d %d",&m,&n);
	for(int i = 0;i < m;i++)//mΪ���� 
	{
		for(int j = 0;j < n;j++)//nΪ���� 
		{
			scanf("%d",&M[i][j]);//һ��һ����ȡ ,�������ȡ��ַ����"&" ,���������Բ��� 
			//printf("%d\n",M[i][j]);
		}
	}
	//Ϊ��û�������ߣ� ��Ϊ��ά���鴫�β��ԣ����³����쳣 
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
