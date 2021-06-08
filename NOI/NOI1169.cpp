#include <iostream>
#include <iomanip>
#include <algorithm>
using namespace std;

void cal(int k,double x)
{
	double ans = 0.0;
	switch(k)
	{
		case 1:cout<<fixed<<setprecision(3)<<sqrt(x)<<endl;break;
		case 2:
		//角度转化弧度
		x = x * 3.1415926 / 180.0; 
		cout<<fixed<<setprecision(3)<<sin(x)<<"  "<<cos(x)<<"  "<<tan(x)<<endl;break;
		case 3:cout<<fixed<<setprecision(3)<<asin(x)<<"  "<<acos(x)<<endl;break;
		case 4:cout<<fixed<<setprecision(3)<<atan(x)<<endl;break;
	}
}

int main()
{
	int n,k;
	double x;
	cin>>n;
	for(int i = 0;i < n;i++)
	{
		cin>>k>>x;
		cal(k,x);
	}
	return 0;
} 
