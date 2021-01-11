#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		if (root == NULL) {
			return res;
		}
		queue<TreeNode*> q;
		q.push(root);
		while (!q.empty()) {
			vector<int> v;
			int len = q.size();
			for (int i = 0; i < len; i++) {
				TreeNode* t = q.front();
				q.pop();
				if (t->left != NULL)q.push(t->left);
				if (t->right != NULL)q.push(t->right);
				v.push_back(t->val);
			}
			res.push_back(v);
		}
		return res;
	}
};
int main() {
	return 0;
}