#include <stdio.h>
int is_prime_num(int n)
{
	for(int i = 2;i < n;i++)
	{
		if(n % i == 0)
		return 0;//C������0Ϊ�٣�����Ϊ�� 
	} 
	return 1;//C������0Ϊ�٣�����Ϊ�� 
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i = 2;i <= n - 2;i++)//Ҫ���ҳ�������������������n
	{
		if(is_prime_num(i) && is_prime_num(i + 2))
		printf("%d %d\n",i,i + 2);
	}
	return 0;
}
