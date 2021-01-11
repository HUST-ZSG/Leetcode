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
	TreeNode * DFS(vector<int>& preorder, vector<int>& inorder, int pl, int il, int len) {
		if (len == 0) return NULL;
		else {
			int temp = preorder[pl];
			int k;
			for (k = il; k < il + len; k++)
				if (inorder[k] == temp)break;
			int numLeft = k - il;   //左子树的结点个数
			TreeNode* node = new TreeNode(temp);
			//左子树的先序区间[preL+1,preL+numLeft] 中序区间[inL,inL+numLeft-1]或[inL, numLeft-1]
			node->left = DFS(preorder, inorder, pl + 1, il, numLeft);

			//右子树的先序区间[preL+1+numLeft,preR] 中序区间[inL+numLeft+1,inR]或[numLeft+1,inR]
			node->right = DFS(preorder, inorder, pl + 1 + numLeft, il + numLeft + 1, len - numLeft - 1);
			return node;
		}
	}

	TreeNode * buildTree(vector<int>& preorder, vector<int>& inorder) {
		if (preorder.size() == 0)return NULL;
		return DFS(preorder, inorder, 0, 0, preorder.size());
	}
};

int main() {
	Solution s;
	vector<vector<int> > v = { { 1, 3, 5, 7 },{ 10, 11, 16, 20 },{ 23, 30, 34, 50 } };
	return 0;
}