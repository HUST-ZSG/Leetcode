#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;



class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int res = 0;// 最长字串返回值
		int m[256] = {0};
		int left = 0;
		for (int i = 0; i < s.size(); i++) {
			if (m[s[i]]==0 || m[s[i]] < left)
				res = max(res, i - left + 1);
			else
				left = m[s[i]];
			m[s[i]] = i+1;
		}
		return res;
	}
};

int main() {
	Solution s;
	string str = " ";
	//cin >> str;
	cout << s.lengthOfLongestSubstring(str) << endl;
	return 0;
}