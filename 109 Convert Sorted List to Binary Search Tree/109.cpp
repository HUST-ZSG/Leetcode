#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;


 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };


//Definition for a binary tree node.
 struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	TreeNode * creatNode(vector<ListNode* >& v, int left, int right) {
		if (left > right)return NULL;
		int mid = (left + right) / 2;
		TreeNode* node = new TreeNode(v[mid]->val);
		node->left = creatNode(v, left, mid - 1);
		node->right = creatNode(v, mid + 1, right);
		return node;
	}

	TreeNode * sortedListToBST(ListNode* head) {
		if (head == NULL)return NULL;
		vector<ListNode* > v;
		while (head != NULL) {
			v.push_back(head);
			head = head->next;
		}
		int left = 0;
		int right = v.size() - 1;
		return creatNode(v, left, right);
	}
};

int main() {
	Solution s;
	vector<vector<int> > v = { { 1, 3, 5, 7 },{ 10, 11, 16, 20 },{ 23, 30, 34, 50 } };
	return 0;
}