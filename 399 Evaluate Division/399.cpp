#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <unordered_map>
#include <string>
#include <string.h>
using namespace std;

/*u
	给出方程式 A / B = k, 其中 A 和 B 均为代表字符串的变量，
	k 是一个浮点型数字。根据已知方程式求解问题，并返回计算结果。
	如果结果不存在，则返回 -1.0。
*/

struct Node {      //结点结构体
	double val;
	Node* parent;
	Node() :parent(this) {};
	Node(double v) :val(v), parent(this) {};
};

Node* find(Node* node) {  //寻找父节点
	while (node->parent != node)
		node = node->parent;
	return node;
}

void union_node(Node* n1, Node* n2, double val, unordered_map<string, Node*> &mp) { //合并操作
	Node* p1 = find(n1);
	Node* p2 = find(n2);
	if (p1 != p2) {    //将n1所在结点集合等比例放大
		double ratio = n2->val * val / n1->val; // 计算需要放大的倍数
		for (auto n : mp) {
			if (p1 == find(n.second))n.second->val *= ratio;
		}
		p1->parent = p2;
	}
}

class Solution {
public:
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		vector<double> ans;
		unordered_map<string, Node*> mp;
		for (int i = 0; i < equations.size(); i++) {  //构造并查集
			if (mp.find(equations[i][0]) == mp.end())mp[equations[i][0]] = new Node(values[i]);  
			if (mp.find(equations[i][1]) == mp.end())mp[equations[i][1]] = new Node(1.0);
			union_node(mp[equations[i][0]], mp[equations[i][1]], values[i], mp); 
		}

		for (int i = 0; i < queries.size(); i++) {  //求值
			if (mp.find(queries[i][0]) != mp.end() && mp.find(queries[i][1]) != mp.end()) {
				Node* n1 = mp[queries[i][0]];
				Node* n2 = mp[queries[i][1]];
				if (find(n1) == find(n2))ans.push_back(n1->val / n2->val);
				else ans.push_back(-1.0);
			}
			else ans.push_back(-1.0);
		}
		return ans;
	}
};

int main() {
	Solution s;
	vector<vector<string>> a = { {"a", "b"}, {"b", "c"} };
	vector<double> b = {2.0, 3.0};
	vector<vector<string>> c = {{"a", "c"}, {"b", "a"}, {"a", "e"}, {"a", "a"}, {"x", "x"}};
	s.calcEquation(a, b, c);
	return 0;
}