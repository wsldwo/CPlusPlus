#include <stdio.h>
#include <math.h>
/*
double exp (double x); �ݺ���e^x

double pow (double x, double y); x^y�����x=0��y<=0,����x<0��y���������������������������

double sqrt (double x); x��ƽ����������x>=0

double log (double x); ��eΪ�׵Ķ���,��Ȼ������x>0

double log10 (double x); ��10Ϊ�׵Ķ�����x>0

ȡ��
double ceil (double x); ȡ����

double floor (double x); ȡ����

����ֵ
double fabs (double x); x�ľ���ֵ
*/
int main()
{
	double R,X,P,Y;
	scanf("%lf %lf %lf",&R,&X,&P);
	Y = pow((100 + R) / 100,P) * X;
	printf("%.2lf",Y);
	return 0;
} 
