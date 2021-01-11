#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <queue>
using namespace std;

//Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	struct cmp
	{
		bool operator()(ListNode* a, ListNode*b) {
			return a->val > b->val;
		}
	};
	ListNode * mergeKLists(vector<ListNode*>& lists) {
		priority_queue<ListNode*, vector<ListNode*>, cmp> heap;
		ListNode* head = new ListNode(-1);
		ListNode* cur = head;
		for (int i = 0; i < lists.size(); i++)
			if(lists[i])
				heap.push(lists[i]);
		while (!heap.empty()) {
			cur->next = heap.top();
			heap.pop();
			cur = cur->next;
			if (cur->next != NULL)heap.push(cur->next);
		}
		return head->next;
	}
};
int main() {
	Solution s;
	return 0;
}