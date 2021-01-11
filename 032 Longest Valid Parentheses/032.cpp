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
	int longestValidParentheses(string s) {
		int max = 0;
		vector<int> v;
		stack<int> st;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(')st.push(i);
			else if (s[i] == ')' && !st.empty()) {
				int temp = st.top();
				v.push_back(i);
				v.push_back(temp);
				st.pop();
			}
		}
		sort(v.begin(), v.end());
		int cnt = 1;
		for (int i = 1; i < v.size(); i++) {
			if (v[i] == v[i - 1] + 1) {
				cnt++;
				if (cnt > max)max = cnt;
			}
			else cnt = 1;
		}
		return max;
	}
};
int main() {
	Solution s;
	vector<int> v({ 1,2,3 });
	cout << s.longestValidParentheses(")()())") << endl;
	return 0;
}