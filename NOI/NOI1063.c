#include <stdio.h>

int factorial(int n) //16! == 2004189184 17! == -288522240 (int溢出)
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
		//为解决溢出问题，此处考虑加入简单约分，简化计算 
		//return factorial(n) / (factorial(n - m) * factorial(m)); 直接算阶乘会结果会溢出
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
