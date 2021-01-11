#include <iostream>
#include <vector>
using namespace std;


//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode * addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* l3 = new ListNode(0);
		ListNode* s = l3;
		int a,b,c=0;
		while (l1 != NULL || l2 != NULL) {
			if (l1 != NULL)
			{
				a = l1->val;
				l1 = l1->next;
			}
			else a = 0;
			if (l2 != NULL) 
			{
				b = l2->val;
				l2 = l2->next;
			}
			else b = 0;
			s->next = new ListNode((a + b + c) % 10);
			c = (a + b + c) / 10;
			s = s->next;
		}
		if (c != 0)s->next = new ListNode(c);
		return l3->next;
	}
};

int main() {
	Solution s;
	ListNode* l1 = new ListNode(2);
	l1->next = new ListNode(4);
	l1->next->next = new ListNode(3);
	ListNode* l2 = new ListNode(5);
	l2->next = new ListNode(6);
	l2->next->next = new ListNode(4);
	ListNode* l3 = s.addTwoNumbers(l1, l2);
	while (l3 != NULL) {
		cout << l3->val << "->";
		l3 = l3->next;
	}
	return 0;
}