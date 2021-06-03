#include <stdio.h>
/*
回溯法 
终于知道此题的C回溯版本要怎么写了,诀窍是使用数组存储学生、书籍数据，关键是“数组回退” ，“借书记得要还书” 
问题的初始状态：为使问题简单化，假设刚开始时学生i持有书本i。
i:当前学生编号 
n:问题规模，即学生或书籍数量 
students:学生列表，students[i]表示第i个学生所持有的书的编号，0为未拿到书，非零则表示已经拿到书 
books:书籍列表 ，books[i]表示第i本书是否被分配，0为未分配，1为已分配 
solu:方法数量 
*/
void dfs(int i,int n,int *students,int *books,int *solu)
{
	if(i > n)
	{
		*solu += 1;//书发完了 
		 printf("----------方案%d：----------\n",*solu);
		 for(int k = 1;k <= n;k++)
		 {
		 	printf("学生%d拿走书籍%d，",k,students[k]);
		 }
		 printf("\n",*solu); 
	}
	else
	{
		//给编号为i的学生发书 
		for(int j = 1;j <= n;j++)//一般使用for循环划分分支线路 
		{
			if(j != i && !books[j])//这本书不是学生i之前拿的那本书，并且这本书未被分配 
			{
				//发书
				books[j] = i;//把书籍j发给学生i 
				students[i] = j; //学生i拿走书籍j 
				dfs(i + 1,n,students,books,solu);
				//还书
				//不同于python，C语言回溯完成后还需要回退数值，不然会影响其它分支路线，python传递的是列表副本，所以无需回退 
				books[j] = 0;
				students[i] = 0;
			}
		} 
	} 
	
}
// -1 的n次方 
int factor_m1(int n)
{
	if(n % 2 == 0)
	return 1;
	else
	return -1;
} 
/*
递推公式法 
观察python回溯写出来的递推公式，暂时没想到c回溯应该怎么写 
*/
long long cal(int n)
{
	long long num[21];
	num[1] = 0,num[2] = 1;
	for(int i = 3;i <= n;i++)
	{
		//自己发现的公式 f(n) = n * f(n - 1) + pow(-1,n)
		num[i] = i * num[i - 1] + factor_m1(i);
		//其实还有种写法 f(n) = (n - 1) * (f(n - 1) + f(n - 2)) 
	}
	return num[n];
} 
int main()
{
	int n,solu = 0;
	scanf("%d",&n);
	int students[n + 1],books[n + 1];
	memset(students,0,sizeof(students));//使用memset初始化数组，参数1为数组名，参数2为初始值，参数3为数组的大小 
	memset(books,0,sizeof(books));//使用memset初始化数组，参数1为数组名，参数2为初始值，参数3为数组的大小 
	dfs(1,n,students,books,&solu);
	printf("%d",solu);
	/*
	for(int i = 0;i <= n;i++)
	{
		printf("%d  %d\n",students[i],books[i]);
	}
	*/
	//printf("%lld",cal(n));
	return 0;
} 
