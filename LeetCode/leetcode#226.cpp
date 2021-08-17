#include <iostream>
#include <deque>
using namespace std;
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
TreeNode* invertTree(TreeNode* root)
{
	deque <TreeNode*> q;
	if (root)
	{
		q.push_back(root);
		while (q.size() != 0)
		{
			TreeNode* node = q.front();
			q.pop_front();
			TreeNode* temp = node->left;//对于每一个节点，交换其左右孩子
			node->left = node->right;
			node->right = temp;
			if (node -> left)
				q.push_back(node -> left);
			if (node -> right)
				q.push_back(node->right);
		}
	}
	return root;
}

int main()
{
	return 0;
}
