#include <stdio.h>
/*
参数说明：
n:问题规模，即盘子数量 
name:最底下大盘子的名称
times:操作次数，必须使用地址传递，值传递值不会变化 
start,transfer,end:起始柱名称，中转柱名称，终点柱名称（这三根柱子的位置会随着问题改变而动态改变） 
*/ 
void hannoi(int n,int name,int *times,char start,char transfer,char end)
{
	if(n == 1)
	{
		*times += 1;
		printf("%d.Move %d from %c to %c\n",*times,name,start,end);
	}
	else
	{
		/*
		完成汉诺塔永远只有三步：
		1、将大盘子上的 n - 1 个小盘子运到中转柱
		2、将大盘子直接从起点柱运到终点柱
		3、将刚才 n - 1 个小盘子从中转柱运到终点柱 
		*/
		hannoi(n - 1,n - 1,times,start,end,transfer);
		hannoi(1,n,times,start,transfer,end);
		hannoi(n - 1,n - 1,times,transfer,start,end); 
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	int times = 0; 
	hannoi(n,n,&times,'a','b','c');
	return 0;
}
