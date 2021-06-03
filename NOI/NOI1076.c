#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define DATA_LENGTH 1500
#define SEPERATOR '@'
/*
����������a,b(1<=a,b<=10^1000)������a,b�����Լ����
�������
��һ������������������������ж������Ƿ���ż�������ǣ�����2Լ����������ִ�еڶ�����
�ڶ������Խϴ��������С���������Ű����õĲ����С�����Ƚϣ����Դ�����С�����������������ֱ�����õļ����Ͳ����Ϊֹ��
���һ����Լ�������ɸ�2��ڶ����е����ĳ˻�������������Լ����
*/
//C������ʹ���ڴ�ϴ�Ķ�ά�������Ľ���취
//����취���ֲ�����������ռ�ù����ڴ棬������Ҫ�����ȫ�ֱ���
char c[1500][3000];//�����˷�ʹ��

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

//�Ƚ����������Ĵ�С
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

//�����ӷ�
void add(char a[],char b[],char result[])
{
	//printf("%s + %s        ",a,b);
	//char sum[1500];
	int len_a = len(a),len_b = len(b);
	//printf("%d && %d \n",len_a,len_b);
	//1�����벹��
	int max_len = len_a > len_b ? len_a : len_b;
	int i;
	for(i = len_a; i < max_len; i++)
	{
		a[i] = '0';
	}
	a[i] = '\0';//ĩβ���� ��ѭ������ʱ����������ָ��ĩβ
	for (i = len_b; i < max_len; i++)
	{
		b[i] = '0';
	}
	b[i] = '\0';//ĩβ���� ��ѭ������ʱ����������ָ��ĩβ
	//printf("%s + %s\n",a,b);
	//2���ӷ�����
	int incre = 0,r = 0;
	for(i = 0; i < max_len; i++)
	{
		r = charToint(a[i]) + charToint(b[i]) + incre;
		if(r > 9)
		{
			result[i] = intTochar(r % 10);
			incre = r / 10;
			if(i == max_len - 1)//�����������λ��λ
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
	result[i] = '\0';//ĩβ���� ��ѭ������ʱ����������ָ��ĩβ
	//printf("result: %s \n",res);
}
//����
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
//����
void copy(char origin[],char destin[])
{
	int len_des = len(destin);
	for(int i = 0; i <= len_des; i ++) //��i == len_desʱ����Ӧ'\0'�ַ���'\0'ҲӦ�ý��и���
	{
		origin[i] = destin[i];
	}
}
//�����˷�
void multiply(char a[],char b[],char result[])
{
	//printf("this is multiply!!!\n");
	//printf("%s * %s = \n",a,b);
	/*
	BUG#001:
	char c[15][15]; ���Ȳ����������ݣ� ��15�ĳ�30�󣬻ָ�����
	*/
	memset(c,0,sizeof(c));
	//���濪ʼ��ƴ����˷��㷨
	int len_a = len(a),len_b = len(b);
	//������a����b
	int i,j;
	for(i = len_a - 1,j = 0; i >= 0; i--,j++)
	{
		//������
		//1���Ȳ���
		int k = 0;
		while(k < j)
		{
			c[j][k] = '0';
			k++;
		}
		int incre = 0;//��λ����
		int r = 0;//�м���
		//2����a��ÿһλ��������b���洢����ά����c��
		for(int l = len_b - 1; l >= 0; l--)
		{
			r = charToint(a[i]) * charToint(b[l]) + incre;
			if(r > 9)
			{
				c[j][k] = intTochar(r % 10);
				incre = r / 10;
				if(l == 0) //�����������λ��λ
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
	//3����c�����е��м��������ۼӣ��õ����ս��
	result[0] = '0';
	result[1] = '\0';
	for(int m = 0; m < len_a; m++)
	{
		//printf("c[m]: %s\n",c[m]);
		add(result,c[m],result);
	}
	reverse(result);
}
//��������
void minus(char a[],char b[],char res[])
{
	//a - b
	int len_a = len(a),len_b = len(b);
	int i = len_a - 1,j = len_b - 1,k = 0;
	int borrow = 0;//��λ
	while(i >= 0)
	{
		int sa = charToint(a[i]),sb = j >= 0 ? charToint(b[j]) : 0;
		sa -= borrow;
		borrow = 0;
		if(sa < sb)
		{
			borrow = 1;//��λ��һ
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

	if(!all_zero)//����ȫ�� 
	{
		int zero_pos = k - 1;//ȥ��
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
�˺������������������������õ��̺�����������������ַ�������
a / b = c ...... d
�������b����ת��Ϊ���Ρ���
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
		char *sa = cut(a,start,end);//��̬����,�ǵ��ͷ�
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
			//�˷�������
			/*
			BUG001�޸��� product  product2
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
			while(pos1 < len_r)//ȥ��
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
			//��һλ
			end += 1;
			if(end >= len_a)//�����յ�
			{
				//��������ӵ������
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
				//������λ
				sa[pos2] = a[end];
				pos2++;
				sa[pos2] = '\0';
				while(bigger(sa,b) == -1)
				{
					res[k] = '0';//����
					k++;

					end += 1;
					if(end >= len_a)//�����յ�
					{
						//��������ӵ������
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
		return 1;//C�����з���Ϊ��
	else
		return 0;
}
//շת�����
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

int isEven(char n[])// ���� odd num  ż�� even num
{
	int len_n = len(n);
	if(n[len_n - 1] == '0' || n[len_n - 1] == '2' || n[len_n - 1] == '4' || n[len_n - 1] == '6' || n[len_n - 1] == '8')
		return 1;
	else
		return 0;
}

//�������
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
	gcd(a,b,res);//��ʱ
	gcd2(a,b,res);//��ʱ
	//minus(a,b,res);
	//printf("%s - %s = %s",a,b,res);
	return 0;
}
