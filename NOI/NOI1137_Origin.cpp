#include<iostream>
#include<algorithm>
using namespace std;
int i,j,n,m,maxx=0,sum=0,p[1001],ps[501502],x;
int main()
{
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>p[i];
//	������������ɼ���ӣ��������ܵĵ�ǹ�ɼ����ʴ�0��ʼ�� 
	for(i=0,x=0;i<=n;i++)
		for(j=0;j<=i;j++) 
			ps[++x]=p[i]+p[j];		
	sort(ps,ps+x);//Ĭ�������С���� 
	for(i=0,j=x-1;i<=j;){ //���ps[i]���ps[j] 
		sum=ps[i]+ps[j]; //�ɼ���� 
		if(sum>maxx&&sum<=m)
			maxx=sum;
		if(sum>=m)  j--;
		else  i++;
	}	
	cout<<maxx;
	return 0;
}


