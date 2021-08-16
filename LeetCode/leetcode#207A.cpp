#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
using namespace std;
bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
	unordered_map <int,vector<int>> m;
	int inDegree[100005] = {};
	for(int i = 0; i < prerequisites.size(); i++)
	{
        inDegree[prerequisites[i][0]]++;//计算每一门课程的初始入度
		m[prerequisites[i][1]].push_back(prerequisites[i][0]);//记录每一门课程的所有后续课程
	}
    deque <int> q;
    for(int i = 0;i < numCourses;i++)
    {
        if(inDegree[i] == 0)
        q.push_back(i);//添加所有入度为0的课程
    }
    int course_num = 0;//记录选课数量
    while(q.size() != 0)
    {
        int cn = q.front();
        q.pop_front();
        course_num++;//选课数加1
        for(int i = 0;i < m[cn].size();i++)
        {
            inDegree[m[cn][i]]--;//当前课程的所有后续课程入度减1
            if(inDegree[m[cn][i]] == 0)//若这门课入度为0，则进入入队
            q.push_back(m[cn][i]);
        }
    }
	return course_num == numCourses;
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
	vector<int> v1 {3,0};
	vector<int> v2 {3,1};
	vector<int> v3 {1,4};
	vector<int> v4 {4,3};
	vector<int> v5 {5,3};
	vector<int> v6 {5,4};
	//vector<int> v7 {10,11};
	//vector<int> v8 {11,2};
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	v.push_back(v5);
	v.push_back(v6);
	//v.push_back(v7);
	//v.push_back(v8);
	//v.push_back(v1);
	//v.push_back(v2);
	cout << canFinish(8,v) << endl;
	return 0;
}
