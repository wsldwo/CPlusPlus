#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DATA_LENGTH 1500
#define SEPERATOR '@'
/*
输入两个数a,b(1<=a,b<=10^1000)，计算a,b的最大公约数。
更相减损法
第一步：任意给定两个正整数；判断它们是否都是偶数。若是，则用2约简；若不是则执行第二步。
第二步：以较大的数减较小的数，接着把所得的差与较小的数比较，并以大数减小数。继续这个操作，直到所得的减数和差相等为止。
则第一步中约掉的若干个2与第二步中等数的乘积就是所求的最大公约数。
*/
//C语言中使用内存较大的二维数组出错的解决办法
//解决办法：局部变量不允许占用过多内存，所以需要定义成全局变量
char c[1500][3000];//大数乘法使用

int len(char str[])
{
	int length = 0;
	while(str[length] != '\0')
		length++;
	return length;
}

void print(char str[])
{
	for(int i = 0; i < len(str); i++)
	{
		printf("%c",str[i]);
	}
}

void copy_s(char origin[],char dest[],int start_pos)
{
	for(int i = 0,k = start_pos; i <= len(origin); i++,k++)
	{
		dest[k] = origin[i];
	}
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

//比较两个正数的大小
int bigger(char a[],char b[])
{
	int len_a = len(a),len_b = len(b);
	if(len_a > len_b)
		return 1;// a > b
	else if(len_a == len_b)
	{
		for(int i = 0; i < len_a; i++)
		{
			if(charToint(a[i]) > charToint(b[i]))
				return 1;
			else if(charToint(a[i]) < charToint(b[i]))
				return -1;
		}
		return 0;// a == b
	}
	else
		return -1;// a < b
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
//拷贝
void copy(char origin[],char destin[])
{
	int len_des = len(destin);
	for(int i = 0; i <= len_des; i ++) //当i == len_des时，对应'\0'字符，'\0'也应该进行复制
	{
		origin[i] = destin[i];
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
//大数减法
void minus(char a[],char b[],char res[])
{
	//a - b
	int len_a = len(a),len_b = len(b);
	int i = len_a - 1,j = len_b - 1,k = 0;
	int borrow = 0;//借位
	while(i >= 0)
	{
		int sa = charToint(a[i]),sb = j >= 0 ? charToint(b[j]) : 0;
		sa -= borrow;
		borrow = 0;
		if(sa < sb)
		{
			borrow = 1;//高位借一
			res[k] = intTochar(sa + 10 - sb);
		}
		else
		{
			res[k] = intTochar(sa - sb);
		}

		i -= 1;
		j -= 1;
		k += 1;
	}
	res[k] = '\0';

	int all_zero = 1;
	for(int m = 0; m < k; m++)
	{
		if(res[m] != '0')
		{
			all_zero = 0;
			break;
		}
	}

	if(!all_zero)//不是全零 
	{
		int zero_pos = k - 1;//去零
		while(res[zero_pos] == '0')
			zero_pos--;
		res[zero_pos + 1] = '\0';
		reverse(res);
	}
	else
	{
		res[0] = '0';
		res[1] = '\0'; 
	}

}
/*
此函数计算两个正数的整除，得到商和余数，结果保留在字符数组中
a / b = c ...... d
假设除数b可以转化为整形。。
*/

char* cut(char str[],int start,int end)
{
	char *temp = (char *)malloc((end - start + 2) * sizeof(char));
	for(int i = start,j = 0; i <= end; i++,j++)
	{
		temp[j] = str[i];
	}
	temp[end - start + 1] = '\0';
	return temp;
}

void divide(char a[],char b[],char res[])
{
	int len_a = len(a),len_b = len(b),r = bigger(a,b);
	//printf("len_a:%d len_b:%d\n",len_a,len_b);
	if(r == -1)// a < b
	{
		res[0] = '0';
		res[1] = SEPERATOR;
		copy_s(a,res,2);
		//printf("res:  %s / %s = %s\n",a,b,res);
	}
	else if(r == 0)// a == b
	{
		res[0] = '1';
		res[1] = SEPERATOR;
		res[2] = '0';
		res[3] = '\0';
		//printf("res:  %s / %s = %s\n",a,b,res);
	}
	else if(r == 1)// a > b
	{
		int k = 0;
		int start = 0,end = len_b - 1;
		char *sa = cut(a,start,end);//动态分配,记得释放
		//printf("sa:%s b:%s\n",sa,b);
		if(bigger(sa,b) == -1)
		{
			free(sa);
			end += 1;
			sa = cut(a,start,end);
			//printf("incre sa:%s b:%s\n",sa,b);
		}
		while(end < len_a)
		{
			//sa / b = ss ... y
			//乘法做除法
			/*
			BUG001修复： product  product2
			*/
			char product[DATA_LENGTH],product2[DATA_LENGTH];
			for(int i = 1; i < 10; i++)
			{
				char p[2],q[2];
				p[0] = intTochar(i);
				p[1] = '\0';
				q[0] = intTochar(i + 1);
				q[1] = '\0';
				multiply(b,p,product);
				multiply(b,q,product2);
				//printf("produ:%s  produ2:%s  sa:%s\n",product,product2,sa);
				if(bigger(product,sa) <= 0 && bigger(product2,sa) == 1)
				{
					//printf("ss:%d\n",i);
					res[k] = intTochar(i);
					k++;
					break;
				}
			}
			char r[end - start + 2];
			minus(sa,product,r);
			printf("%s - %s = %s\n",sa,product,r);
			free(sa);
			sa = (char*)malloc(1500 * sizeof(char));
			int pos1 = 0,pos2 = 0,len_r = len(r);
			while(pos1 < len_r)//去零
			{
				if(r[pos1] != '0')
					break;
				pos1++;
			}
			while(pos1 < len_r)
			{
				sa[pos2] = r[pos1];
				pos1++;
				pos2++;
			}
			sa[pos2] = '\0';
			//下一位
			end += 1;
			if(end >= len_a)//到达终点
			{
				//将余数添加到结果中
				res[k] = SEPERATOR;
				k++;
				copy_s(sa,res,k);
				if(len(sa) == 0)
				{
					res[k++] = '0';
					res[k] = '\0';
				}
				printf("res:  %s / %s = %s\n",a,b,res);
				return;
			}
			else
			{
				//正常降位
				sa[pos2] = a[end];
				pos2++;
				sa[pos2] = '\0';
				while(bigger(sa,b) == -1)
				{
					res[k] = '0';//商零
					k++;

					end += 1;
					if(end >= len_a)//到达终点
					{
						//将余数添加到结果中
						res[k] = SEPERATOR;
						k++;
						copy_s(sa,res,k);
						if(len(sa) == 0)
						{
							res[k++] = '0';
							res[k] = '\0';
						}
						printf("res:  %s / %s = %s\n",a,b,res);
						return;
					}
					else
					{
						sa[pos2] = a[end];
						pos2++;
						sa[pos2] = '\0';
					}
				}

			}

		}
	}
}

char* getRemainder(char res[])
{
	char *temp = (char *)malloc(DATA_LENGTH * sizeof(char));
	int i = len(res) - 1,j = 0;
	while(res[i] != SEPERATOR)
	{
		temp[j] = res[i];
		j++;
		i--;
	}
	temp[j] = '\0';
	reverse(temp);
	return temp;
}
int isZero(char r[])
{
	if(len(r) == 1 && r[0] == '0')
		return 1;//C语言中非零为真
	else
		return 0;
}
//辗转相除法
//gcd(a,b) = gcd(b,a mod b)
void gcd(char a[],char b[],char res[])
{
	divide(a,b,res);
	char *remainder = getRemainder(res);
	if(isZero(remainder))
	{
		printf("############################################ans: %s\n",b);
		free(remainder);
		return;
	}
	else
	{
		int r = bigger(b,remainder);
		if(r == 1)
			gcd(b,remainder,res);
		else if(r == -1)
			gcd(remainder,b,res);
		else
			printf("#########################################ans: %s\n",b);
	}
}

int isEven(char n[])// 奇数 odd num  偶数 even num
{
	int len_n = len(n);
	if(n[len_n - 1] == '0' || n[len_n - 1] == '2' || n[len_n - 1] == '4' || n[len_n - 1] == '6' || n[len_n - 1] == '8')
		return 1;
	else
		return 0;
}

//更相减损法
void gcd2(char a[],char b[],char res[])
{
	int times = 0,len_a = strlen(a),len_b = strlen(b);
	char two[2];
	two[0] = '2';
	two[1] = '\0';
	while(isEven(a) && isEven(b))
	{
		printf("a:%s b:%s\n",a,b);
		times++;
		char d_a[len_a],d_b[len_b];
		divide(a,two,d_a);
		divide(b,two,d_b);
		d_a[len(d_a) - 2] = '\0';
		d_b[len(d_b) - 2] = '\0';
		strcpy(a,d_a);
		strcpy(b,d_b);
	}
	printf("times:%d\n",times);
	printf("a:%s b:%s\n",a,b);
	while(1)
	{
		printf("while a:%s b:%s\n",a,b);
		int r = bigger(a,b);
		if(r == 0)
		{
			printf("%s * 2 ^ %d\n",a,times);
			char ans[DATA_LENGTH];
			while(times > 0)
			{
				multiply(a,two,ans);
				strcpy(a,ans);
				times--;
			}
			printf("********************************************ans: %s\n",a);
			return;
		}
		else if(r == 1)//a > b
		{
			char minu[DATA_LENGTH];
			minus(a,b,minu);
			strcpy(a,minu);
		}
		else// a < b
		{
			char minu[DATA_LENGTH];
			minus(b,a,minu);
			strcpy(b,minu);
		}

	}
}

int main()
{
	char a[DATA_LENGTH],b[DATA_LENGTH],res[DATA_LENGTH * 2];
	scanf("%s %s",a,b);
	res[0] = '\0';
	//printf("%s * %s = ",a,b);
	//multiply(a,b,res);
	//divide(a,b,res);
	//printf("%s / %s = %s \n",a,b,res);
	gcd(a,b,res);//超时
	gcd2(a,b,res);//超时
	//minus(a,b,res);
	//printf("%s - %s = %s",a,b,res);
	return 0;
}
