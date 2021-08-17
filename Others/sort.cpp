#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
/*
default_random_engine re(time(0));
uniform_int_distribution <unsigned> dis(0,10);//������
for(int i = 0;i < 10;i++)
cout << dis(re) << " ";
*/

void quick_sort_recursive(int arr[],int l,int r)//��·����
{
	if(l < r)
	{
		swap(arr[l],arr[l + rand() % (r - l + 1)]);//���ѡȡpivot
		int pivot = arr[l],i = l + 1,lt = l,gt = r + 1;//iΪ���������������ӵڶ���λ�ÿ�ʼ����Ϊ��һ��λ����������pivot����ltָ��С��pivot�����һ��Ԫ�أ�gtָ�����pivot�ĵ�һ��Ԫ��
		while(i < gt)//��ֹ����i == gt
		{
			if(arr[i] < pivot)
			{
				swap(arr[i],arr[lt + 1]);
				lt++,i++;//��ʱ��Ҫi++����Ϊ���������������Ѿ�ȷ�Ϲ���
			}
			else if(arr[i] == pivot)i++;
			else
			{
				swap(arr[i],arr[gt - 1]);
				gt--;//��ʱ����i++����Ϊ��������������δ֪��
			}
		}
		swap(arr[l],arr[lt]);//���Ҫ���ˣ���pivot������ltĩβ
		quick_sort_recursive(arr,l,lt - 1);
		quick_sort_recursive(arr,gt,r);
	}
}

void quick_sort(int arr[],int arr_size)
{
	quick_sort_recursive(arr,0,arr_size - 1);
}

void merge_sort_recursive(int arr[],int arr_copy[],int l,int r)//�鲢���� (�ݹ�)
{
	if(l < r)
	{
		int start1 = l,end1 = (l + r) / 2,start2 = end1 + 1,end2 = r,k = l;
		merge_sort_recursive(arr,arr_copy,start1,end1);
		merge_sort_recursive(arr,arr_copy,start2,end2);
		while(start1 <= end1 && start2 <= end2)
			arr_copy[k++] = arr[start1] < arr[start2] ? arr[start1++] : arr[start2++];
		while(start1 <= end1)
			arr_copy[k++] = arr[start1++];
		while(start2 <= end2)
			arr_copy[k++] = arr[start2++];
		for(int i = l; i <= r; i++)
			arr[i] = arr_copy[i];
	}
}

void merge_sort(int arr[],int arr_size)//�鲢����
{
	int copy[arr_size] = {};//�������� 
	merge_sort_recursive(arr,copy,0,arr_size - 1);
}

void insert_sort(int arr[],int arr_size)//��������
{
	for(int i = 1;i < arr_size;i++)
	{
		int target = arr[i];
		for(int j = i - 1;j >= 0;j--)
		{
			if(arr[j] > target)
			{
				arr[j + 1] = arr[j];
				if(j == 0)arr[j] = target;//��λ���� 
			}
			else//arr[j] <= target 
			{
				arr[j + 1] = target;//���� 
				break;
			} 
		}
	}
} 

int main()
{
	int arr[20] = {-100,70,990,3,-50,99,70,33,-78,666,8888,-4,70,-990,100,-100,99,700,33,666};
	srand((unsigned)time(NULL));
	quick_sort(arr,20);
	//merge_sort(arr,20);
	//insert_sort(arr,20);
	for(int i = 0; i < 20; i++)
		cout << arr[i] << " ";
	return 0;
}
