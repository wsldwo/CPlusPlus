#include <iostream>
#define DATA_LENGTH 1000
using namespace std;
/*
第1行输入一个正整数N<1000000。
第2到第N+1行，每行2个正整数x和y，表示要计算组合数  ，保证x>=y， x<1000。
N行，每行一个组合数 ，由于答案可能很大，输出答案模10007的结果。
根据杨辉三角递推组合数
*/
int COMBINE[DATA_LENGTH + 10][DATA_LENGTH + 10];//存储整个杨辉三角 
//递归法很慢
int cal(int x,int y)
{
	//cout<<"x:"<<x<<"y:"<<y<<endl;
	if(y == 0 || x == y)
		return 1;
	if(y == 1)
		return x;
	return (cal(x - 1,y - 1) + cal(x - 1,y)) % 10007;
}
//迭代法
//x:行数 
void cal2(int x)
{
	//int line[1010];//line为杨辉三角的每一行
	//line[0] = 1;
	COMBINE[0][0] = 1;
	for(int i = 1; i <= x; i++)
	{
		COMBINE[i][0] = 1;//开头为1 
		int temp[DATA_LENGTH + 10];
		for(int j = 1; j < i; j++ )
		{
			temp[j] = (COMBINE[i - 1][j - 1] + COMBINE[i - 1][j]) % 10007;//结果取模，等于步步取模 ，无论是加法还是乘法 
		}
		for(int j = 1; j < i; j++ )
		{
			COMBINE[i][j] = temp[j];
		}
		COMBINE[i][i] = 1;//结尾为1 
		//打印
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
