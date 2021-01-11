#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;


// Definition for a Node.
class Node {
public:
	int val;
	vector<Node*> neighbors;

	Node() {}

	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};

class Solution {
public:
	Node * cloneGraph(Node* node) {
		map<Node*, Node*> map;
		vector<Node*> v;
		Node* head = new Node(node->val, v);
		map[node] = head;
		queue<Node*> q;
		q.push(node);
		while (!q.empty()) {
			node = q.front();
			Node* clone = map[node];
			q.pop();
			for (int i = 0; i < node->neighbors.size(); i++) {
				if (map.find(node->neighbors[i]) == map.end()) {
					map[node->neighbors[i]] = new Node(node->neighbors[i]->val,v);
					q.push(node->neighbors[i]);
				}
				clone->neighbors.push_back(map[node->neighbors[i]]);
			}
		}
		return head;
	}
};

int main() {
	Solution s;
	vector<vector<int> > v = { { 1, 3, 5, 7 },{ 10, 11, 16, 20 },{ 23, 30, 34, 50 } };
	return 0;
}