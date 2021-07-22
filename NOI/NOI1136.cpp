#include <iostream>
#include <string>
using namespace std;
int n,m,pattern[10005][26];
string word;
int main()
{
	cin >> n;
	for(int i = 0; i < n; i++)
	{
		int p[26] = {};
		cin >> word;
		for(int j = 0;j < word.length();j++)
			p[word[j] - 'A'] += 1;
		/*for(int j = 0;j < 26;j++)
		cout << p[j] << "  ";
		cout << endl;*/
		bool isNew = true;
		for(int k = 0;k < m;k++)
		{
			for(int x = 0;x < 26;x++)
			{
				if(pattern[k][x] != p[x])
				break;
				else if(x == 25)
				isNew = false;
			}
			if(!isNew)break;
		}
		if(isNew)
		{
			for(int x = 0;x < 26;x++)
				pattern[m][x] = p[x];
			
			m++;
		}
	}
	cout << m << endl;
	return 0;
}
