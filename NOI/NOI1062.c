#include <stdio.h>
double abs(double n)
{
	if(n < 0)
	return -1 * n;
	else
	return n;
}
int main()
{
	double x1,y1,x2,y2,dis;
	scanf("%lf %lf %lf %lf",&x1,&y1,&x2,&y2);
	dis = abs(x1 - x2) + abs(y1 - y2);
	printf("%.3lf",dis);
	return 0;
}
