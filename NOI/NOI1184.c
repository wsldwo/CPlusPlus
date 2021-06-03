#include <stdio.h>
/*
len_a:5Ԫ��������
len_b:10Ԫ��������
shop_5:�̵�5Ԫ���� 
�˺�����a�ӡ�b�ӵ��˵�����ȫ��ͬ��(��ȫһ����)��������
���ս����Ҫ���� n!��a��ȫ���У� * n! ��b��ȫ���У�
*/
int factorial(int n)
{
	if(n == 0 || n == 1)return 1;
	else return factorial(n - 1) * n;
}
void dfs(int len_a,int len_b,int shop_5,long long *solutions)
{
	if(len_a == 0 && len_b == 0)
	{
		*solutions += 1;
	}
	else
	{
		if(shop_5 > 0 && len_b > 0)
			dfs(len_a,len_b - 1,shop_5 - 1,solutions);//10Ԫ����
		if(len_a > 0)
			dfs(len_a - 1,len_b,shop_5 + 1,solutions);//5Ԫ���� 
	} 
}
int main()
{
	int n;
	scanf("%d",&n);
	long long ans,solutions = 0;
	dfs(n,n,0,&solutions);
	//printf("%lld   %d   ",solutions,factorial(n));
	/*
	// n = 9 , n = 10 ��� ����취
	Ҫʹ���ս������Ϊlong long����ô�������ı���������ǿ������ת��Ϊlong long 
	*/
	ans = (long long)factorial(n) * (long long)factorial(n) * solutions;//n!��a��ȫ���У� * n! ��b��ȫ���У�
	printf("%lld",ans);
	return 0;
}
