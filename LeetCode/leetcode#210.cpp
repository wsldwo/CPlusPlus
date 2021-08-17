#include <iostream>
#include <vector>
#include <unordered_map>
#include <deque>
using namespace std;
vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
	unordered_map <int, vector<int>> m;
	int inDegree[100005] = {};
	for (int i = 0; i < prerequisites.size(); i++) {
		inDegree[prerequisites[i][0]]++;//����ÿһ�ſγ̵ĳ�ʼ���
		m[prerequisites[i][1]].push_back(prerequisites[i][0]);//��¼ÿһ�ſγ̵����к����γ�
	}
	deque <int> q;
	for (int i = 0; i < numCourses; i++) {
		if (inDegree[i] == 0)
			q.push_back(i);//�����������Ϊ0�Ŀγ�
	}
	int course_num = 0;//��¼ѡ������
	vector <int> v;//��¼ѡ�η���
	while (q.size() != 0) {
		int cn = q.front();
		q.pop_front();
		course_num++;//ѡ������1
		v.push_back(cn);//ѡ��γ�cn
		for (int i = 0; i < m[cn].size(); i++) {
			inDegree[m[cn][i]]--;//��ǰ�γ̵����к����γ���ȼ�1
			if (inDegree[m[cn][i]] == 0) //�����ſ����Ϊ0����������
				q.push_back(m[cn][i]);
		}
	}
	if (course_num != numCourses)
		v.clear();
	return v;
}
/*for(auto it:m)
	{
		cout << it.first << "  " ;
		for(int i = 0;i < it.second.size();i++)
		cout << it.second[i] << " ";
		cout << endl;
	}*/
//cout << m[5].size() << " :m5" << endl;
//int enq[5005] = {};//��¼�γ��Ƿ���ʹ�
int main() {
	vector<vector<int>> v;
	vector<int> v1 {1, 0};
	vector<int> v2 {2, 0};
	vector<int> v3 {3, 1};
	vector<int> v4 {3, 2};
	//vector<int> v5 {5, 3};
	//vector<int> v6 {5, 4};
	//vector<int> v7 {10,11};
	//vector<int> v8 {11,2};
	v.push_back(v1);
	v.push_back(v2);
	v.push_back(v3);
	v.push_back(v4);
	//v.push_back(v5);
	//v.push_back(v6);
	//v.push_back(v7);
	//v.push_back(v8);
	//v.push_back(v1);
	//v.push_back(v2);
	vector<int> ve = findOrder(4, v);
	for (int i = 0; i < ve.size(); i++) {
		cout << ve[i] << " ";
	}
	return 0;
}