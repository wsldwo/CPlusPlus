#include <iostream>
#include <string>
using namespace std;
string s1,s2;
string mul(string a,string b)//a * b
{
	if(a == "0" || b == "0")
	return "0";
	int len_a = a.length(),len_b = b.length();
	int s[2021] = {};//�洢��λs[0]��ʮλs[1]����λs[2]��ǧλs[3]...����ֵ
	for(int i = 0;i < len_b;i++)//��b��a 
	{
		int _b = b[len_b - 1 - i] - '0';
		for(int j = len_a - 1;j >= 0;j--)
		{
			int _a = a[j] - '0';
			s[len_a - 1 - j + i] += _a * _b;//��װ���������λ 
		}
	}
	//�����λ 
	for(int i = 0;i < len_a + len_b;i++)
	{
		int temp = s[i];
		s[i] = temp % 10;
		temp /= 10;
		int k = i + 1;
		while(temp > 0)
		{
			s[k] += temp % 10;
			temp /= 10;
			k++;
		}
	}
	int end = 2020;
	while(end >= 0 && s[end] == 0)//�ҵ�ĩβ 
	end--;
	string c;
	while(end >= 0)
	{
		c += char(s[end] + '0');
		end--;
	}
	return c;
}
int main()
{
	cin >> s1 >> s2;
	cout << mul(s1,s2) << endl; 
	return 0;
} 
