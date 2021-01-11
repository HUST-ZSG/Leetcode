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
	TreeNode * DFS(vector<int>& inorder, vector<int>& postorder, int inL, int inR,int postL, int postR) {
		if (inL > inR) return NULL;
		else {
			int temp = postorder[postR];
			int k;
			for (k = inL; k < inR; k++)
				if (inorder[k] == temp)break;
			int numLeft = k - inL;   //左子树的结点个数
			TreeNode* node = new TreeNode(temp);

			//左子树的中序区间[inL,k-1] 后序区间[postL,postL+numLeft-1];
			node->left = DFS(inorder, postorder, inL, k - 1, postL, postL + numLeft - 1);

			//右子树的中序区间[k+1,inR] 后序区间[postL+numLeft,postR-1]
			node->right = DFS(inorder, postorder, k + 1, inR, postL + numLeft, postR - 1);
			return node;
		}
	}

	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		if (inorder.size() == 0)return NULL;
		return DFS(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size()-1);
	}
};

int main() {
	Solution s;
	vector<vector<int> > v = { { 1, 3, 5, 7 },{ 10, 11, 16, 20 },{ 23, 30, 34, 50 } };
	return 0;
}