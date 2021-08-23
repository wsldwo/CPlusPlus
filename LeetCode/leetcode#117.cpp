#include <iostream>
#include <deque>
using namespace std;
class Node
{
	public:
		int val;
		Node* left;
		Node* right;
		Node* next;
		Node() : val(0), left(NULL), right(NULL), next(NULL) {}
		Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}
		Node(int _val, Node* _left, Node* _right, Node* _next)
			: val(_val), left(_left), right(_right), next(_next) {}
};
Node* connect(Node* root)
{
	if (root)
	{
		deque <Node*> q;
		q.push_back(root);
		while (!q.empty())
		{
			for (int i = q.size(); i > 0; i--)
			{
				Node* node1;
				Node* node2;
				node1 = q.front();
				q.pop_front();
				if(i > 1)
				{
					node2 = q.front();
					node1->next = node2;
				}
				if(node1->left)
				q.push_back(node1->left);
				if(node1->right)
				q.push_back(node1->right);
			}
		}
	}
	return root;
}
int main()
{
	return 0;
}
