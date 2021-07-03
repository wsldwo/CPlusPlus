#include <iostream>
#include <vector> 
using namespace std;
int N,COUNT,USE[11];//0为未使用 1为已使用
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
			QUEUE.push_back(i);//队尾插入 
			COUNT += 1;//计数加一 
			USE[i] = 1;//已使用 
			dfs();
			USE[i] = 0;//未使用 
			COUNT -= 1;//计数减一 
			QUEUE.pop_back();//队尾删除 
		}
	}
} 
int main()
{
	cin >> N;
	dfs();
	return 0;
} 
