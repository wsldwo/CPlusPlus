#include <iostream>
#include <string>
using namespace std;

int N,M;//N行  M列 
//long long DP[810][810];//DP[i][j]表示从左下角走到坐标为（x,y）最短走法的种数 
string DPS[810][810];
/*
long long 越界
wrong answer diff :858110510779117752 : 25477612258980856902730428600 
需要使用大数加法 
*/ 

char tochar(int n)
{
	switch(n)
	{
		case 0 : return '0';
		case 1 : return '1';
		case 2 : return '2';
		case 3 : return '3';
		case 4 : return '4';
		case 5 : return '5';
		case 6 : return '6';
		case 7 : return '7';
		case 8 : return '8';
		case 9 : return '9';
	}
}

void reverse(string &s)//必须使用引用传递，否则不生效 
{
	int i = 0,j = s.length() - 1;
	while(i < j)
	{
		char c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
}

string add(string a, string b)
{
	int len_a = a.length(),len_b = b.length();
	int i = len_a - 1,j = len_b - 1,incre = 0;
	string c;
	while(i >= 0 || j >= 0)
	{
		int r = incre;
		if(i >= 0)
		r += a[i] - 48;//字符转整只需减去48（0的ascii码） 
		if(j >= 0)
		r += b[j] - 48;//字符转整只需减去48（0的ascii码） 
		if(r >= 10)
		{
			c += tochar(r % 10);
			incre = 1;
			if(i <= 0 && j <= 0)//首位进位 
			{
				c += '1';
			}
		} 
		else
		{
			c += tochar(r);
			incre  = 0; 
		}
		i--;
		j--;
		//cout << "c:" << c << endl;
	}
	//c += '\0';//好像不用加结束符 
	reverse(c);
	//cout << a << " + " << b << " = " << c << endl;
	return c;
}
/*
void cal()//long long越界 40分 
{
	for(int i = N;i >= 1;i--)
	{
		for(int j = 1;j <= M;j++)
		{
			if(j == 1)//边界情况
			DP[i][j] = 1;
			else if(i == N)//边界情况
			DP[i][j] = 1;
			else//然后，通过状态转移方程计算每一步的值 
			DP[i][j] = DP[i][j - 1] + DP[i + 1][j];
		}
	}
	cout <<"cal :"<< DP[1][M] << endl;
}
*/
void cal2()//时间超限 70分 
{
	for(int i = N;i >= 1;i--)
	{
		for(int j = 1;j <= M;j++)
		{
			if(j == 1 || i == N)//边界情况
			DPS[i][j] = "1";
			else if(i + j < N + 1) //斜率为1 可以优化 4.05s -----> 2.26s
			DPS[i][j] = DPS[N + 1 - j][N + 1 - i];
			else//然后，通过状态转移方程计算每一步的值 
			DPS[i][j] = add(DPS[i][j - 1],DPS[i + 1][j]);
		}
	}
	cout << DPS[1][M] << endl;
}

int main()
{
	//cin >> M >> N;
	M = 800;
	N = 800;
	if(M < N)//只求解 M >= N 的情况，因为DP[I][J] == DP[J][I] 
	{
		int temp = M;
		M = N;
		N = temp;
	}
	//cal();
	cal2();
	return 0;
} 
