#include <stdio.h>
/*
greatest common divisor ���Լ��
least common multiple ��С������
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
