#include <iostream>
#define LEN 100
using namespace std;
char WORD[LEN + 1];
int analyze()
{
	int ans = 1,pos = 0;
	while(WORD[pos] != '\0')
	{
		ans *= WORD[pos] - 96;//a��ascii��ֵΪ97 
		ans %= 10007;//���ȡģ�����ڲ���ȡģ �������Ǽӷ����ǳ˷� 
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
