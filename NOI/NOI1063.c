#include <stdio.h>

int factorial(int n) //16! == 2004189184 17! == -288522240 (int���)
{ 
	if(n == 0 || n == 1)
	return 1;
	else
	return n * factorial(n - 1);
}

int C(int n,int m)
{
	if(n < m)
	return -1;
	else
	{
		//Ϊ���������⣬�˴����Ǽ����Լ�֣��򻯼��� 
		//return factorial(n) / (factorial(n - m) * factorial(m)); ֱ����׳˻��������
		int temp = 1;
		if(n - m > m)
		{
			for(int i = n;i > n - m;i--)
			temp *= i;
			return temp / factorial(m);
		}
		else
		{
			for(int i = n;i > m;i--)
			temp *= i;
			return temp / factorial(n - m);
		}
	} 
	
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);//0<n<=20,0<=m<=n 
	printf("%d",C(n,m));
	return 0;
} 
