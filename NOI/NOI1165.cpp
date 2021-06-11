#include <iostream>
#define LEN 1001
using namespace std;
int N,M,R,C;
int danmaku[LEN][LEN];//��������ö���Ϊȫ�ֱ�������������ʱ���� 
long long area[LEN][LEN],SCORE = 0;
void f()
{
	//Ԥ�����������ÿһ����Ϊ���½ǣ������Ͻǵ����ֵ�� 
	for(int i = 1;i <= N;i++)
	{
		for(int j = 1;j <= M;j++)
		{
			area[i][j] = danmaku[i][j] + area[i - 1][j] + area[i][j - 1] - area[i - 1][j - 1];
		}
	}
	//ö��ÿһ��RxC�ľ��ε����
	for(int i = R;i <= N;i++)
	{
		for(int j = C;j <= M;j++)
		{
			long long s = area[i][j] + area[i - R][j - C] - area[i - R][j] - area[i][j - C];
			if(s > SCORE)
			SCORE = s; 
		}
	}
}
int main()
{
	cin>>N>>M>>R>>C;
	for(int i = 1;i <= N;i++)//���ݴ洢��ʱ���1��ʼ��ı�0Ҫ�����״��� 
	{
		for(int j = 1;j <= M;j++)
		{
			cin>>danmaku[i][j];
		}
	}
	f();
	cout<<SCORE<<endl;
	return 0;
} 
