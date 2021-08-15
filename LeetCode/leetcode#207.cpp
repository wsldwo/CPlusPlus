#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <deque>
using namespace std;
bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
	unordered_map <int,vector<int>> m;//记录每一们课程的所有前驱课程
	int max_course_no = 0;//一点小优化
	for(int i = 0; i < prerequisites.size(); i++)
	{
		m[prerequisites[i][0]].push_back(prerequisites[i][1]);
		if(prerequisites[i][0] > max_course_no)
			max_course_no = prerequisites[i][0];
	}
	for(int i = 0; i <= max_course_no; i++)//BugFix: i < prerequisites.size()  ============>>  i < numCourses  ============>> i <= max_course_no
	{
		if(m[i].size() != 0)//课程i存在前驱课程
		{
			unordered_set <int> s;
			deque <int> q;
			q.push_back(i);
			s.emplace(i);
			while(q.size() != 0)
			{
				for(int j = q.size(); j > 0; j--)
				{
					int cn = q.front();
					q.pop_front();
					for(int k = 0; k < m[cn].size(); k++)
					{
						if(m[cn][k] == i)//重新回到起点，形成闭环，无法满足
							return false;
						if(s.count(m[cn][k]) == 0)
						{
							q.push_back(m[cn][k]);
							s.emplace(m[cn][k]);
						}
					}
				}
			}
		}
	}
	return true;
}
/*for(auto it:m)
	{
		cout << it.first << "  " ;
		for(int i = 0;i < it.second.size();i++)
		cout << it.second[i] << " ";
		cout << endl;
	}*/
//cout << m[5].size() << " :m5" << endl;
//int enq[5005] = {};//记录课程是否访问过
int main()
{
	vector<vector<int>> v;
	vector<int> v1 {2,3};
	vector<int> v2 {3,2};
	/*vector<int> v3 {9,10};
	vector<int> v4 {10,0};
	vector<int> v5 {1,2};
	vector<int> v6 {2,10};
	vector<int> v7 {10,11};
	vector<int> v8 {11,2};
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);
	v.push_back(v6);
	v.push_back(v7);
	v.push_back(v8);*/
	v.push_back(v1);
	v.push_back(v2);
	cout << canFinish(8,v) << endl;
	return 0;
}
