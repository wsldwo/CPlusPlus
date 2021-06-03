#include <stdio.h>
int num[31];//全局变量 
int Fibonacci(int n)
{
	num[1] = 0;
	num[2] = 1;
	for(int i = 3;i <= n;i++)
	num[i] = num[i - 1] + num[i - 2];
	return num[n];
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%d",Fibonacci(n));
	return 0;
}
