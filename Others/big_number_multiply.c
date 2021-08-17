#include <stdio.h>
#include <string.h>
#define DATA_LENGTH 1500
char c[DATA_LENGTH][DATA_LENGTH * 2];//大数组需要定义成全局变量 

int len(char str[])
{
	int length = 0;
	while(str[length] != '\0')
		length++;
	return length;
}

int charToint(char c)
{
	if(c == '0')
		return 0;
	if(c == '1')
		return 1;
	if(c == '2')
		return 2;
	if(c == '3')
		return 3;
	if(c == '4')
		return 4;
	if(c == '5')
		return 5;
	if(c == '6')
		return 6;
	if(c == '7')
		return 7;
	if(c == '8')
		return 8;
	if(c == '9')
		return 9;
}

char intTochar(int n)
{
	switch(n)
	{
		case 0:
			return '0';
		case 1:
			return '1';
		case 2:
			return '2';
		case 3:
			return '3';
		case 4:
			return '4';
		case 5:
			return '5';
		case 6:
			return '6';
		case 7:
			return '7';
		case 8:
			return '8';
		case 9:
			return '9';
	}
}
//大数加法
void add(char a[],char b[],char result[])
{
	//printf("%s + %s        ",a,b);
	//char sum[1500];
	int len_a = len(a),len_b = len(b);
	//printf("%d && %d \n",len_a,len_b);
	//1、对齐补零
	int max_len = len_a > len_b ? len_a : len_b;
	int i;
	for(i = len_a; i < max_len; i++)
	{
		a[i] = '0';
	}
	a[i] = '\0';//末尾补零 ，循环跳出时，索引正好指向末尾
	for (i = len_b; i < max_len; i++)
	{
		b[i] = '0';
	}
	b[i] = '\0';//末尾补零 ，循环跳出时，索引正好指向末尾
	//printf("%s + %s\n",a,b);
	//2、加法计算
	int incre = 0,r = 0;
	for(i = 0; i < max_len; i++)
	{
		r = charToint(a[i]) + charToint(b[i]) + incre;
		if(r > 9)
		{
			result[i] = intTochar(r % 10);
			incre = r / 10;
			if(i == max_len - 1)//特殊情况，首位进位
			{
				result[++i] = intTochar(incre);
			}
		}
		else
		{
			result[i] = intTochar(r);
			incre = 0;
		}
	}
	result[i] = '\0';//末尾补零 ，循环跳出时，索引正好指向末尾
	//printf("result: %s \n",res);
}
//逆置
void reverse(char s[])
{
	int len_s = len(s);
	char c;
	for(int i = 0,j = len_s - 1; i < j; i++,j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
//大数乘法
void multiply(char a[],char b[],char result[])
{
	//printf("this is multiply!!!\n");
	//printf("%s * %s = \n",a,b);
	/*
	BUG#001:
	char c[15][15]; 长度不够容纳数据， 把15改成30后，恢复正常
	*/
	memset(c,0,sizeof(c));
	//下面开始设计大数乘法算法
	int len_a = len(a),len_b = len(b);
	//比如拿a乘以b
	int i,j;
	for(i = len_a - 1,j = 0; i >= 0; i--,j++)
	{
		//逆序存放
		//1、先补零
		int k = 0;
		while(k < j)
		{
			c[j][k] = '0';
			k++;
		}
		int incre = 0;//进位变量
		int r = 0;//中间结果
		//2、拿a的每一位数，乘以b，存储到二维数组c中
		for(int l = len_b - 1; l >= 0; l--)
		{
			r = charToint(a[i]) * charToint(b[l]) + incre;
			if(r > 9)
			{
				c[j][k] = intTochar(r % 10);
				incre = r / 10;
				if(l == 0) //特殊情况，首位进位
				{
					c[j][++k] = intTochar(incre);
				}
			}
			else
			{
				c[j][k] = intTochar(r);
				incre = 0;
			}
			k++;
		}
		c[j][k] = '\0';
	}
	//3、把c数组中的中间结果进行累加，得到最终结果
	result[0] = '0';
	result[1] = '\0';
	for(int m = 0; m < len_a; m++)
	{
		//printf("c[m]: %s\n",c[m]);
		add(result,c[m],result);
	}
	reverse(result);
}

int main()
{
	char a[DATA_LENGTH],b[DATA_LENGTH],res[DATA_LENGTH * 2];
	scanf("%s %s",a,b);
	multiply(a,b,res);
	printf("%s * %s = %s\n",a,b,res);
	return 0;
}
