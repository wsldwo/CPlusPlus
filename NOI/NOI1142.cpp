#include <iostream>
#include <algorithm>
using namespace std;
bool isPrime(long long num)
{
	if(num <= 1)return false;
	if(num == 2)return true;
	long long boundary = sqrt(num) + 1;
	for(int i = 2;i < boundary;i++)
	{
		if(num % i == 0)
		return false;
	}
	return true;
}
int main()
{
	int n;
	cin >> n;
	for(int i = 0;i < n;i++)
	{
		long long num;
		cin >> num;
		if(isPrime(num))
		cout << "yes" << endl;
		else
		cout << "no" << endl;
	}
	return 0;
} 
