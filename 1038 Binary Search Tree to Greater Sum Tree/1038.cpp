#include <iostream>
#include <vector>
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
	int sum = 0;
	TreeNode*  bstToGst(TreeNode* root) {
		if (root == NULL)return NULL;
		bstToGst(root->right);
		sum += root->val;
		root->val = sum;
		bstToGst(root->left);
		return root;
	}
};
int main() {
	Solution s;
	return 0;
}