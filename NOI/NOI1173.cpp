#include <iostream>
#define DATA_LENGTH 1000
using namespace std;
/*
��1������һ��������N<1000000��
��2����N+1�У�ÿ��2��������x��y����ʾҪ���������  ����֤x>=y�� x<1000��
N�У�ÿ��һ������� �����ڴ𰸿��ܴܺ������ģ10007�Ľ����
����������ǵ��������
*/
int COMBINE[DATA_LENGTH + 10][DATA_LENGTH + 10];//�洢����������� 
//�ݹ鷨����
int cal(int x,int y)
{
	//cout<<"x:"<<x<<"y:"<<y<<endl;
	if(y == 0 || x == y)
		return 1;
	if(y == 1)
		return x;
	return (cal(x - 1,y - 1) + cal(x - 1,y)) % 10007;
}
//������
//x:���� 
void cal2(int x)
{
	//int line[1010];//lineΪ������ǵ�ÿһ��
	//line[0] = 1;
	COMBINE[0][0] = 1;
	for(int i = 1; i <= x; i++)
	{
		COMBINE[i][0] = 1;//��ͷΪ1 
		int temp[DATA_LENGTH + 10];
		for(int j = 1; j < i; j++ )
		{
			temp[j] = (COMBINE[i - 1][j - 1] + COMBINE[i - 1][j]) % 10007;//���ȡģ�����ڲ���ȡģ �������Ǽӷ����ǳ˷� 
		}
		for(int j = 1; j < i; j++ )
		{
			COMBINE[i][j] = temp[j];
		}
		COMBINE[i][i] = 1;//��βΪ1 
		//��ӡ
		/*
		for(int j = 0; j <= i; j++ )
		{
			cout<<line[j]<<" "; 
		}
		cout<<endl;
		*/
	}
}
int main()
{
	int n,x,y;
	cin>>n;
	cal2(1000); 
	for(int i = 0; i < n; i++)
	{
		cin>>x>>y;
		cout<<COMBINE[x][y]<<endl;
	}
	return 0;
}
