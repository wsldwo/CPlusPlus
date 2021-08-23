#include <iostream>
#include <vector>
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
void calLeft(int&sum, int type, TreeNode* root)
{
	if (root)
	{
		if (type == -1 && !root->left && !root->right)// -1 left 0 middle 1 right
			sum += root->val;
		if (root->left)
			calLeft(sum, -1, root->left);
		if (root->right)
			calLeft(sum, 1, root->right);
	}
}
int sumOfLeftLeaves(TreeNode* root)
{
	int sum = 0;
	calLeft(sum, 0, root);
	return sum;
}
int main()
{
	return 0;
}
