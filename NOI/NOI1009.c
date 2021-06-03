#include <stdio.h>
int main()
{
	int boys,girls;
	scanf("%d %d",&boys,&girls);
	if(boys + girls < 10)
	printf("water");
	else if(boys > girls)
	printf("tree");
	else
	printf("tea");
	return 0;
}
