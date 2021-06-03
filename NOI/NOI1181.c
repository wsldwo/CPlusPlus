#include <stdio.h>
/*
回溯法 ,精简版出栈模拟，不记录节点的值 
*/ 
void dfs(int in_stack_len,int stack_len,int *solutions)
{
	//printf("isl:%d sl:%d\n",in_stack_len,stack_len);
	if(in_stack_len == 0 && stack_len == 0)
	{
		//元素排空，出栈完成，方案数加一 
		/*
		切记，不可使用 *solutions ++，原因是++运算符的优先级比*运算符还要高 
		*/
		*solutions += 1; 
	}
	else
	{
		if(stack_len > 0)//出栈 
		{
			dfs(in_stack_len,stack_len - 1,solutions);
		}
		if(in_stack_len > 0)//入栈 
		{
			dfs(in_stack_len - 1,stack_len + 1,solutions);
		} 
	} 
}
/*
递推公式法 

2进制16位整数取值范围是：-32768 32767                              short 
2进制32位整数取值范围是：-2147483648 2147483647                    int （long）
2进制64位整数取值范围是：-9223372036854775808 9223372036854775807  long long (__int64)

卡特兰数

明安图数，又称卡塔兰数，英文名Catalan number，是组合数学中一个常出现于各种计数问题中的数列。
以中国蒙古族数学家明安图 (1692-1763)和比利时的数学家欧仁·查理·卡塔兰 (1814–1894)的名字来命名，
其前几项为（从第零项开始） : 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 
2674440, 9694845, 35357670, 129644790, 477638700, 1767263190, 6564120420, 24466267020, 91482563640, 
343059613650, 1289904147324, 4861946401452, ...
*/
long long cal(long long n,long long num[31])
{
	for(int i = 2;i <= n;i++)
	{
		long long temp = 0;
		for(int j = 0,k = i - 1;j < i;j++,k--)
		{
			temp += num[j] * num[k];
		}
		num[i] = temp;
	}
	return num[n];
} 
/*
结合所有情况，即f(4) = f(3) + f(2) * f(1) + f(1) * f(2) + f(3);
规整化我们定义f(0) = 1；于是：
f(4) = f(0)*f(3) + f(1)*f(2) + f(2) * f(1) + f(3)*f(0)=14
f(3)= f(0)*f(2) + f(1)*f(1) + f(2) * f(0)=5
f(2)=f(0)*f(1)+f(1)*f(0)=2
即， 
f(n) = f(0)*f(n-1) + f(1)*f(n-2) + ... + f(n-1)*f(0)
*/
int main()
{
	long long n,num[31];//num[31] = {0}管用  num[31] = {1}不管用 
	num[0] = 1,num[1] = 1;
	scanf("%lld",&n);
	printf("%lld\n",cal(n,num));
	/*
	for(int i = 0;i <= 30;i++)
	{
		printf("%ld\n",cal(i,num));
	}
	*/
	return 0;
} 
