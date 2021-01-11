#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> v;
		string s;
		string str[8] = { "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };
		if (digits.size() == 0)return v;
		BFSCombinations(v, digits, 0, str, s);
		return v;
	}
	void BFSCombinations(vector<string>& v, string digits, int site, string* s, string str) {
		if (site == digits.size()) {
			v.push_back(str);
			return;
		}
		int c = digits[site] - '2';
		for (int i = 0; i < s[c].size(); i++) {
			str += s[c][i];
			BFSCombinations(v, digits, site + 1, s, str);
			str = str.substr(0, str.size() - 1);
		}
	}
};
int main() {
	Solution s;
	cout << s.letterCombinations("23").size() << endl;
	return 0;
}