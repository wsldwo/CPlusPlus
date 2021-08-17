#include <stdio.h>
#include <string.h>
#define DATA_LENGTH 1500
char c[DATA_LENGTH][DATA_LENGTH * 2];//��������Ҫ�����ȫ�ֱ��� 

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

int main()
{
	char a[DATA_LENGTH],b[DATA_LENGTH],res[DATA_LENGTH * 2];
	scanf("%s %s",a,b);
	multiply(a,b,res);
	printf("%s * %s = %s\n",a,b,res);
	return 0;
}
