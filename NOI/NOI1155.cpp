#include <iostream>
using namespace std;

int n1,n2;
int A[1005],B[1005];//AΪ���� BΪ��ĸ
int A_SPLIT[1005],B_SPLIT[1005];//�����ֽ�����ʽ

#include<deque>
#include<sstream>
std::string BigNumMultiply(std::string s1,std::string s2){
    //��¼���ս��
    std::string res="";
    //ʹ��deque����Ϊ���ֽ�λʱ�����ڶ���ǰ�������ݣ�Ч�ʱ�vector�ߣ���С��Ϊ��С
    std::deque<int> vec(s1.size()+s2.size()-1,0);
    for(int i=0;i<s1.size();++i){
        for(int j=0;j<s2.size();++j){
            vec[i+j]+=(s1[i]-'0')*(s2[j]-'0');//��¼��˽��
        }
    }
    //��λ����
    int addflag=0;
    //�������������Ϊ����ߵ�ֵΪ���λ�����ұߵ�ֵ�����λ����λ����Ҫ�ӵ�λ��ʼ
    for(int i=vec.size()-1;i>=0;--i){
        int temp=vec[i]+addflag;//��ǰֵ���Ͻ�λֵ
        vec[i]=temp%10;//��ǰֵ
        addflag=temp/10;//��λֵ
    }
    //����н�λ������λ�ӵ�����ͷ��
    while(addflag!=0){
        int t=addflag%10;
        vec.push_front(t);
        addflag/=10;
    }
    for(auto c:vec){
        std::ostringstream ss;
        ss<<c;
        res=res+ss.str();
    }
    return res;
}

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

string tostring(int num)
{
	string s;
	while(num > 0)
	{
		s += tochar(num % 10);
		num /= 10;
	}
	for(int i = 0,j = s.length() - 1;i < j;i++,j--)
	{
		char c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
	return s;
}
void split(int num,char type)
{
	//cout << "split:" << num << endl;
	if(type == 'A')
	{
		int divisor = 2;
		while(num > 1)
		{
			if(num % divisor == 0)
			{
				num /= divisor;
				A_SPLIT[divisor] += 1;//������һ
			}
			else
				divisor += 1;//��ʽ��һ
		}
	}
	if(type == 'B')
	{
		int divisor = 2;
		while(num > 1)
		{
			if(num % divisor == 0)
			{
				num /= divisor;
				B_SPLIT[divisor] += 1;//������һ
			}
			else
				divisor += 1;//��ʽ��һ
		}
	}
}

void print(int arr[])
{
	for(int i = 2; i <= 1000; i++)
	{
		if(arr[i] > 0)
		{
			//cout << i << "^" << arr[i] << "*";
			for(int j = 1; j <= arr[i]; j++)
			{
				cout << i << "*";
			}
		}

	}
	cout << endl;
}

int main()
{
	cin >> n1;
	for(int i = 1; i <= n1; i++)
		cin >> A[i];
	cin >> n2;
	for(int i = 1; i <= n2; i++)
		cin >> B[i];
	for(int i = 1; i <= n1; i++)
		split(A[i],'A');
	for(int i = 1; i <= n2; i++)
		split(B[i],'B');
	//print(A_SPLIT);
	//print(B_SPLIT);
	for(int i = 2; i <= 1000; i++)
	{
		if(A_SPLIT[i] >= B_SPLIT[i])
		{
			A_SPLIT[i] -= B_SPLIT[i];
			B_SPLIT[i] = 0;
		}
		else
		{
			B_SPLIT[i] -= A_SPLIT[i];
			A_SPLIT[i] = 0;
		}
	}
	//long long fz = 1,fm = 1;
	string sfz = "1",sfm = "1";
	//cout << "���ӣ�1 * ";
	for(int i = 2; i <= 1000; i++)
	{
		if(A_SPLIT[i] > 0)
		{
			for(int j = 1; j <= A_SPLIT[i]; j++)
			{
				//cout << i << " * ";
				//fz *= i;
				sfz = BigNumMultiply(sfz,tostring(i));
			}
		}
	}
	//cout << endl << "--------------------------------" << endl;
	//cout << "��ĸ��1 * ";
	for(int i = 2; i <= 1000; i++)
	{
		if(B_SPLIT[i] > 0)
		{
			for(int j = 1; j <= B_SPLIT[i]; j++)
			{
				//cout << i << " * ";
				//fm *= i;
				sfm = BigNumMultiply(sfm,tostring(i));
			}
		}
	}
	//cout << endl << fz << "/" << fm << endl;
	//cout << sfz << "/" << sfm << endl;
	//cout << BigNumMultiply("12345","67890") << endl;
	cout << sfz << endl;
	cout << sfm << endl;
	
	return 0;
}
