#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int type; //���   0ΪСţ ��1Ϊĸţ
	int age;  //���� 
}Cow;
 
int f_mature_cow (int year)
{
	if(year <= 1 || year == 2 || year == 3 || year == 4)
	{
		return 1;
	}
	
	return f_mature_cow(year - 1) + f_mature_cow(year - 3);
	
}

int f_little_cow (int year)
{
	if(year <= 1 )
	{
		return 0;
	}
	if(year == 2 )
	{
		return 1;
	}
	if(year == 3 )
	{
		return 2;
	}
	if(year == 4 )
	{
		return 3;
	}
	
	return f_little_cow(year - 1) + f_little_cow(year - 3);
	
}

int f_cow(int year)
{
	if(year <= 1 )
	{
		return 1;
	}
	if(year == 2 )
	{
		return 2;
	}
	if(year == 3 )
	{
		return 3;
	}
	return f_cow(year - 1) + f_cow(year - 3);

}

int main()
{
	int year; 
	//Cow cow[200000];
	//int mature_cow[60],little_cow[60];//�洢ÿ���ĸţ��Сţ���� 
	while(scanf("%d",&year))//��C�����У�0Ϊ�٣���0Ϊ�棬scanf�����벻ƥ��ʱ������0 
	{
		if(year == 0)break;
		/*
		int mature_cow = 1,little_cow = 0; 
		for(int i = 1;i < year;i ++)
		{
			little_cow += mature_cow;//ĸţÿ����һСţ 
			mature_cow += 0;//Сţ3��������Ϊĸţ 
			printf("%d\n",mature_cow + little_cow);
		}
		
		int cow_amount = 1;
		cow[0].age = 3;
		cow[0].type = 1;
		for(int i = 1;i < year;i ++)
		{
			for(int j = 0;j < cow_amount;j++)
			{
				if(cow[j].type == 1)
				{
					cow_amount ++;//ĸţ��Сţ��
					cow[cow_amount - 1].type = 0;
					cow[cow_amount - 1].age = 0;
				} 
				cow[j].age += 1;
				if(cow[j].age >= 3){
					cow[j].type = 1; //Сţ��ĸţ�� 
				}
			}
		}
		
		printf("%d\n",cow_amount);
		
		
		for(int i = 0;i < cow_amount;i ++)//���ýṹ������ 
		{
			cow[i].age = 0;
			cow[i].type = 0;
		}
		
		*/
		
		//printf("��%d��ĸţ������%d\n",year,f_mature_cow(year) + f_little_cow(year));
		printf("%d\n",f_cow(year));
	}
	return 0;
}
