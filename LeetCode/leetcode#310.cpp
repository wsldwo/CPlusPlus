#include <iostream>
#include <vector>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)//仍然超时
{
	unordered_map <int, vector<int>> m, h;
	for (int i = 0; i < edges.size(); i++)
	{
		m[edges[i][0]].push_back(edges[i][1]);
		m[edges[i][1]].push_back(edges[i][0]);
	}
	int min_height = 0;
	for (int i = 0; i < n; i++)
	{
		//枚举根节点
		deque<int> q;
		int enq[20005] = {};
		q.push_back(i);
		enq[i] = 1;
		int height = -1;
		while (q.size() != 0)
		{
			height += 1;
			if (height > min_height && min_height != 0)//优化1：当前高度大于最小高度，跳出
				break;
			for (int j = q.size(); j > 0; j--)
			{
				int node = q.front();
				q.pop_front();
				for (int k = 0; k < m[node].size(); k++)
					if (!enq[m[node][k]])
					{
						q.push_back(m[node][k]);
						enq[m[node][k]] = 1;
					}
			}
		}
		h[height].push_back(i);
		if (min_height == 0 || height < min_height)
			min_height = height;
	}
	return h[min_height];
}

vector<int> findMinHeightTrees2(int n, vector<vector<int>>& edges)//拓扑排序思路
{
	if (n == 1) return {0};
	vector<unordered_set<int>> adj(n);
	vector<int> res;
	queue<int> q;
	for (auto edge : edges)
	{
		adj[edge[0]].insert(edge[1]);
		adj[edge[1]].insert(edge[0]);
	}
	for (int i = 0; i < n; i++)
	{
		if (adj[i].size() == 1) q.push(i);
	}
	while (n > 2)
	{
		int size = q.size();
		n -= size;
		while (size-- > 0)
		{
			auto t = q.front();
			q.pop();
			for (auto itm : adj[t])
			{
				adj[itm].erase(t);
				if (adj[itm].size() == 1) q.push(itm);
			}
		}
	}
	while (!q.empty())
	{
		res.push_back(q.front());
		q.pop();
	}
	return res;
}

int main()
{
	vector<int> v1{1, 0};
	vector<int> v2{1, 2};
	vector<int> v3{1, 3};
	vector<vector<int>> v;
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	findMinHeightTrees(4, v);
	return 0;
}
