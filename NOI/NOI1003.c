#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n;
	scanf("%d",&n);
	n = n * 1000 + n;
	printf("%d",n / ( 7 * 11 * 13));
	return 0;
}
