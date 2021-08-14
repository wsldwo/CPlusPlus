#include <iostream>
#include <vector>
#include <deque>
using namespace std;

int numIslands(vector<vector<char>>& grid)
{
	int m = grid.size(),n = grid[0].size(),island_num = 0;//m 行 n 列
	//cout << "m:" << m << " n:" << n << endl;
	int visited[305][305] = {};//记录节点是否访问 
	for(int i = 0;i < m;i++)
	{
		for(int j = 0;j < n;j++)
		{
			if(grid[i][j] == '1' && !visited[i][j])
			{
				island_num += 1;
				deque <pair<int,int>> q;
				q.push_back(make_pair(i,j));
				visited[i][j] = 1;
				while(q.size() != 0)
				{
					//cout << "q_size:" << q.size() << endl;
					for(int k = q.size();k > 0;k--)
					{
						pair<int,int> p = q.front();
						q.pop_front();
						if(p.second - 1 >= 0 && grid[p.first][p.second - 1] == '1' && !visited[p.first][p.second - 1])//左侧 
						{
							q.push_back(make_pair(p.first,p.second - 1));
							visited[p.first][p.second - 1] = 1;
						}
						if(p.second + 1 < n && grid[p.first][p.second + 1] == '1' && !visited[p.first][p.second + 1])//右侧 
						{
							q.push_back(make_pair(p.first,p.second + 1));
							visited[p.first][p.second + 1] = 1;
						}
						if(p.first - 1 >= 0 && grid[p.first - 1][p.second] == '1' && !visited[p.first - 1][p.second])//上方 
						{
							q.push_back(make_pair(p.first - 1,p.second));
							visited[p.first - 1][p.second] = 1;
						}
						if(p.first + 1 < m && grid[p.first + 1][p.second] == '1' && !visited[p.first + 1][p.second])//下方 
						{
							q.push_back(make_pair(p.first + 1,p.second));
							visited[p.first + 1][p.second] = 1;
						} 
					}
				} 
			}
		}
	}
	return island_num;
}

int main()
{
	vector<char> v1{'1','1','0','0','0'};
	vector<char> v2{'1','1','0','0','0'}; 
	vector<char> v3{'0','0','1','0','0'}; 
	vector<char> v4{'0','0','0','1','1'};
	vector <vector<char>> v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	cout << numIslands(v) << endl;
	return 0;
}
