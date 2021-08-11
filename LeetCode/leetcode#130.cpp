#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void solve(vector<vector<char>>& board)
{
	typedef struct{int x,y;}pos;
	int m = board.size(), n = board[0].size();// m �� n ��
	int visited[205][205] = {};//��ʼ��Ϊ��
	for(int i = 1;i < m - 1;i++)//ֱ�Ӵӵ�2�п�ʼ 
	{
		for(int j = 1;j < n - 1;j++)//ֱ�Ӵӵ�2�п�ʼ
		{
			cout << "i:" << i << " j:" << j << endl; 
			if(visited[i][j] == 0 && board[i][j] == 'O')
			{//��ʼBFS 
				queue <pos> q; // BFSʹ�õĶ��� 
				vector <pos> v; //�洢��һ����Χ���������� 
				pos p = {i,j};
				q.push(p);
				v.push_back(p);
				visited[i][j] = 1;
				bool alive = false;
				while(q.size() != 0)
				{
					cout << "q_size:" << q.size() << endl;
					for(int k = q.size();k > 0;k--)//��Щ"����"�໥��ͨ 
					{
						pos _p = q.front();
						cout << "_p.x:" << _p.x << "_p.y:" << _p.y << endl;
						q.pop();
						if(_p.y - 1 >= 0 && board[_p.x][_p.y - 1] == 'O' && !visited[_p.x][_p.y - 1])//��� 
						{
							visited[_p.x][_p.y - 1] = 1;
							pos po = {_p.x,_p.y - 1};
							q.push(po);
							v.push_back(po);
							if(_p.x == 0 || _p.x == m - 1 || _p.y - 1 == 0 || _p.y - 1 == n - 1)alive = true; 
						}
						if(_p.y + 1 < n && board[_p.x][_p.y + 1] == 'O' && !visited[_p.x][_p.y + 1])//�Ҳ� 
						{
							visited[_p.x][_p.y + 1] = 1;
							pos po = {_p.x,_p.y + 1};
							q.push(po);
							v.push_back(po);
							if(_p.x == 0 || _p.x == m - 1 || _p.y + 1 == 0 || _p.y + 1 == n - 1)alive = true; 
						}
						if(_p.x - 1 >= 0 && board[_p.x - 1][_p.y] == 'O' && !visited[_p.x - 1][_p.y])//�ϲ� 
						{
							visited[_p.x - 1][_p.y] = 1;
							pos po = {_p.x - 1,_p.y};
							q.push(po);
							v.push_back(po);
							if(_p.x - 1 == 0 || _p.x - 1 == m - 1 || _p.y == 0 || _p.y == n - 1)alive = true; 
						}
						if(_p.x + 1 < m && board[_p.x + 1][_p.y] == 'O' && !visited[_p.x + 1][_p.y])//�²�
						{
							visited[_p.x + 1][_p.y] = 1;
							pos po = {_p.x + 1,_p.y};
							q.push(po);
							v.push_back(po);
							if(_p.x + 1 == 0 || _p.x + 1 == m - 1 || _p.y == 0 || _p.y == n - 1)alive = true; 
						} 
					}
					//��ʱ�����У�ֻ������һ��ڵ� 
				}
				if(!alive)//��ǰ�Ⲩ����Ϊ"����" 
				{
					for(int l = 0;l < v.size();l++)
					{
						board[v[l].x][v[l].y] = 'X'; 
					}	
				}
			}
		}
	} 
}

int main()
{
	vector<vector<char>> board;
	vector<char> b1{'X','X','X','X'};
	vector<char> b2{'X','O','O','X'};
	vector<char> b3{'X','X','O','X'};
	vector<char> b4{'X','O','X','X'};
	board.push_back(b1);
	board.push_back(b2);
	board.push_back(b3);
	board.push_back(b4);
	
	solve(board);
	
	return 0;
}
