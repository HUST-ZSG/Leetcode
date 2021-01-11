#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <stack>
using namespace std;


// Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
	ListNode * mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* head = new ListNode(0);
		ListNode* temp = head;
		while (l1 != NULL && l2 != NULL) {
			if (l1->val < l2->val) {
				temp->next = l1;
				temp = l1;
				l1 = l1->next;
			}
			else {
				temp->next = l2;
				temp = l2;
				l2 = l2->next;
			}
		}
		if (l1)temp->next = l1;
		else temp->next = l2;
		return head->next;
	}
};
int main() {
	Solution s;
	ListNode* v1 = new ListNode(1);
	ListNode* v2 = new ListNode(5);
	ListNode* v3 = new ListNode(3);
	ListNode* v4 = new ListNode(4);
	ListNode* v5 = new ListNode(5);
	v1->next = v2;

	v3->next = v4;
	v4->next = v5;
	s.mergeTwoLists(v1, v3);
	return 0;
}