#include <stdio.h>
int len(char s[])
{
	int length = 0;
	while(s[length] != '\0')
		length++;
	return length;
}
int is_same(char s1[],char s2[])
{
	int pos = 0;
	while(s1[pos] != '\0' && s2[pos] != '\0')
	{
		if(s1[pos] != s2[pos])
			return 0;
		pos++;
	}
	if(s1[pos] == '\0' && s2[pos] == '\0')
		return 1;//在C语言中，0为假，非零为真 
	else
		return 0;//在C语言中，0为假，非零为真 
}
int main()
{
	char conti,password[10],true_pass[10] = "NOIP@CCF";
	/*
	下次可以试试while(scanf("%d",&n)!=EOF) 
	何时输出EOF? 在stdio.h中宏定义为-1，按照说明，
	scanf函数只有在第一个参数为NULL(空指针)的状况下，才可能返回EOF，
	不然，返回成功格式化并赋值的参数个数(>=0)。
	scanf()函数返回成功赋值的数据项数，出错时则返回，EOF定义为-1。
	~是按位取反，-1十六进制补码表示为0x ffffffff，f是二进制的1111，取反后就全部变成0了，于是while结束。
	只有返回值为EOF（即-1）时，其取反的的值（即while循环的判断条件）才为0，才能结束循环，
	其它输入情况下（无论是否输入成功）while循环的判断条件为非0，即为真。
	
	while (~scanf("%d%d",&m,&n))  <=>  while (scanf("%d%d",&m,&n)!=EOF) 
	
	*/ 
	while(1)
	{
		scanf("%c",&conti);
		if(conti == 'Y')
		{
			scanf("%s",password);
			if(is_same(password,true_pass))
			{
				printf("Success\n");
				//题目意思没看懂，题解中密码正确后就直接break了
				break; 
			}
			else
				printf("Sorry\n");
		}
		else if(conti == 'N')
		{
			break;
		}
	}
	return 0;
} 
