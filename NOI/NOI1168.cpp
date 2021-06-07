#include <iostream>
#include <cstring>
#define LEN 105
using namespace std;
int N,CUBE[LEN + 1],ITEM[LEN + 1],A[LEN + 1],B[LEN + 1];
int LEAST_TIME = 0,ANS_A[LEN + 1],ANS_B[LEN + 1];

int sum(int arr[])
{
	int temp = 0,pos = 0;
	while(arr[pos] != 0)
	{
		temp += arr[pos];
		pos++;
	}
	return temp;
}

void copy(int a[],int b[])
{
	int pos = 0;
	while(b[pos] != 0)
	{
		a[pos] = b[pos];
		pos++;
	}
	a[pos] = 0;
}

void print_arr(int arr[])
{
	int pos = 0;
	while(arr[pos] != 0)
	{
		cout<<arr[pos]<<" ";
		pos++;
	}
	cout<<endl;
}

void dfs(int no)
{
	if(no < N)
	{
		//对于每一个魔方，只有两个选择进入A或者进入B
		//路线A
		int posA = 0;
		while(A[posA] != 0)
			posA++;
		A[posA] = CUBE[no];
		dfs(no + 1);
		A[posA] = 0;

		//路线B
		int posB = 0;
		while(B[posB] != 0)
			posB++;
		B[posB] = CUBE[no];
		dfs(no + 1);
		B[posB] = 0;
	}
	else
	{
		int sum_a = sum(A),sum_b = sum(B);
		int t = sum_a > sum_b ? sum_a : sum_b;
		if(LEAST_TIME == 0 || t < LEAST_TIME)
		{
			LEAST_TIME = t;
			copy(ANS_A,A);
			copy(ANS_B,B);
		}
	}
}
/*
该问题的本质是，把数字分摊成和最接近的两堆，完成时间就是和较大的那堆。
1、对数组进行排序
2、先分配较大的数到A堆，再分配小数到B堆，直至B堆超过A堆
3、重复第二步，直到所有数字都被分配
*/

void sort(int arr[],int size)//就写个插入排序吧
{
	for(int i = 1; i < size; i++) //从第二个元素开始，向前插入
	{
		int target = arr[i];
		for(int j = i - 1; j >= 0; j--)
		{
			if(arr[j] > target)//数据后移
			{
				arr[j + 1] = arr[j];
				if(j == 0)//首位插入
					arr[j] = target;
			}
			else
			{
				arr[j + 1] = target;//完成插入
				break;
			}
		}
	}
}

int max(int a,int b)
{
	return a > b ? a : b;
}

int sum_arr(int arr[],int size)
{
	int res = 0;
	for(int i = 0;i < size;i++)
	res += arr[i];
	return res;
}
/*
动态规划 
dp[i][j]: 在前i件物品中选择一部分装入容量为j的背包中，所能得到的最大值 
dp[i][j] = max(dp[i-1][j],dp[i-1][j-arr[i]]+arr[i]) 
*/ 

void fun()
{
	/*
	BUG001:ITEM数组也应该从索引1开始存储数据！ 
	*/
	int total_sum = sum_arr(ITEM,N + 1);
	int half_sum = total_sum / 2;
	int dp[N + 1][half_sum + 1];
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= N;i++)
	{
		for(int j = 1;j <= half_sum;j++)
		{
			//如果第i件物品不装进背包
			dp[i][j] = dp[i - 1][j];
			//如果第i件物品装进背包
			if(ITEM[i] <= j && dp[i - 1][j - ITEM[i]] + ITEM[i] > dp[i][j])
			dp[i][j] = dp[i - 1][j - ITEM[i]] + ITEM[i];
		}
	}
	cout<<total_sum - dp[N][half_sum]<<endl;
}

int main()
{
	cin>>N;
	for(int i = 0; i < N; i++)
	{
		cin>>CUBE[i];
		ITEM[i + 1] = CUBE[i];
	}
	/* 
	dfs(0);
	print_arr(ANS_A);
	print_arr(ANS_B);
	cout<<LEAST_TIME<<endl;
	*/
	fun();
	//print_arr(A);
	//print_arr(B);
	//cout<<LEAST_TIME<<endl;
	return 0;
}
