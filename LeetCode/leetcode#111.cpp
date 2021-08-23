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
int minDepth(TreeNode* root)
{
	int depth = 0;
	bool first_leaf = false;
	if (root)
	{
		deque<TreeNode*> q;
		q.push_back(root);
		while (!q.empty())
		{
			depth += 1;
			for (int i = q.size(); i > 0; i--)
			{
				TreeNode* node = q.front();
				q.pop_front();
				if (node->left)
					q.push_back(node->left);
				if (node->right)
					q.push_back(node->right);
				if (!node->left && !node->right)
				{
					first_leaf = true;
					break;
				}
			}
			if (first_leaf)
				break;
		}
	}
	return depth;
}
int main()
{

	return 0;
}
