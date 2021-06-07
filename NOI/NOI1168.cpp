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
		//����ÿһ��ħ����ֻ������ѡ�����A���߽���B
		//·��A
		int posA = 0;
		while(A[posA] != 0)
			posA++;
		A[posA] = CUBE[no];
		dfs(no + 1);
		A[posA] = 0;

		//·��B
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
������ı����ǣ������ַ�̯�ɺ���ӽ������ѣ����ʱ����Ǻͽϴ���Ƕѡ�
1���������������
2���ȷ���ϴ������A�ѣ��ٷ���С����B�ѣ�ֱ��B�ѳ���A��
3���ظ��ڶ�����ֱ���������ֶ�������
*/

void sort(int arr[],int size)//��д�����������
{
	for(int i = 1; i < size; i++) //�ӵڶ���Ԫ�ؿ�ʼ����ǰ����
	{
		int target = arr[i];
		for(int j = i - 1; j >= 0; j--)
		{
			if(arr[j] > target)//���ݺ���
			{
				arr[j + 1] = arr[j];
				if(j == 0)//��λ����
					arr[j] = target;
			}
			else
			{
				arr[j + 1] = target;//��ɲ���
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
��̬�滮 
dp[i][j]: ��ǰi����Ʒ��ѡ��һ����װ������Ϊj�ı����У����ܵõ������ֵ 
dp[i][j] = max(dp[i-1][j],dp[i-1][j-arr[i]]+arr[i]) 
*/ 

void fun()
{
	/*
	BUG001:ITEM����ҲӦ�ô�����1��ʼ�洢���ݣ� 
	*/
	int total_sum = sum_arr(ITEM,N + 1);
	int half_sum = total_sum / 2;
	int dp[N + 1][half_sum + 1];
	memset(dp,0,sizeof(dp));
	for(int i = 1;i <= N;i++)
	{
		for(int j = 1;j <= half_sum;j++)
		{
			//�����i����Ʒ��װ������
			dp[i][j] = dp[i - 1][j];
			//�����i����Ʒװ������
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
