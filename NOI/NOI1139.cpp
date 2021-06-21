#include <iostream>
#include <string>
using namespace std;
string s1,s2;
string sub(string a,string b)//a - b
{
	//首先，需要比较a和b的大小，a若小于b，需要转化为 -（b - a） 
	int len_a = a.length(),len_b = b.length();
	int is_a_bigger = 0;//0为相等 
	if(len_a > len_b)
	is_a_bigger = 1;//1为大于 
	else if(len_a == len_b)
	{
		for(int i = 0;i < len_a;i++)
		{
			if(a[i] - '0' > b[i] - '0')
			{
				is_a_bigger = 1;
				break;
			}
			else if(a[i] - '0' < b[i] - '0')
			{
				is_a_bigger = -1;
				break;
			} 
		}
	}
	else
	is_a_bigger = -1;//-1为小于 
	//然后，开始计算 a - b
	if(is_a_bigger == 0)
	return "0";
	else if(is_a_bigger == -1)//若a较小，则交换a、b 
	{
		string t = a;
		a = b;
		b = t;
		int temp = len_a;//长度也必须交换！！！ 
		len_a = len_b;
		len_b = temp;
	}
	string c;
	int borrow = 0;//借位
	int i = len_a - 1,j = len_b - 1;
	while(i >= 0 || j >= 0)
	{
		int _a = a[i] - '0' - borrow;
		int _b = 0;
		if(j >= 0)//数b可能没有数a长 
		_b += b[j] - '0'; 
		if(_a >= _b)
		{
			c += char((_a - _b) + '0');
			borrow = 0;
		}
		else
		{
			c += char((10 + _a - _b) + '0');
			borrow = 1;//高位借一
		}
		i--,j--; 
	}
	//最后，逆转c 
	i = 0,j = c.length() - 1;
	while(i < j)
	{
		char ch = c[i];
		c[i] = c[j];
		c[j] = ch;
		i++,j--;
	} 
	//消除前导0
	while(c[0] == '0')
	c.erase(0,1);//string.erase(pos,n) 删除从pos开始的n个字符
	if(is_a_bigger == -1)
	c = "-" + c;//补上负号 
	return c;
}
int main()
{
	cin >> s1 >> s2;
	cout << sub(s1,s2) << endl;
	return 0;
}
