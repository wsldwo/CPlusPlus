#include <iostream>
#include <string>
using namespace std;
string s1,s2;
string sub(string a,string b)//a - b
{
	//���ȣ���Ҫ�Ƚ�a��b�Ĵ�С��a��С��b����Ҫת��Ϊ -��b - a�� 
	int len_a = a.length(),len_b = b.length();
	int is_a_bigger = 0;//0Ϊ��� 
	if(len_a > len_b)
	is_a_bigger = 1;//1Ϊ���� 
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
	is_a_bigger = -1;//-1ΪС�� 
	//Ȼ�󣬿�ʼ���� a - b
	if(is_a_bigger == 0)
	return "0";
	else if(is_a_bigger == -1)//��a��С���򽻻�a��b 
	{
		string t = a;
		a = b;
		b = t;
		int temp = len_a;//����Ҳ���뽻�������� 
		len_a = len_b;
		len_b = temp;
	}
	string c;
	int borrow = 0;//��λ
	int i = len_a - 1,j = len_b - 1;
	while(i >= 0 || j >= 0)
	{
		int _a = a[i] - '0' - borrow;
		int _b = 0;
		if(j >= 0)//��b����û����a�� 
		_b += b[j] - '0'; 
		if(_a >= _b)
		{
			c += char((_a - _b) + '0');
			borrow = 0;
		}
		else
		{
			c += char((10 + _a - _b) + '0');
			borrow = 1;//��λ��һ
		}
		i--,j--; 
	}
	//�����תc 
	i = 0,j = c.length() - 1;
	while(i < j)
	{
		char ch = c[i];
		c[i] = c[j];
		c[j] = ch;
		i++,j--;
	} 
	//����ǰ��0
	while(c[0] == '0')
	c.erase(0,1);//string.erase(pos,n) ɾ����pos��ʼ��n���ַ�
	if(is_a_bigger == -1)
	c = "-" + c;//���ϸ��� 
	return c;
}
int main()
{
	cin >> s1 >> s2;
	cout << sub(s1,s2) << endl;
	return 0;
}
