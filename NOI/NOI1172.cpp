#include <iostream>
#define LEN 100
using namespace std;
char WORD[LEN + 1];
int analyze()
{
	int ans = 1,pos = 0;
	while(WORD[pos] != '\0')
	{
		ans *= WORD[pos] - 96;//a的ascii码值为97 
		ans %= 10007;//结果取模，等于步步取模 ，无论是加法还是乘法 
		pos += 1;
	}
	return ans; 
}

int main()
{
	cin >> WORD;
	cout << analyze() << endl;
	return 0;
} 
