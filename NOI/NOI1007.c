#include <stdio.h>
#include <math.h>
int main()
{
	double a,b;
	int _a,_b;
	scanf("%lf %lf",&a,&b);
	_a = floor(a); //����ȡ�� 
	_b = ceil(b); //����ȡ��
	int i = _a / _b;
	while(a - b * i >= b)
	{
		i++;
	}
	printf("%.2lf",a - b * i);
	return 0;
}
