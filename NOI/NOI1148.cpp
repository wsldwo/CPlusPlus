#include <iostream>
#include <vector> 
using namespace std;
int N,COUNT,USE[11];//0Ϊδʹ�� 1Ϊ��ʹ��
vector <int> QUEUE;
void dfs()
{
	if(COUNT == N)
	{
		for(int i = 0;i < QUEUE.size();i++)
		cout << QUEUE[i] << " ";
		cout << endl;
		return;
	} 
	for(int i = 1;i<= N;i++)
	{
		if(USE[i] == 0)
		{
			QUEUE.push_back(i);//��β���� 
			COUNT += 1;//������һ 
			USE[i] = 1;//��ʹ�� 
			dfs();
			USE[i] = 0;//δʹ�� 
			COUNT -= 1;//������һ 
			QUEUE.pop_back();//��βɾ�� 
		}
	}
} 
int main()
{
	cin >> N;
	dfs();
	return 0;
} 
