#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Node
{
	public:
		int val;
		vector<Node*> neighbors;
		Node()
		{
			val = 0;
			neighbors = vector<Node*>();
		}
		Node(int _val)
		{
			val = _val;
			neighbors = vector<Node*>();
		}
		Node(int _val, vector<Node*> _neighbors)
		{
			val = _val;
			neighbors = _neighbors;
		}
};

Node* cloneGraph(Node* node)
{
	if(node)
	{
		if(node->neighbors.size())
		{
			Node* _ns[101];
			for(int i = 1; i <= 100; i++)
				_ns[i] = new Node(i);//�ڶ��Ͽ��ڴ�
			//Ҫ��ʼBFS�ˣ�����
			deque <Node*> q;
			int visited[101] = {},enq[101] = {};//visited ��¼�Ƿ����   enq��¼�Ƿ���� 
			q.push_back(node);
			enq[1] = 1;
			while(q.size() != 0)
			{
				/*cout << "q_size:" << q.size() << endl;
				cout << "deque:  ";
				for(int i = 0; i < q.size(); i++)
					cout << q[i] -> val << " ";
				cout << endl;*/
				int q_size = q.size();//bug_fix
				for(int i = 0; i < q_size; i++)//���ﲻ��ʹ��q.size()����Ϊ�±߻�����ӵĽڵ㣬�ᵼ��q.size()����
				{
					Node* _n = q.front();
					//cout << "cur_node: "<< _n -> val << endl;
					q.pop_front();
					if(!visited[_n -> val])
					{
						//cout << "neighbors:";
						for(int j = 0; j < _n -> neighbors.size(); j++)
						{
							//cout << _n -> neighbors[j] -> val << "  ";
							_ns[_n -> val] -> neighbors.push_back(_ns[_n -> neighbors[j] -> val]);//���п���
							if(!enq[_n -> neighbors[j] -> val])
							{
								/*
								��Bug����һ���硣�� 
								node -> neighbors[j] =============>> _n -> neighbors[j]
								*/ 
								q.push_back(_n -> neighbors[j]);//��һ��ڵ����
								enq[_n -> neighbors[j] -> val] = 1;//�����
							}
						}
						//cout << endl;
						visited[_n -> val] = 1;//�ѷ���
					}
				}
				//cout << endl;
			}
			return _ns[1];
		}
		else
		{
			Node* _n = new Node(1);
			return _n;
		}
	}
	else
	{
		return NULL;
	}
}

int main()
{
	Node node[5];
	for(int i = 1; i <= 4; i++)
		node[i].val  = i;
	node[1].neighbors.push_back(&node[2]);
	node[1].neighbors.push_back(&node[4]);
	node[2].neighbors.push_back(&node[1]);
	node[2].neighbors.push_back(&node[3]);
	node[3].neighbors.push_back(&node[2]);
	node[3].neighbors.push_back(&node[4]);
	node[4].neighbors.push_back(&node[1]);
	node[4].neighbors.push_back(&node[3]);
	cloneGraph(&node[1]);
	return 0;
}
