#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
	string multiply(string num1, string num2) {
		string ans(230, '0');
		int len1 = num1.size();
		int len2 = num2.size();
		for (int i = len1 - 1; i >= 0; --i)
			for (int j = len2 - 1; j >= 0; --j) {
				int c1 = num1[i] - '0';
				int c2 = num2[j] - '0';
				int cur = c1 * c2;
				combine(ans, cur, len1 + len2 - i - j - 2);
			}
		int len = ans.size();
		for (int i = 0; i < len / 2; ++i)
			swap(ans[i], ans[len - i - 1]);
		int p;
		for (p = 0; p < len - 1; ++p)
			if (ans[p] != '0')
				break;
		return ans.substr(p);
	}
	void combine(string& ans, int cur, int pos) {
		int c1, c2;
		int c = 0;
		int i = 0 + pos;
		while(cur != 0 || c != 0) {
			c1 = ans[i] - '0';
			c2 = cur % 10;
			ans[i] = (c1 + c2 + c) % 10 + '0';
			c = (c1 + c2 + c) / 10;
			cur /= 10;
			++i;
		}
	}
};

int main() {
	Solution s;
	cout << s.multiply("999", "999") << endl;
	return 0;
}