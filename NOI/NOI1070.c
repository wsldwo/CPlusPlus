#include <stdio.h>
/*
����˵����
n:�����ģ������������ 
name:����´����ӵ�����
times:��������������ʹ�õ�ַ���ݣ�ֵ����ֵ����仯 
start,transfer,end:��ʼ�����ƣ���ת�����ƣ��յ������ƣ����������ӵ�λ�û���������ı����̬�ı䣩 
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
		��ɺ�ŵ����Զֻ��������
		1�����������ϵ� n - 1 ��С�����˵���ת��
		2����������ֱ�Ӵ�������˵��յ���
		3�����ղ� n - 1 ��С���Ӵ���ת���˵��յ��� 
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
