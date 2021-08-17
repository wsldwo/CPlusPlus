#include <stdio.h> 
#include <string.h>
#define DATA_LENGTH 1500
#define SEPERATOR '@' 
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

void copy_s(char origin[],char dest[],int start_pos)
{
	for(int i = 0,k = start_pos; i <= len(origin); i++,k++)
	{
		dest[k] = origin[i];
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
			//printf("incre sa:%s b:%s",sa,b);
		}
		while(end < len_a)
		{
			//sa / b = ss ... y
			//乘法做除法
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
					res[k++] = intTochar(i);
					break;
				}
			}
			char r[end - start + 2];
			minus(sa,product,r);
			//printf("%s - %s = %s\n",sa,product,r);
			free(sa);
			sa = (char*)malloc(DATA_LENGTH * sizeof(char));
			int pos1 = 0,pos2 = 0,len_r = len(r);
			while(pos1 < len_r)//去零
			{
				if(r[pos1] != '0')
					break;
				pos1++;
			}
			while(pos1 < len_r)
			{
				sa[pos2++] = r[pos1++];
			}
			sa[pos2] = '\0';
			//下一位
			end += 1;
			if(end >= len_a)//到达终点
			{
				//将余数添加到结果中
				res[k++] = SEPERATOR;
				copy_s(sa,res,k);
				if(len(sa) == 0)
				{
					res[k++] = '0';
					res[k] = '\0';
				}
				//printf("res:  %s / %s = %s\n",a,b,res);
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
					res[k++] = '0';//商零
					end += 1;
					if(end >= len_a)//到达终点
					{
						//将余数添加到结果中
						res[k++] = SEPERATOR;
						copy_s(sa,res,k);
						if(len(sa) == 0)
						{
							res[k++] = '0';
							res[k] = '\0';
						}
						//printf("res:  %s / %s = %s\n",a,b,res);
						return;
					}
					else
					{
						sa[pos2++] = a[end];
						sa[pos2] = '\0';
					}
				}

			}
		}
	}
}

int main()
{
	char a[DATA_LENGTH],b[DATA_LENGTH],res[DATA_LENGTH * 2];
	scanf("%s %s",a,b);
	divide(a,b,res);
	printf("%s / %s = %s\n",a,b,res);
	return 0;
}
