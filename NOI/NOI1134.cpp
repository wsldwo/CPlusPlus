#include <iostream>
#include <algorithm>
using namespace std;
int n,a,b,c[500005],ci,t;// a 自然烘干 b 机器烘干 ci 已修改索引 
void f()
{
	ci = n;
	//思考漏洞：衣服未必要完全烘干，中途可以切换其它湿度更大的衣服！！
	for(int i = n; i >= 1;)
	{
		if(c[i] <= 0)
			break;
		/*
		cout << "before:  ";
		for(int j = i; j >= i - 6; j--)
			if(j >= 1)
				cout << " c[" << j <<"]: " << c[j];
		cout << endl;
		*/
		int x = (c[i] - c[i - 1]) / b + 1;//有点问题,会出现 c[i] < c[i-1] 的情况 
		if(c[i] - (a + b) * (x-1) <= 0 && c[i - 1] - a * (x-1) <= 0 )x -= 1;//x修正 
		t += x;
		c[i] -= (a + b) * x;
		//for(int j = i - 1; j >= 1; j--)
			//c[j] -= a * x;
		//将c[i]插入到合适位置   //sort(c + 1,c + 1 + n);
		int y = c[i];
		
		for(int j = i - 1; j >= 1; j--)
		{
			//c[j] = j >= ci ? c[j] - a * x:c[j] - a * t;
			if(j >= ci)
			{
				c[j] -= a * x;
			}
			else
			{
				c[j] -= a * t;
				ci = j;//更新ci 
			}
			//cout << "ci:" << ci  << " y:" << y << " t:" << t << " x: " << x << endl;
			if(c[j] > y)
			{
				c[j + 1] = c[j];
				if(j == 1)
					c[j] = y;
			}
			else
			{
				c[j + 1] = y;
				
				for(int p = j - 1;p >= ci;p--)//bug fix，这个bug太难发现了 
				c[p] -= a * x;
				 
				break;
			}
		}
		/*
		cout << "after:  ";
		for(int j = i; j >= i - 6; j--)
			if(j >= 1)
				cout << " c[" << j <<"]: " << c[j];
		cout << endl;
		*/
	}
	cout << t << endl;
}
int main()
{
	cin >> n >> a >> b;
	for(int i = 1; i <= n; i++)
		cin >> c[i];
	sort(c + 1,c + 1 + n);//sort(start,start+size,compare)
	f();
	return 0;
}
