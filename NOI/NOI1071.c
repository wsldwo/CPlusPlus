#include <stdio.h>
int pell(int k)
{
	if(k == 1)return 1;
	if(k == 2)return 2;
	int a = 1,b = 2,c;//a,b始终对应当前项的前前一项和前一项,c为当前项 
	for(int i = 3;i <= k;i++)
	{
		/*
		简直是太秒了，把大数取模转化为中间结果取模 
		a = b + c + d + e + ...  a % 32767 = b % 32767 + c % 32767
		*/ 
		c = (2 * b + a) % 32767;
		a = b;
		b = c;
	}
	return c; 
}
int main()
{
	int n,N[10];
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d",&N[i]);
	} 
	for(int i = 0;i < n;i++)
	{
		printf("%d\n",pell(N[i]));//又是int溢出，pell(25) == 1311738121，pell(26)就溢出了 
	} 
	return 0;
} 
