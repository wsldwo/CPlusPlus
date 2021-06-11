#include <iostream>
#define LEN 1001
using namespace std;
int N,M,R,C;
int danmaku[LEN][LEN];//大数组最好定义为全局变量，避免运行时错误 
long long area[LEN][LEN],SCORE = 0;
void f()
{
	//预处理：计算出以每一个点为右下角，到左上角的面积值。 
	for(int i = 1;i <= N;i++)
	{
		for(int j = 1;j <= M;j++)
		{
			area[i][j] = danmaku[i][j] + area[i - 1][j] + area[i][j - 1] - area[i - 1][j - 1];
		}
	}
	//枚举每一个RxC的矩形的面积
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
	for(int i = 1;i <= N;i++)//数据存储有时候从1开始真的比0要更容易处理 
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
