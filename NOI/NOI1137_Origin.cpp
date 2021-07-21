#include<iostream>
#include<algorithm>
using namespace std;
int i,j,n,m,maxx=0,sum=0,p[1001],ps[501502],x;
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>p[i];
//	任意两次射击成绩相加，包含可能的单枪成绩，故从0开始。 
	for(i=0,x=0;i<=n;i++)
		for(j=0;j<=i;j++) 
			ps[++x]=p[i]+p[j];		
	sort(ps,ps+x);//默认排序从小到大 
	for(i=0,j=x-1;i<=j;){ //最低ps[i]最高ps[j] 
		sum=ps[i]+ps[j]; //成绩相加 
		if(sum>maxx&&sum<=m)
			maxx=sum;
		if(sum>=m)  j--;
		else  i++;
	}	
	cout<<maxx;
	return 0;
}


