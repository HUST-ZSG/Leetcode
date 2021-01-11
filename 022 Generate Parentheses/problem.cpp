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

class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> v;
		backtrack(v,"",0,0,n);
		return v;
	}
	void backtrack(vector<string>& v, string str, int open, int close, int n) {
		if (str.size() == 2 * n) {
			v.push_back(str);
			return;
		}
		if (open < n)backtrack(v, str + "(", open + 1, close, n);
		if (close < open)backtrack(v, str + ")", open, close + 1, n);
	}
};
int main() {
	Solution s;
	cout << s.generateParenthesis(3).size() << endl;
	return 0;
}