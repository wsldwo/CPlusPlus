#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int type; //类别   0为小牛 ，1为母牛
	int age;  //年龄 
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
	//int mature_cow[60],little_cow[60];//存储每年的母牛，小牛数量 
	while(scanf("%d",&year))//在C语言中，0为假，非0为真，scanf在输入不匹配时，返回0 
	{
		if(year == 0)break;
		/*
		int mature_cow = 1,little_cow = 0; 
		for(int i = 1;i < year;i ++)
		{
			little_cow += mature_cow;//母牛每年生一小牛 
			mature_cow += 0;//小牛3年整成熟为母牛 
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
					cow_amount ++;//母牛生小牛啦
					cow[cow_amount - 1].type = 0;
					cow[cow_amount - 1].age = 0;
				} 
				cow[j].age += 1;
				if(cow[j].age >= 3){
					cow[j].type = 1; //小牛变母牛啦 
				}
			}
		}
		
		printf("%d\n",cow_amount);
		
		
		for(int i = 0;i < cow_amount;i ++)//重置结构体数组 
		{
			cow[i].age = 0;
			cow[i].type = 0;
		}
		
		*/
		
		//printf("第%d年母牛数量：%d\n",year,f_mature_cow(year) + f_little_cow(year));
		printf("%d\n",f_cow(year));
	}
	return 0;
}
