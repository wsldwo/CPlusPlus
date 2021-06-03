#include <stdio.h>
#include <math.h>
/*
double exp (double x); 幂函数e^x

double pow (double x, double y); x^y，如果x=0且y<=0,或者x<0且y不是整型数，将产生定义域错误

double sqrt (double x); x的平方根，其中x>=0

double log (double x); 以e为底的对数,自然对数，x>0

double log10 (double x); 以10为底的对数，x>0

取整
double ceil (double x); 取上整

double floor (double x); 取下整

绝对值
double fabs (double x); x的绝对值
*/
int main()
{
	double R,X,P,Y;
	scanf("%lf %lf %lf",&R,&X,&P);
	Y = pow((100 + R) / 100,P) * X;
	printf("%.2lf",Y);
	return 0;
} 
