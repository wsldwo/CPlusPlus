#include <iostream>
#define LEN 20
using namespace std;
int N,M,SOLU = 0,FRAME[LEN + 1][LEN + 1];//ȫ�������Զ���ʼ�� 

void dfs(int x,int y)
{
	if(x < N)
	{
		//�����
		if(FRAME[x + 1][y] == 0 || x + 1 == N)//С���У�������һ�������壬Ҳ�����ߣ�����ͨ�� 
		dfs(x + 1,y); 
		//���ұ�
		if(FRAME[x + 1][y + 1] == 0 || x + 1 == N)//С���У�������һ�������壬Ҳ�����ߣ�����ͨ�� 
		dfs(x + 1,y + 1);
	}
	else
	SOLU += 1;
}

int main()
{
	cin>>N>>M;
	int x,y;
	for(int i = 0; i < M; i++)
	{
		cin>>x>>y;
		FRAME[x][y] = 1;//��x�еĵ�y�������桱���ǡ����塱��
	}
	dfs(1,1);
	cout<<SOLU; 
	return 0;
}
