#include <iostream>
using namespace std;
int data[1001],dp[1001][1001],maxn=0;
int main() 
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
      scanf("%d",&data[i]),dp[i][i]=data[i];
    for(int i=n;i>=1;i--)
    {
        for(int j=i;j<=n;j++)
        dp[i][j]=max(dp[i][j-1]+data[j]*(n-(j-i)),dp[i+1][j]+data[i]*(n-(j-i)));
    }
    cout<<dp[1][n];
    return 0;
}
