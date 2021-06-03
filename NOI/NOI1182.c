#include <stdio.h>
long long cal(int n)
{
	long long num[33];
	num[2] = 1,num[3] = 1;
	for(int i = 4;i <= n;i++)
	{
		num[i] = 0;
		for(int j = 2;j <= i - 1;j++)
      	{
      		num[i] = num[j] * num[i - j + 1] + num[i];//又是卡特兰数！！！ 
     	}
	}
	return num[n];
}
int main()
{
	int n;
	scanf("%d",&n);
	printf("%lld",cal(n));
	return 0;
}
