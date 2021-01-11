#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <stack>
using namespace std;


// Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
/*
	版本一 递归
	ltag、utag分别表示是否存在左右边界
*/
/*
class Solution {
public:
	bool helper(TreeNode* p, int low, int ltag, int up, int utag) {
		if (p == NULL)return true;
		if ((utag != 0 && p->val >= up) || (ltag != 0 && p->val <= low))return false;
		if (!helper(p->left, low, ltag, p->val, 1))return false;
		if (!helper(p->right, p->val, 1, up, utag))return false;
		return true;
	}
	bool isValidBST(TreeNode* root) {
		return helper(root, 0, 0, 0, 0);
	}
};
*/

/*
	版本二 中序遍历
*/
class Solution {
public:
	bool isValidBST(TreeNode* root) {
		stack<TreeNode*> s;
		long long num = INT64_MIN;
		while (root != NULL || !s.empty()) {
			while (root) {
				s.push(root);
				root = root->left;
			}
			root = s.top();
			s.pop();
			if (root->val <= num)return false;
			num = root->val;
			root = root->right;
		}
		return true;
	}
};
int main() {
	Solution s;
	TreeNode* root;
	root = new TreeNode(2);
	root->left = new TreeNode(1);
	root->right = new TreeNode(3);
	cout << s.isValidBST(root) << endl;
	return 0;
}