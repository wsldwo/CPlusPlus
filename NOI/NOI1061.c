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
		return 1;//��C�����У�0Ϊ�٣�����Ϊ�� 
	else
		return 0;//��C�����У�0Ϊ�٣�����Ϊ�� 
}
int main()
{
	char conti,password[10],true_pass[10] = "NOIP@CCF";
	/*
	�´ο�������while(scanf("%d",&n)!=EOF) 
	��ʱ���EOF? ��stdio.h�к궨��Ϊ-1������˵����
	scanf����ֻ���ڵ�һ������ΪNULL(��ָ��)��״���£��ſ��ܷ���EOF��
	��Ȼ�����سɹ���ʽ������ֵ�Ĳ�������(>=0)��
	scanf()�������سɹ���ֵ����������������ʱ�򷵻أ�EOF����Ϊ-1��
	~�ǰ�λȡ����-1ʮ�����Ʋ����ʾΪ0x ffffffff��f�Ƕ����Ƶ�1111��ȡ�����ȫ�����0�ˣ�����while������
	ֻ�з���ֵΪEOF����-1��ʱ����ȡ���ĵ�ֵ����whileѭ�����ж���������Ϊ0�����ܽ���ѭ����
	������������£������Ƿ�����ɹ���whileѭ�����ж�����Ϊ��0����Ϊ�档
	
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
				//��Ŀ��˼û�����������������ȷ���ֱ��break��
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
