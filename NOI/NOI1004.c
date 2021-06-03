/*
����֮�����������������
2����16λ����ȡֵ��Χ�ǣ�-32768 32767                              short 
2����32λ����ȡֵ��Χ�ǣ�-2147483648 2147483647                    int ��long��
2����64λ����ȡֵ��Χ�ǣ�-9223372036854775808 9223372036854775807  long long (__int64)

100��ͨ����C���Գ���֮һ��
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
int len(char *s)//Ҳ��д�� char s[]����Ϊ��������������һ��ָ����� 
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
//�����ӷ� 
void add(char *a,char *b,char *result)
{
	//printf("%s + %s        ",a,b);
	char sum[15];
	int len_a = len(a),len_b = len(b);
	//printf("%d && %d \n",len_a,len_b);
	//1�����벹�� 
	int max_len = len_a > len_b ? len_a : len_b;
	int i;
	for(i = len_a;i < max_len;i++)
	{
		a[i] = '0'; 
	} 
	a[i] = '\0';//ĩβ���� ��ѭ������ʱ����������ָ��ĩβ 
	for (i = len_b;i < max_len;i++)
	{
		b[i] = '0';
	}
	b[i] = '\0';//ĩβ���� ��ѭ������ʱ����������ָ��ĩβ 
	//printf("%s + %s\n",a,b);
	//2���ӷ����� 
	int incre = 0,r = 0;
	for(i = 0;i < max_len;i++)
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
//���� 
void copy(char *origin,char *destin)
{
	int len_des = len(destin);
	for(int i = 0;i <= len_des;i ++)//��i == len_desʱ����Ӧ'\0'�ַ���'\0'ҲӦ�ý��и��� 
	{
		origin[i] = destin[i];
	}
} 
//�����˷� 
void multiply(char *a,char *b,char *result)
{
	/*
	BUG#001:
	char c[15][15]; ���Ȳ����������ݣ� ��15�ĳ�30�󣬻ָ����� 
	*/
	char c[15][30];
	//���濪ʼ��ƴ����˷��㷨
	int len_a = len(a),len_b = len(b);
	//������a����b
	int i,j; 
	for(i = len_a - 1,j = 0;i >= 0;i--,j++)
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
		for(int l = len_b - 1;l >= 0;l--)
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
	while(1)//��C�����У�0Ϊ�٣�����Ϊ�� 
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
	int n,m,a;//1000000000 1000000000 1 ������������Ҫ��ƴ����˷� 
	char n1[15],n2[15],res[30];
	scanf("%d %d %d",&n,&m,&a);
	if(a > n || a > m)
	{
		res[0] = '0';
		res[1] = '\0';
	}
	else
	{
		int t1 = m / a,t2 = n / a;// C ��������������������������������ȡ���� 
		intTostring(t1,n1);
		intTostring(t2,n2);
		multiply(n1,n2,res);
	}
	printf("%s",res);
	return 0;//��C�����У�����0��ʾ�����˳������ط�0��ʾ�쳣�˳��� 
}

