#include <iostream>
#include <vector>
#include <deque>
using namespace std;
typedef struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
} TreeNode;
vector<int> rightSideView(TreeNode* root)
{
	vector<int> v;
	if(root)
	{
		deque<TreeNode*> q;
		//int enq[105] = {};//记录是否入队 。。二叉树好像不需要这个数组 
		q.push_back(root);
		while(q.size() != 0)
		{
			vector<int> ve;
			for(int i = q.size();i > 0;i--)
			{
				TreeNode* node = q.front();
				ve.push_back(node -> val);
				q.pop_front();
				if(node -> left)q.push_back(node -> left);
				if(node -> right)q.push_back(node -> right);
			}
			v.push_back(ve[ve.size()-1]);
		}
		
	}
	return v;
}
int main()
{
	return 0;
}
