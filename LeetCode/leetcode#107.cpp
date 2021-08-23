#include <iostream>
#include<vector>
#include<deque>
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
vector<vector<int>> levelOrderBottom(TreeNode* root)
{
	vector<vector<int>> v1, v2;
	deque<TreeNode*> q;
	if (root)
	{
		q.push_back(root);
		while (!q.empty())
		{
			vector<int> v;
			for (int i = q.size(); i > 0; i--)
			{
				TreeNode* node = q.front();
				q.pop_front();
				v.push_back(node->val);
				if (node->left)
					q.push_back(node->left);
				if (node->right)
					q.push_back(node->right);
			}
			v1.push_back(v);
		}
	}
	for (int i = v1.size() - 1; i >= 0; i--)
		v2.push_back(v1[i]);
	return v2;
}
int main()
{
	return 0;
}
