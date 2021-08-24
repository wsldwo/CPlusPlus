#include <iostream>
#include <vector>
#include <deque>
#include <set>
using namespace std;

vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights)
{
	int m = heights.size(), n = heights[0].size();
	vector<vector<int>> water_type(151, vector<int>(151, -1)); //-1:未鉴定  0：内陆  1：太平洋  2：大西洋  3：太平洋 && 大西洋
	set<pair<int, int>> s;
	deque<pair<int, int>> q;
	vector<vector<int>> water;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << "m:" << m  << " n:" << n << " i:" << i << " j:" << j << endl;
			q.clear();
			s.clear();
			q.push_back(make_pair(i, j));
			s.emplace(make_pair(i, j));
			bool pacific = false, atlantic = false;
			while (!q.empty())
			{
				pair<int, int> p = q.front();
				q.pop_front();
				int x = p.first, y = p.second;
				if (x - 1 >= 0 && heights[x - 1][y] <= heights[x][y]) //向上流动
				{
					if (water_type[x - 1][y] != -1)//状态已计算,继承状态
					{
						switch (water_type[x - 1][y])
						{
							case 1:
								pacific = true;
								break;
							case 2:
								atlantic = true;
								break;
							case 3:
								pacific = true;
								atlantic = true;
								break;
							default:
								break;
						}
						s.emplace(make_pair(x - 1, y));
					}
					else
					{
						if (s.find(make_pair(x - 1, y)) == s.end()) //未找到
						{
							q.push_back(make_pair(x - 1, y));
							s.emplace(make_pair(x - 1, y));
						}
					}
				}
				else if (x - 1 < 0)
				{
					pacific = true;
				}

				if (x + 1 < m && heights[x + 1][y] <= heights[x][y]) //向下流动
				{
					if (water_type[x + 1][y] != -1)//状态已计算,继承状态
					{
						switch (water_type[x + 1][y])
						{
							case 1:
								pacific = true;
								break;
							case 2:
								atlantic = true;
								break;
							case 3:
								pacific = true;
								atlantic = true;
								break;
							default:
								break;
						}
						s.emplace(make_pair(x + 1, y));
					}
					else
					{
						if (s.find(make_pair(x + 1, y)) == s.end()) //未找到
						{
							q.push_back(make_pair(x + 1, y));
							s.emplace(make_pair(x + 1, y));
						}
					}
				}
				else if (x + 1 >= m)
				{
					atlantic = true;
				}

				if (y - 1 >= 0 && heights[x][y - 1] <= heights[x][y]) //向左流动
				{
					if (water_type[x][y - 1] != -1)//状态已计算,继承状态
					{
						switch (water_type[x][y - 1])
						{
							case 1:
								pacific = true;
								break;
							case 2:
								atlantic = true;
								break;
							case 3:
								pacific = true;
								atlantic = true;
								break;
							default:
								break;
						}
						s.emplace(make_pair(x, y - 1));
					}
					else
					{
						if (s.find(make_pair(x, y - 1)) == s.end()) //未找到
						{
							q.push_back(make_pair(x, y - 1));
							s.emplace(make_pair(x, y - 1));
						}
					}
				}
				else if (y - 1 < 0)
				{
					pacific = true;
				}

				if (y + 1 < n && heights[x][y + 1] <= heights[x][y]) //向右流动
				{
					if (water_type[x][y + 1] != -1)//状态已计算,继承状态
					{
						switch (water_type[x][y + 1])
						{
							case 1:
								pacific = true;
								break;
							case 2:
								atlantic = true;
								break;
							case 3:
								pacific = true;
								atlantic = true;
								break;
							default:
								break;
						}
						s.emplace(make_pair(x, y + 1));
					}
					else
					{
						if (s.find(make_pair(x, y + 1)) == s.end()) //未找到
						{
							q.push_back(make_pair(x, y + 1));
							s.emplace(make_pair(x, y + 1));
						}
					}
				}
				else if (y + 1 >= n)
				{
					atlantic = true;
				}

				if (pacific && atlantic)
				{
					water_type[i][j] = 3;
					//vector<int> v{i, j};
					water.push_back(vector<int> {i, j});
					break;
				}
				else if (pacific && !atlantic)
				{
					water_type[i][j] = 1;
				}
				else if (!pacific && atlantic)
				{
					water_type[i][j] = 2;
				}
				else
				{
					water_type[i][j] = 0;
				}

			}
		}
	}

	return water;
}
int main()
{
	vector<int> v1{1, 2, 2, 3, 5};
	vector<int> v2{3, 2, 3, 4, 4};
	vector<int> v3{2, 4, 5, 3, 1};
	vector<int> v4{6, 7, 1, 4, 5};
	vector<int> v5{5, 1, 1, 2, 4};
	vector<vector<int>> heights;
	heights.push_back(v1);
	heights.push_back(v2);
	heights.push_back(v3);
	heights.push_back(v4);
	heights.push_back(v5);
	pacificAtlantic(heights);
	return 0;
}
