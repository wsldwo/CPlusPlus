#include <stdio.h>
/*
greatest common divisor 最大公约数
least common multiple 最小公倍数
*/
int lcm(int a,int b)
{
	int start = a > b ? a:b;
	while(start % a != 0 || start % b != 0)
	{
		start++;
	}
	return start;
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	printf("%d",lcm(n,m));
	return 0;
} 
