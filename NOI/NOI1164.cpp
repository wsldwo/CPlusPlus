#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int n,ans,v[2020],f[2020][2020];

/*
大佬写的递归，太牛了，直接AC。
*/
int dfs(int ste,int l,int r){
    if(r<l)return 0;
    if(f[l][r])return f[l][r];
    f[l][r]=max(dfs(ste+1,l+1,r)+ste*v[l],dfs(ste+1,l,r-1)+ste*v[r]);
    return f[l][r];
}

int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",&v[i]);
    dfs(1,1,n);
    printf("%d",f[1][n]);
    return 0;
}

