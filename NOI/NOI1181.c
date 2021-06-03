#include <stdio.h>
/*
���ݷ� ,������ջģ�⣬����¼�ڵ��ֵ 
*/ 
void dfs(int in_stack_len,int stack_len,int *solutions)
{
	//printf("isl:%d sl:%d\n",in_stack_len,stack_len);
	if(in_stack_len == 0 && stack_len == 0)
	{
		//Ԫ���ſգ���ջ��ɣ���������һ 
		/*
		�мǣ�����ʹ�� *solutions ++��ԭ����++����������ȼ���*�������Ҫ�� 
		*/
		*solutions += 1; 
	}
	else
	{
		if(stack_len > 0)//��ջ 
		{
			dfs(in_stack_len,stack_len - 1,solutions);
		}
		if(in_stack_len > 0)//��ջ 
		{
			dfs(in_stack_len - 1,stack_len + 1,solutions);
		} 
	} 
}
/*
���ƹ�ʽ�� 

2����16λ����ȡֵ��Χ�ǣ�-32768 32767                              short 
2����32λ����ȡֵ��Χ�ǣ�-2147483648 2147483647                    int ��long��
2����64λ����ȡֵ��Χ�ǣ�-9223372036854775808 9223372036854775807  long long (__int64)

��������

����ͼ�����ֳƿ���������Ӣ����Catalan number���������ѧ��һ���������ڸ��ּ��������е����С�
���й��ɹ�����ѧ������ͼ (1692-1763)�ͱ���ʱ����ѧ��ŷ�ʡ����������� (1814�C1894)��������������
��ǰ����Ϊ���ӵ����ʼ�� : 1, 1, 2, 5, 14, 42, 132, 429, 1430, 4862, 16796, 58786, 208012, 742900, 
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
��������������f(4) = f(3) + f(2) * f(1) + f(1) * f(2) + f(3);
���������Ƕ���f(0) = 1�����ǣ�
f(4) = f(0)*f(3) + f(1)*f(2) + f(2) * f(1) + f(3)*f(0)=14
f(3)= f(0)*f(2) + f(1)*f(1) + f(2) * f(0)=5
f(2)=f(0)*f(1)+f(1)*f(0)=2
���� 
f(n) = f(0)*f(n-1) + f(1)*f(n-2) + ... + f(n-1)*f(0)
*/
int main()
{
	long long n,num[31];//num[31] = {0}����  num[31] = {1}������ 
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
