#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <set>
using namespace std;

//Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode * removeNthFromEnd(ListNode* head, int n) {
		ListNode* d = new ListNode(0);
		d->next = head;
		ListNode* first = d,* second = d;
		while (n) {
			if (first == NULL)return head;
			first = first->next;
			n--;
		}
		while (first->next != NULL) {
			first = first->next;
			second = second->next;
		}
		ListNode* temp = second->next;
		second->next = temp ->next;
		delete temp;
		return d->next;
	}
};
int main() {
	Solution s;
	ListNode* v1 = new ListNode(1);
	ListNode* v2 = new ListNode(1);
	ListNode* v3 = new ListNode(1);
	ListNode* v4 = new ListNode(1);
	ListNode* v5 = new ListNode(1);
	v1->next = v2;
	v2->next = v3;
	v3->next = v4;
	v4->next = v5;
	s.removeNthFromEnd(v1, 2);
	return 0;
}