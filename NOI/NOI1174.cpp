#include <iostream>
#include <cstring>
#define DATA_LENGTH 12
using namespace std;
int N,ANS = 0,NUMBER[DATA_LENGTH + 1],QUEUE[DATA_LENGTH + 1],ANSWER[DATA_LENGTH + 1];
//NUMBER��¼�����Ƿ�ʹ��
//��¼����
//���ݷ�
//no:����ӵ���������
void dfs(int no)
{
	if(no < N)
	{
		/*
		��֦�Ż���������1ʼ�շŵ���һ��λ�ã�����ݴ�����2��ʼ 
		���ʵ�������
		*/
		for(int i = 2; i <= N; i++)
		{
			if(NUMBER[i] == 0)
			{
				NUMBER[i] = 1;
				QUEUE[no] = i;
				dfs(no + 1);
				NUMBER[i] = 0;
				QUEUE[no] = 0;
			}
		}
	}
	else
	{
		int temp = 0;
		QUEUE[N] = QUEUE[0];
		/*
		for(int i = 0;i < N;i++)
		{
			cout<<QUEUE[i]<<" ";
		}
		cout<<endl;
		*/
		for(int i = 0; i < N; i++)
		{
			temp += (QUEUE[i] - QUEUE[i + 1]) * (QUEUE[i] - QUEUE[i + 1]);
		}
		QUEUE[N] = 0;
		if(temp > ANS)
		{
			ANS = temp;
			
			for(int i = 0; i < N; i++)
			{
				ANSWER[i] = QUEUE[i];
			}
			
		}
	}
}

int main()
{
	cin>>N;
	memset(NUMBER,0,sizeof(NUMBER));//��������
	memset(QUEUE,0,sizeof(QUEUE));//��������
	memset(ANSWER,0,sizeof(ANSWER));//��������
	/*
	��֦�Ż���������1ʼ�շŵ���һ��λ�ã�����ݴ�����2��ʼ 
	���ʵ������� 
	*/
	NUMBER[1] = 1;
	QUEUE[0] = 1;
	dfs(1);
	
	for(int i = 0; i < N; i++)
	{
		cout<<ANSWER[i]<<" ";
	}
	cout<<endl;
	
	cout<<ANS;
	return 0;
}
