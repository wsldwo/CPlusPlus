#include <stdio.h>
int is_prime_num(int n)
{
	for(int i = 2;i < n;i++)
	{
		if(n % i == 0)
		return 0;//C语言中0为假，非零为真 
	} 
	return 1;//C语言中0为假，非零为真 
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 2;i <= n - 2;i++)//要求找出所有两个数均不大于n
	{
		if(is_prime_num(i) && is_prime_num(i + 2))
		printf("%d %d\n",i,i + 2);
	}
	return 0;
}
