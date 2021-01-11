#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)return s;
		string str = "";
		string * ss = new string[numRows];
		for (int i = 0; i < numRows; i++) {
			ss[i] = "";
		}
		for (int i = 0; i < s.size(); i++) {
			for (int j = 0; j < numRows; j++) {
				if (i % (2 * numRows - 2) == j || i % (2 * numRows - 2) == (2 * numRows - 2 - j)) {
					ss[j] += s[i];
					break;
				}
			}
		}
		for (int i = 0; i < numRows; i++)
			str += ss[i];
		return str;
	}
};
int main() {
	Solution s;
	string str = "LEETCODEISHIRING";
	cout << s.convert(str,4) << endl;
	return 0;
}