#include <stdio.h>
int main()
{
	int weight;
	double cost;
	scanf("%d",&weight);
	if(weight > 30)
	printf("Fail");
	else
	{
		if(weight <= 10)
		cost = 0.2 + weight * 0.8;
		else if(weight <= 20)
		cost = 0.2 + (weight - 10) * 0.75 + 10 * 0.8;
		else
		cost = 0.2 + (weight - 20) * 0.70 + 10 * 0.8 + 10 * 0.75;
		printf("%.2lf",cost);
	}
	return 0;
}
