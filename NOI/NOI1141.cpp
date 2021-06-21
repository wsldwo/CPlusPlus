#include <iostream>
#include <string>
using namespace std;
string s1,s2;
int bigger(string a,string b)
{
	int is_a_bigger = 0;//0为相等，1为大于，-1为小于
	int len_a = a.length(),len_b = b.length();
	if(len_a > len_b)
		is_a_bigger = 1;
	else if(len_a == len_b)
	{
		for(int i = 0; i < len_a; i++)
		{
			if(a[i] - '0' > b[i] - '0')
			{
				is_a_bigger = 1;
				break;
			}
			if(a[i] - '0' < b[i] - '0')
			{
				is_a_bigger = -1;
				break;
			}
		}
	}
	else
		is_a_bigger = -1;
	return is_a_bigger;
}
string mul_int(string a,int b)//b为 1 ~ 9
{
	string c;
	int incre = 0;//进位
	for(int i = a.length() - 1; i >= 0; i--)
	{
		int r = (a[i] - '0') * b + incre;
		if(r > 9)
		{
			c += char((r % 10) + '0');
			incre = r / 10;
			if(i == 0)//首位进位
				c += char(incre + '0');
		}
		else
		{
			c += char(r + '0');
			incre = 0;
		}
	}
	//逆转
	int i = 0,j = c.length() - 1;
	while(i < j)
	{
		char ch = c[i];
		c[i] = c[j];
		c[j] = ch;
		i++,j--;
	}
	return c;
}
string subb(string a,string b)//a - b  这里确保 a >= b
{
	if(bigger(a,b) == 0)
		return "0";
	else
	{
		int len_a = a.length(),len_b = b.length();
		int i = len_a - 1,j = len_b - 1,borrow = 0;
		string c;
		while(i >= 0 || j >= 0)
		{
			int _a = a[i] - '0' - borrow;
			int _b = 0;
			if(j >= 0)
				_b += b[j] - '0';
			if(_a >= _b)
			{
				c += char((_a - _b) + '0');
				borrow = 0;
			}
			else
			{
				c += char((10 + _a - _b) + '0');
				borrow = 1;
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
		//清除前导零
		while(c[0] == '0')
		c.erase(0,1);// erase(pos,n) 
		return c;
	}
}
void div(string a,string b)// a / b = c ... d
{
	//首先，比较a、b大小
	int is_a_bigger = bigger(a,b);
	//然后，根据a b大小，进行除法
	if(is_a_bigger == 0)
		cout << "1" << endl << "0" << endl;
	else if(is_a_bigger == 1)
	{
		int len_a = a.length(),len_b = b.length();
		string bc = a.substr(0,len_b - 1);//余数初始化  string substr(pos,n)
		string c;//c为商
		for(int i = len_b - 1; i < len_a; i++)
		{
			bc += a[i];//降位
			if(bigger(bc,b) < 0)
			{
				c += '0';
			}
			else
			{
				for(int j = 1; j < 10; j++)
				{
					string bj = mul_int(b,j),bjo = mul_int(b,j + 1);
					if(bigger(bj,bc) <= 0 && bigger(bjo,bc) == 1)
					{
						c += char(j + '0');
						string s = subb(bc,bj);
						if(s == "0")
							bc.clear();
						else
							bc = s;
						break;
					}
				}
			}
		}
		//清除前导零
		while(c[0] == '0')
		c.erase(0,1);// erase(pos,n)
		if(bc.empty())
		bc = "0";
		cout << c << endl << bc << endl; 
	}
	else
		cout << "0" << endl << a << endl;
}

int main()
{
	cin >> s1 >> s2;
	div(s1,s2);
	return 0;
}
