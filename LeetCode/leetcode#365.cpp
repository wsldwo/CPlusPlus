#include <iostream>
#include <vector>
#include <deque>
#include <unordered_set>

using namespace std;
bool canMeasureWater1(int jug1Capacity, int jug2Capacity, int targetCapacity)//vector<pair<int,int>>超时
{
	if (jug1Capacity == targetCapacity || jug2Capacity == targetCapacity || jug1Capacity + jug2Capacity == targetCapacity)
		return true;
	if (targetCapacity > jug1Capacity + jug2Capacity)
		return false;
	vector<pair<int, int>> v; //记录已出现过的状态
	deque<pair<int, int>> q;
	q.push_back(make_pair(0, 0));
	v.push_back(make_pair(0, 0));
	while (q.size() != 0)
	{
		pair<int, int> p = q.front();
		q.pop_front();
		//cout << "jug1:" << p.first << "  jug2:" << p.second << endl;
		if (p.first == targetCapacity || p.second == targetCapacity || p.first + p.second == targetCapacity)
			return true;
		int jug1 = p.first, jug2 = p.second;
		//jug1 into jug2
		if (jug1 == 0)jug1 = jug1Capacity;
		if (jug2 == jug2Capacity)jug2 = 0;
		int jug2_left = jug2Capacity - jug2;
		if (jug2_left >= jug1)
		{
			jug2 += jug1;
			jug1 = 0;
		}
		else
		{
			jug1 -= jug2_left;
			jug2 = jug2Capacity;
		}
		bool visited = false;
		//cout <<" temp "<< "jug1:" << jug1 << "  jug2:" << jug2 << endl;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].first == jug1 && v[i].second == jug2)
			{
				visited = true;
				break;
			}
		}
		if (!visited)
		{
			q.push_back(make_pair(jug1, jug2));
			v.push_back(make_pair(jug1, jug2));
		}
		//jug2 into jug1
		jug1 = p.first, jug2 = p.second;
		if (jug2 == 0)jug2 = jug2Capacity;
		if (jug1 == jug1Capacity)jug1 = 0;
		int jug1_left = jug1Capacity - jug1;
		if (jug1_left >= jug2)
		{
			jug1 += jug2;
			jug2 = 0;
		}
		else
		{
			jug2 -= jug1_left;
			jug1 = jug1Capacity;
		}
		visited = false;
		//cout <<" temp "<< "jug1:" << jug1 << "  jug2:" << jug2 << endl;
		for (int i = 0; i < v.size(); i++)
		{
			if (v[i].first == jug1 && v[i].second == jug2)
			{
				visited = true;
				break;
			}
		}
		if (!visited)
		{
			q.push_back(make_pair(jug1, jug2));
			v.push_back(make_pair(jug1, jug2));
		}
	}
	return false;
}

void enqueue(unordered_set<size_t>& s,deque<pair<int, int>>& q,int jug1,int jug2)
{
	size_t val = (size_t)jug1 * 10000779 + jug2;//hash公式，尽量确保值是唯一的
	if(s.find(val) == s.end())
	{
		s.insert(val);
		q.push_back(make_pair(jug1, jug2));
	}
}

bool canMeasureWater2(int jug1Capacity, int jug2Capacity, int targetCapacity)
{
	if (jug1Capacity == targetCapacity || jug2Capacity == targetCapacity || jug1Capacity + jug2Capacity == targetCapacity)
		return true;
	if (targetCapacity > jug1Capacity + jug2Capacity)
		return false;
	//vector<pair<int, int>> v; //记录已出现过的状态
	unordered_set<size_t> s;//size_t <==> long long unsigned int
	deque<pair<int, int>> q;
	enqueue(s,q,0,0);
	//q.push_back(make_pair(0, 0));
	//v.push_back(make_pair(0, 0));
	while (q.size() != 0)
	{
		pair<int, int> p = q.front();
		q.pop_front();
		//cout << "jug1:" << p.first << "  jug2:" << p.second << endl;
		if (p.first == targetCapacity || p.second == targetCapacity || p.first + p.second == targetCapacity)
			return true;
		int jug1 = p.first, jug2 = p.second;
		//jug1 into jug2
		if (jug1 == 0)jug1 = jug1Capacity;
		if (jug2 == jug2Capacity)jug2 = 0;
		int jug2_left = jug2Capacity - jug2;
		if (jug2_left >= jug1)
		{
			jug2 += jug1;
			jug1 = 0;
		}
		else
		{
			jug1 -= jug2_left;
			jug2 = jug2Capacity;
		}
		enqueue(s,q,jug1,jug2);
		//jug2 into jug1
		jug1 = p.first, jug2 = p.second;
		if (jug2 == 0)jug2 = jug2Capacity;
		if (jug1 == jug1Capacity)jug1 = 0;
		int jug1_left = jug1Capacity - jug1;
		if (jug1_left >= jug2)
		{
			jug1 += jug2;
			jug2 = 0;
		}
		else
		{
			jug2 -= jug1_left;
			jug1 = jug1Capacity;
		}
		enqueue(s,q,jug1,jug2);
	}
	return false;
}


int main()
{
	//cout << canMeasureWater1(22003,31237,1);//3.393s
	cout << canMeasureWater2(22003,31237,1);//0.538s
	return 0;
}
