#include <iostream>
#include <algorithm>
using namespace std;
int N,TIME[100005];
long long DP[100005];
/*
这题就十分类似此前的几个小盆友拿着手电筒过独木桥的题目。
经过不断的推导，最优方法只能在两种方法之中诞生，
一种是最快的那个人带一个最慢的也就是Time[I]（因为先前快排过所以越后面就是越慢的老头），最快的那个人再把船送回来；
另一种是t[1]和t[2]一起先过去，记录了t[2]的时间一次，然后T[1]回来，记录了T[1]的时间，再让两个最慢的老头过去，也就是T[I]和T[I-1]，再让T[2]把船送回来。
综合起来，得到状态转移方程：f[i]:=min(f[i-1]+time[1]+time[i],f[i-2]+time[1]+time[i]+time[2]*2);初始化是f[1]=a[1],f[2]=a[2]；

*/ 
//i:人的编号，从1开始 
//计算前i个人的最少渡河时间 
long long cal(int i)
{
	/*
	if(i == 1 || i == 2)return TIME[i];
	return min(cal(i - 1) + TIME[1] + TIME[i],cal(i - 2) + TIME[1] + TIME[i] + TIME[2] * 2);
	*/ 
	if(i == 1 || i == 2)return TIME[i];
	int j = 3;
	DP[1] = TIME[1],DP[2] = TIME[2];
	while(j <= i)
	{
		DP[j] = min(DP[j - 1] + TIME[1] + TIME[j],DP[j - 2] + TIME[1] + TIME[j] + TIME[2] * 2);
		j++;
	}
	return DP[i];
}
//插入排序
void insert_sort(int arr[],int size,int start = 0)
{
	for(int i = start + 1;i < start + size;i++)//从第二个元素向前插入 
	{
		int temp = arr[i];
		for(int j = i - 1;j >= start;j--)//从后向前插入
		{
			if(arr[j] > temp)
			{
				arr[j + 1] = arr[j];//数据后移
				if(j == start)//特殊情况，首位插入 
				arr[start] = temp; 
			}
			else
			{
				arr[j + 1] = temp;//插入
				break; 
			} 
		} 
	}
} 
int main()
{
	cin>>N;
	for(int i = 1;i <= N;i++)
	cin>>TIME[i];
	insert_sort(TIME,N,1);//先排序 
	cout<<cal(N)<<endl;
	//system("pause");
	return 0;
} 
