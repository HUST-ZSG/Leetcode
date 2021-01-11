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
	bool isValid(string s) {
		stack<char> st;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '{' || s[i] == '[' || s[i] == '(')st.push(s[i]);
			else {
				if (st.empty())return false;
				char c = st.top();
				st.pop();
				if ((s[i] == '}'&&c != '{') || (s[i] == ']'&&c != '[') || (s[i] == ')'&&c != '('))return false;
			}
		}
		if (!st.empty())return false;
		return true;
	}
};
int main() {
	Solution s;
	cout << s.isValid("()") << endl;
	return 0;
}