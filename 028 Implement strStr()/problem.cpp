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
	int strStr(string haystack, string needle) {
		return haystack.find(needle);
	}
};
int main() {
	Solution s;
	cout << s.strStr("asdf", "daas") << endl;
	return 0;
}