/*
整数之间的运算结果是整数。
2进制16位整数取值范围是：-32768 32767                              short 
2进制32位整数取值范围是：-2147483648 2147483647                    int （long）
2进制64位整数取值范围是：-9223372036854775808 9223372036854775807  long long (__int64)

100分通过的C语言程序之一：
#include <stdio.h>

int main(void)
{
    long long n, m, a;

    scanf("%lld%lld%lld", &n, &m, &a);

    printf("%lld\n", (n / a) * (m / a));

    return 0;
}
*/

#include <stdio.h>
int len(char *s)//也可写成 char s[]，因为数组变量本身就是一个指针变量 
{
	int i = 0;
	while(s[i] != '\0')i++;
	return i;
}
char intTochar(int n)
{
	switch(n)
	{
		case 0:return '0';
		case 1:return '1';
		case 2:return '2';
		case 3:return '3';
		case 4:return '4';
		case 5:return '5';
		case 6:return '6';
		case 7:return '7';
		case 8:return '8';
		case 9:return '9';
	}
}
int charToint(char c)
{
	if(c == '0')
		return 0;
	else if(c == '1')
		return 1;
	else if(c == '2')
		return 2;
	else if(c == '3')
		return 3;
	else if(c == '4')
		return 4;
	else if(c == '5')
		return 5;
	else if(c == '6')
		return 6;
	else if(c == '7')
		return 7;
	else if(c == '8')
		return 8;
	else if(c == '9')
		return 9;
}
//大数加法 
void add(char *a,char *b,char *result)
{
	//printf("%s + %s        ",a,b);
	char sum[15];
	int len_a = len(a),len_b = len(b);
	//printf("%d && %d \n",len_a,len_b);
	//1、对齐补零 
	int max_len = len_a > len_b ? len_a : len_b;
	int i;
	for(i = len_a;i < max_len;i++)
	{
		a[i] = '0'; 
	} 
	a[i] = '\0';//末尾补零 ，循环跳出时，索引正好指向末尾 
	for (i = len_b;i < max_len;i++)
	{
		b[i] = '0';
	}
	b[i] = '\0';//末尾补零 ，循环跳出时，索引正好指向末尾 
	//printf("%s + %s\n",a,b);
	//2、加法计算 
	int incre = 0,r = 0;
	for(i = 0;i < max_len;i++)
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
void reverse(char *s)
{
	int len_s = len(s);
	char c;
	for(int i = 0,j = len_s - 1;i < j;i++,j--)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
	}
}
//拷贝 
void copy(char *origin,char *destin)
{
	int len_des = len(destin);
	for(int i = 0;i <= len_des;i ++)//当i == len_des时，对应'\0'字符，'\0'也应该进行复制 
	{
		origin[i] = destin[i];
	}
} 
//大数乘法 
void multiply(char *a,char *b,char *result)
{
	/*
	BUG#001:
	char c[15][15]; 长度不够容纳数据， 把15改成30后，恢复正常 
	*/
	char c[15][30];
	//下面开始设计大数乘法算法
	int len_a = len(a),len_b = len(b);
	//比如拿a乘以b
	int i,j; 
	for(i = len_a - 1,j = 0;i >= 0;i--,j++)
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
		for(int l = len_b - 1;l >= 0;l--)
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
	for(int m = 0;m < len_a;m++)
	{
		//printf("c[m]: %s\n",c[m]);
		add(result,c[m],result);
	}
	reverse(result);
}

void intTostring(int n,char *s)
{
	int i = 0;
	while(1)//在C语言中，0为假，非零为真 
	{
		s[i++] = intTochar(n % 10);
		n /= 10;
		if(n == 0)
		{
			break;
		}
	}
	s[i] = '\0';
	reverse(s);
} 

int main()
{
	int n,m,a;//1000000000 1000000000 1 结果会溢出，需要设计大数乘法 
	char n1[15],n2[15],res[30];
	scanf("%d %d %d",&n,&m,&a);
	if(a > n || a > m)
	{
		res[0] = '0';
		res[1] = '\0';
	}
	else
	{
		int t1 = m / a,t2 = n / a;// C 语言中整数除以整数仍是整数（向下取整） 
		intTostring(t1,n1);
		intTostring(t2,n2);
		multiply(n1,n2,res);
	}
	printf("%s",res);
	return 0;//在C语言中，返回0表示正常退出，返回非0表示异常退出！ 
}

