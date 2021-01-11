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
//迭代
class Solution {
public:
	ListNode * reverseKGroup(ListNode* head, int k) {
		stack<ListNode*> s;
		ListNode* temp = head;
		int cnt = 0;
		while (head != NULL && cnt < k) {
			s.push(head);
			cnt++;
			head = head->next;
		}
		if (s.size() < k)return temp;
		else {
			temp->next = reverseKGroup(head, k);
			head = s.top();
			s.pop();
			temp = head;
			while (!s.empty()) {
				temp->next = s.top();
				s.pop();
				temp = temp->next;
			}
		}
		return head;
	}
};
int main() {
	Solution s;
	ListNode* v1 = new ListNode(1);
	ListNode* v2 = new ListNode(2);
	ListNode* v3 = new ListNode(3);
	ListNode* v4 = new ListNode(4);
	ListNode* v5 = new ListNode(5);
	v1->next = v2;
	v2->next = v3;
	v3->next = v4;
	v4->next = v5;
	s.reverseKGroup(v1, 2);
	return 0;
}