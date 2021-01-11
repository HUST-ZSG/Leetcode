#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		int len = 0;
		if (strs.size() == 0 || strs[0].size() == 0)return "";
		for (int i = 0; i < strs[0].size(); i++) {
			char c = strs[0][i];
			for (int j = 1; j < strs.size(); j++) {
				if (i == strs[j].size() || c != strs[j][i])return strs[0].substr(0, len);
			}
			len++;
		}
		return strs[0].substr(0,len);
	}
};
int main() {
	Solution s;
	vector<string> v;
	v.push_back("ssad");
	v.push_back("ssads");
	cout << s.longestCommonPrefix(v) << endl;
	return 0;
}