#include <stdio.h>
int main()
{
	int n,sum;
	scanf("%d",&n);
	int arr[3],num = n;
	for(int i = 0;i < 3;i++)
	{
		arr[i] = num % 10;
		num /= 10;
	}
	sum = arr[0] * arr[0] * arr[0] + arr[1] * arr[1] * arr[1] + arr[2] * arr[2] * arr[2];
	if(sum == n)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
	return 0;
} 
