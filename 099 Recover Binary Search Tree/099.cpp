#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <stack>
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
	//中序遍历非递归
	void recoverTree(TreeNode* root) {
		TreeNode* pre = nullptr;
		TreeNode* n1 = nullptr, *n2 = nullptr;
		stack<TreeNode*> st;
		while (!st.empty() || root) {
			while (root) {
				st.push(root);
				root = root->left;
			}
			root = st.top();
			st.pop();
			if (pre && pre->val > root->val) { //注意:有可能这是最后两个结点,不要忽略
				if (n1)n2 = root;
				else {
					n1 = pre;
					n2 = root;
				}
			}
			pre = root;
			root = root->right;
		}
		swap(n1->val, n2->val);
	}
};

int main() {
	Solution s;
	TreeNode* n1 = new TreeNode(3);
	TreeNode* n2 = new TreeNode(1);
	TreeNode* n3 = new TreeNode(4);
	TreeNode* n4 = new TreeNode(2);
	n1->left = n2;
	n1->right = n3;
	n3->right = n4;
	s.recoverTree(n1);
	return 0;
}