#include <iostream>
using namespace std;
struct box
{
	int x,y,z;//�����
} boxes[105];
int n;//������Ŀ
long long dp[105];//dp[i] ��ʾǰi�����ӿ��Դﵽ�����߶�
//dp[i] = max(dp[i - 1] + ��boxes[i]���в���, ��boxes[i]Ϊ�������߶�) 
void cal(int n)
{
	if(n == 1)
	{
		//x y z
		int h1 = z;
		//x z y
		int h2 = y;
		//y z x
		int h3 = x;
	}
} 
int main()
{
	cin>>n;
	for(int i = 1; i <= n; i++)
	cin>>boxes[i].x>>boxes[i].y>>boxes[i].z;

	return 0;
}
