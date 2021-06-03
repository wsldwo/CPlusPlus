#include <stdio.h>
/*
卡特兰数 其前几项为（从第零项开始） : 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900,
*/ 
long long cal(int n,long long num[31])
{
	for(int i = 2;i <= n;i++)
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
	long long num[31];//num[31] = {0}管用  num[31] = {1}不管用 
	num[0] = 1,num[1] = 1;
	scanf("%d",&n);
	printf("%lld\n",cal(n,num));
	return 0;
} 
