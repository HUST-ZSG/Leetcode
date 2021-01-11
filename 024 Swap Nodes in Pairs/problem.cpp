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
	ListNode * swapPairs(ListNode* head) {
		if (head==NULL || head->next==NULL)return head;
		ListNode* cur = head->next;
		head->next = cur->next;
		cur->next = head;
		head = cur;
		cur = head->next;
		while (cur->next && cur->next->next) {
			ListNode* temp = cur->next;
			cur->next = temp->next;
			temp->next = temp->next->next;
			cur->next->next = temp;
			cur = temp;
		}
		return head;
	}
};
int main() {
	Solution s;
	return 0;
}