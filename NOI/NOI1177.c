#include <stdio.h>
long long cal(int n)
{
	if(n < 4)
	return n;
	else
	{
		long long a = 2,b = 3;
		for(int i = 4;i <= n;i++)
		{
			long long c = a + b;
			a = b;
			b = c;
		}
		return b;
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	printf("%lld",cal(n));
	return 0;
} 
