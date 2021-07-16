#include <iostream>
#include <string>
using namespace std;

int compare(string num1,string num2)
{
	int len1 = num1.length(),len2 = num2.length();
	if(len1 > len2)return 1;//num1 > num2
	if(len1 < len2)return -1;//num1 < num2
	for(int i = 0;i < len1;i++)
	{
		int n1 = num1[i] - '0',n2 = num2[i] - '0';//字符转整 
		if(n1 > n2)return 1;
		if(n1 < n2)return -1;
	}
	return 0;//num1 == num2
}

string reverse(string s)
{
	int i = 0,j = s.length() - 1;
	while(i < j)
	{
		char t = s[i];
		s[i] = s[j];
		s[j] = t;
		i++,j--;
	}
	return s;
}

string add(string num1,string num2)
{
	string num;
	int len1 = num1.length(),len2 = num2.length(),bigger_len = len1 > len2 ? len1 : len2,incre = 0;	
	for(int i = 0;i < bigger_len;i++)
	{
		int a = 0,b = 0,c = 0;
		if(i < len1)a += num1[len1 - 1 - i] - '0';
		if(i < len2)b += num2[len2 - 1 - i] - '0';
		c = a + b + incre;
		if(c > 9)
		{
			incre = 1;
			num += char(c % 10 + '0');
			if(i == bigger_len - 1)num += '1';//首位进1 
		}
		else
		{
			incre = 0;
			num += char(c + '0');
		}
	}
	return reverse(num);
}

string multiply(string num1,string num2)
{
	if(num1 == "0" || num2 == "0")return "0";
	string res = "0";
	int len1 = num1.length(),len2 = num2.length();
	for(int i = 0;i < len2;i++)//num2 x num1 
	{
		string temp;
		for(int k = 0;k < i;k++)temp += '0';//补零 
		int b = num2[len2 - 1 - i] - '0',incre = 0;
		for(int j = len1 - 1;j >= 0;j--)
		{
			int a = num1[j] - '0';
			int c = b * a + incre;
			if(c > 9)
			{
				temp += char(c % 10 + '0');
				incre = c / 10;
				if(j == 0)temp += char(incre + '0');
			}
			else
			{
				temp += char(c + '0');
				incre = 0;
			}
		}
		res = add(res,reverse(temp));
	}
	return res;
}

string minus_(string num1,string num2)//num1 - num2 ，此处确保 num1 >= num2 
{
	string num;
	int r = compare(num1,num2);
	bool negative = false;
	if(r == 0)return "0";
	if(r == -1)
	{
		negative = true;
		string temp = num1;
		num1 = num2;
		num2 = temp;
		
	}
	int len1 = num1.length(),len2 = num2.length(),bigger_len = len1 > len2 ? len1 : len2,borrow = 0;
	for(int i = 0;i < bigger_len;i++)
	{
		int a = 0 - borrow,b = 0;
		if(i < len1)a += num1[len1 - 1 - i] - '0';
		if(i < len2)b += num2[len2 - 1 - i] - '0';
		if(a >= b)
		{
			borrow = 0;
			num += char(a - b + '0');
		}
		else
		{
			borrow = 1;
			num += char(10 + a - b + '0');
		}
	}
	num = reverse(num);
	while(num[0] == '0')//清除前导零 
	num.erase(0,1);//string.erase(pos,len)
	if(negative)return "-" + num;
	else return num;
}

string divide(string num1,string num2)//num1 / num2 = res 
{
	string res,num;
	int r = compare(num1,num2);
	if(r == -1)return "0";//cout << num1 << " / " << num2 << " = " << "0" << "..." << num1 << endl;
	if(r == 0)return "1";//cout << num1 << " / " << num2 << " = " << "1" << endl;
	int len1 = num1.length(),len2 = num2.length();
	int init_len = compare(num1.substr(0,len2),num2) >= 0 ? len2 : len2 + 1;
	num = num1.substr(0,init_len - 1);
	for(int i = init_len - 1;i < len1;i++)
	{
		num += num1[i];
		//cout << "num: " << num << endl; 
		if(compare(num,num2) >= 0)
		{
			for(int j = 1;j <= 9;j++)
			{
				string a,b;
				a += char(j + '0'),b += char(j + 1 + '0');
				string s1 = multiply(a,num2), s2 = multiply(b,num2);
				if(compare(num,s1) >= 0 && compare(num,s2) == -1)
				{
					//cout << "num: " << num << " s1: " << s1 << " s2: " << s2 << endl;
					res += char(j + '0');
					num = minus_(num,s1);
					if(num == "0")num = "";
				}
			}
		}
		else
		{
			res += '0';//除不够，商零 
			if(num == "0")num = "";//清除前导零 
		}
	}
	return res; 
}

int main()
{
	string left = "1",right,target,middle;
	cin >> target;right = target;
	while(compare(left,right) <= 0)
	{
		middle = divide(add(left,right),"2");
		//cout << "left: " << left << " middle: " << middle << " right: " << right << " target: " << target << endl;
		int r = compare(multiply(middle,middle),target);
		int r2 = compare(multiply(add(middle,"1"),add(middle,"1")),target);
		if(r == 0 || r <= 0 && r2 == 1)
		{
			cout << middle << endl;
			break;
		}
		if(r == 1)
		right = minus_(middle,"1");
		if(r == -1)
		left = add(middle,"1");
	}
	return 0;
} 
