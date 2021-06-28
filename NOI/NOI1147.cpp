#include <iostream>
#include <string>
using namespace std;
string S1,S2;
int DP[5005][5005];//DP[i][j]为S1的前i个序列和S2的前j个序列的最长公共子序列的长度
int f()
{
	int len1 = S1.length(),len2 = S2.length();
	for(int i = 1; i <= len1; i++)
	{
		for(int j = 1; j <= len2; j++)
		{
			if(S1[i - 1] == S2[j - 1])
				DP[i][j] = DP[i - 1][j - 1] + 1;//末尾相同则一定是最长公共子序列的末尾 
			else
				DP[i][j] = DP[i - 1][j] > DP[i][j - 1] ? DP[i - 1][j] : DP[i][j - 1];//末尾不同，则取较大者 
		}
	}
	return DP[len1][len2];
}
int main()
{
	cin >> S1 >> S2;
	//S1 = "bsqbhydtjnvjpnbmeeodemuqjfsyayruyjzgyukhdlgylrcgathpnxsbqmkwyrjlxkcdqfxxcgznjcyorywbxdugkzxnyojqqxendmykbwekilwbbmepaasmegqaxjtpibswsgufimhgfjtulziypafpcingdgmcohxwqowedbicogorjczhndxaouefdgpwpveiigsjxkzgfbuhaycjxeajbaacpmcuupohukulvusdopdmxlfomhkicgmmrecsyeaovatlnuumsdqyl";
	//S2 = "amocmxszorvjrdjuhvbxaxftfsiknmbtkakyalctnrybynpvcyasdueajtihysovpsgchidvuaxrwvrhcliihibwievdjivglhagiyigynidsidemkxphrjrhtefpzesfulbfaguuuwjtjhbqbodbdyvrsinhggczinvuzemwijvvgdkzmxcfwbylwqbrggznrzxeumhtdewouthhdaiiyboxaexpxnjfawlqtjvrrzxvuhbkxvlszsxvcnfsdtfgroeajajbfdofpvdbquqxankhcxtqjhmfgbsiszr";
	cout << f() << endl;
	return 0;
}
