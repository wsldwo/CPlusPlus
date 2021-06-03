#include <stdio.h>
/*
���ݷ� 
����֪�������C���ݰ汾Ҫ��ôд��,������ʹ������洢ѧ�����鼮���ݣ��ؼ��ǡ�������ˡ� ��������ǵ�Ҫ���顱 
����ĳ�ʼ״̬��Ϊʹ����򵥻�������տ�ʼʱѧ��i�����鱾i��
i:��ǰѧ����� 
n:�����ģ����ѧ�����鼮���� 
students:ѧ���б�students[i]��ʾ��i��ѧ�������е���ı�ţ�0Ϊδ�õ��飬�������ʾ�Ѿ��õ��� 
books:�鼮�б� ��books[i]��ʾ��i�����Ƿ񱻷��䣬0Ϊδ���䣬1Ϊ�ѷ��� 
solu:�������� 
*/
void dfs(int i,int n,int *students,int *books,int *solu)
{
	if(i > n)
	{
		*solu += 1;//�鷢���� 
		 printf("----------����%d��----------\n",*solu);
		 for(int k = 1;k <= n;k++)
		 {
		 	printf("ѧ��%d�����鼮%d��",k,students[k]);
		 }
		 printf("\n",*solu); 
	}
	else
	{
		//�����Ϊi��ѧ������ 
		for(int j = 1;j <= n;j++)//һ��ʹ��forѭ�����ַ�֧��· 
		{
			if(j != i && !books[j])//�Ȿ�鲻��ѧ��i֮ǰ�õ��Ǳ��飬�����Ȿ��δ������ 
			{
				//����
				books[j] = i;//���鼮j����ѧ��i 
				students[i] = j; //ѧ��i�����鼮j 
				dfs(i + 1,n,students,books,solu);
				//����
				//��ͬ��python��C���Ի�����ɺ���Ҫ������ֵ����Ȼ��Ӱ��������֧·�ߣ�python���ݵ����б���������������� 
				books[j] = 0;
				students[i] = 0;
			}
		} 
	} 
	
}
// -1 ��n�η� 
int factor_m1(int n)
{
	if(n % 2 == 0)
	return 1;
	else
	return -1;
} 
/*
���ƹ�ʽ�� 
�۲�python����д�����ĵ��ƹ�ʽ����ʱû�뵽c����Ӧ����ôд 
*/
long long cal(int n)
{
	long long num[21];
	num[1] = 0,num[2] = 1;
	for(int i = 3;i <= n;i++)
	{
		//�Լ����ֵĹ�ʽ f(n) = n * f(n - 1) + pow(-1,n)
		num[i] = i * num[i - 1] + factor_m1(i);
		//��ʵ������д�� f(n) = (n - 1) * (f(n - 1) + f(n - 2)) 
	}
	return num[n];
} 
int main()
{
	int n,solu = 0;
	scanf("%d",&n);
	int students[n + 1],books[n + 1];
	memset(students,0,sizeof(students));//ʹ��memset��ʼ�����飬����1Ϊ������������2Ϊ��ʼֵ������3Ϊ����Ĵ�С 
	memset(books,0,sizeof(books));//ʹ��memset��ʼ�����飬����1Ϊ������������2Ϊ��ʼֵ������3Ϊ����Ĵ�С 
	dfs(1,n,students,books,&solu);
	printf("%d",solu);
	/*
	for(int i = 0;i <= n;i++)
	{
		printf("%d  %d\n",students[i],books[i]);
	}
	*/
	//printf("%lld",cal(n));
	return 0;
} 
