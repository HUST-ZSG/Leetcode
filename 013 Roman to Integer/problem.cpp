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
	int romanToInt(string s) {
		map<char, int> m;
		m['I'] = 1;
		m['V'] = 5;
		m['X'] = 10;
		m['L'] = 50;
		m['C'] = 100;
		m['D'] = 500;
		m['M'] = 1000;
		int pre = 0;
		int cur = 0;
		int sum = 0;
		for (int i = 0; i < s.size(); i++) {
			cur = m[s[i]];
			if (cur <= pre) sum += cur;
			else sum += cur - 2 * pre;
			pre = cur;
		}
		return sum;
	}
};
int main() {
	Solution s;

	cout << s.romanToInt("IV") << endl;
	return 0;
}