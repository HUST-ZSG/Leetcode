#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		if (p.size() == 0) {
			if (s.size() == 0)return true;
			return false;
		}

		if (p.size() == 1 || p[1] != '*') {
			if (s.size() == 0 || (p[0] != '.'&&s[0] != p[0]))
				return false;
			else return isMatch(s.substr(1), p.substr(1));
		}

		while (s.size() != 0 && (s[0] == p[0] || p[0] == '.')) {
			if (isMatch(s, p.substr(2)))return true;
			s = s.substr(1);
		}
		return isMatch(s, p.substr(2));
	}
	bool isMatch_2(string s, string p)
	{
		int n = s.size();
		int m = p.size();
		bool dp[1010][1010];
		memset(dp, false, sizeof(dp));
		dp[0][0] = true;
		for (int i = 0; i <= n; ++i)
		{
			for (int j = 1; j <= m; ++j)
			{
				if (j > 1 && p[j - 1] == '*')
					dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
				else
					dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
			}
		}
		return dp[n][m];
	}
};
int main() {
	Solution s;
	cout << s.isMatch("aaa", "a.a") << endl;
	return 0;
}