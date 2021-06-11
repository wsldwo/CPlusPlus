#include <iostream>
#include <algorithm>
using namespace std;
int N,TIME[100005];
long long DP[100005];
/*
�����ʮ�����ƴ�ǰ�ļ���С���������ֵ�Ͳ����ľ�ŵ���Ŀ��
�������ϵ��Ƶ������ŷ���ֻ�������ַ���֮�е�����
һ���������Ǹ��˴�һ��������Ҳ����Time[I]����Ϊ��ǰ���Ź�����Խ�������Խ������ͷ���������Ǹ����ٰѴ��ͻ�����
��һ����t[1]��t[2]һ���ȹ�ȥ����¼��t[2]��ʱ��һ�Σ�Ȼ��T[1]��������¼��T[1]��ʱ�䣬����������������ͷ��ȥ��Ҳ����T[I]��T[I-1]������T[2]�Ѵ��ͻ�����
�ۺ��������õ�״̬ת�Ʒ��̣�f[i]:=min(f[i-1]+time[1]+time[i],f[i-2]+time[1]+time[i]+time[2]*2);��ʼ����f[1]=a[1],f[2]=a[2]��

*/ 
//i:�˵ı�ţ���1��ʼ 
//����ǰi���˵����ٶɺ�ʱ�� 
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
//��������
void insert_sort(int arr[],int size,int start = 0)
{
	for(int i = start + 1;i < start + size;i++)//�ӵڶ���Ԫ����ǰ���� 
	{
		int temp = arr[i];
		for(int j = i - 1;j >= start;j--)//�Ӻ���ǰ����
		{
			if(arr[j] > temp)
			{
				arr[j + 1] = arr[j];//���ݺ���
				if(j == start)//�����������λ���� 
				arr[start] = temp; 
			}
			else
			{
				arr[j + 1] = temp;//����
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
	insert_sort(TIME,N,1);//������ 
	cout<<cal(N)<<endl;
	//system("pause");
	return 0;
} 
