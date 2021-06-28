#include <iostream>
#include <string>
using namespace std;
string S1,S2;
int DP[5005][5005];//DP[i][j]ΪS1��ǰi�����к�S2��ǰj�����е�����������еĳ���
int f()
{
	int len1 = S1.length(),len2 = S2.length();
	for(int i = 1; i <= len1; i++)
	{
		for(int j = 1; j <= len2; j++)
		{
			if(S1[i - 1] == S2[j - 1])
				DP[i][j] = DP[i - 1][j - 1] + 1;//ĩβ��ͬ��һ��������������е�ĩβ 
			else
				DP[i][j] = DP[i - 1][j] > DP[i][j - 1] ? DP[i - 1][j] : DP[i][j - 1];//ĩβ��ͬ����ȡ�ϴ��� 
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
