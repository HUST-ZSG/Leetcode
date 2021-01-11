#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	vector<int> v;
	vector<vector<int>> ans;
	void DFS(TreeNode* node, int sum, int target) {
		if (node == NULL)return;
		v.push_back(node->val);
		if (node->left == NULL && node->right == NULL && sum + node->val == target) {
			ans.push_back(v);
			v.pop_back();
			return;
		}
		DFS(node->left, sum + node->val, target);
		DFS(node->right, sum + node->val, target);
		v.pop_back();
	}

	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		DFS(root, 0, sum);
		return ans;
	}
};

int main() {
	Solution s;
	vector<vector<int> > v = { { 1, 3, 5, 7 },{ 10, 11, 16, 20 },{ 23, 30, 34, 50 } };
	return 0;
}