#include <iostream>
#include <string>
using namespace std;
string s1,s2;
string add(string a,string b)//a + b
{
	string c;
	int len_a = a.length(),len_b = b.length();
	int i = len_a - 1,j = len_b - 1;
	int incre = 0;
	while(i >= 0 || j >= 0)
	{
		int r = incre;
		if(i >= 0)
		r += a[i] - '0';
		if(j >= 0)
		r += b[j] - '0';
		if(r >= 10)
		{
			c += char((r % 10) + '0');
			incre = 1;
			if(i <= 0 && j <= 0)//首位进位 
			c += '1';
		}
		else
		{
			c += char(r + '0');
			incre = 0;
		}
		i--,j--; 
	}
	//逆转
	i = 0,j = c.length() - 1;
	while(i < j)
	{
		char ch = c[i];
		c[i] = c[j];
		c[j] = ch;
		i++,j--;
	} 
	return c;
}
int main()
{
	cin >> s1 >> s2;
	cout << add(s1,s2) << endl;
	return 0;
}
