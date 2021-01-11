#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;


/*
	方法一 中心扩展方法，通过对回文中心的枚举，计算最大长度
*/

/*
class Solution {
public:
	string longestPalindrome(string s) {
		int start = 0;
		int len = 0;
		for (int i = 0; i < s.size(); i++) { // 回文数为奇数
			int temp = 1;
			for (int j = 1; i - j >= 0 && i + j < s.size(); j++) {
				if (s[i - j] == s[i + j])
					temp += 2;
				else break;
			}
			if (temp > len) {
				len = temp;
				start = i - len/2;
			}
		}
		for (int i = 0; i < s.size(); i++) { //回文数为偶数
			int temp = 0;
			for (int j = 0; i - j >= 0 && i + j + 1 < s.size(); j++) {
				if (s[i - j] == s[i + j + 1])
					temp += 2;
				else break;
			}
			if (temp > len) {
				len = temp;
				start = i - len/2 + 1;
			}
		}
		return s.substr(start, len);
	}
};
*/

/*
	方法二 动态规划
*/
const int maxn = 1010;
int dp[maxn][maxn];
class Solution {
public:
	string longestPalindrome(string s) {
		int len = s.size();
		int ans = 1; //记录最长回文长度
		int start = 0; //记录起始位置
		memset(dp, 0, sizeof(dp));

		//边界
		for (int i = 0; i < maxn; i++) {
			dp[i][i] = 1;
			if (i < len - 1) {
				if (s[i] == s[i + 1]) {
					dp[i][i + 1] = 1;
					ans = 2;
					start = i;
				}
			}
		}

		//状态转移方程
		for (int L = 3; L <= len; L++) {
			for (int i = 0; i + L - 1 < len; i++) {
				int j = i + L - 1; //字串的右端点
				if (s[i] == s[j] && dp[i + 1][j - 1] == 1) {
					dp[i][j] = 1;
					ans = L;
					start = i;
				}
			}
		}

		return s.substr(start, ans);
	}
};

int main() {
	Solution s;
	string str = "babad";
	cout << s.longestPalindrome(str) << endl;
	return 0;
}