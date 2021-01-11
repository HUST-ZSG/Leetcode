#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		int r = 0;
		while (x != 0) {
			if (r > INT_MAX/10 || (r == INT_MAX / 10 && x % 10 > 7) || r < INT_MIN / 10 || (r == INT_MIN / 10 && x % 10 < -8)) return 0;
			r *= 10;
			r += x % 10;
			x = x / 10;
		}
		return r;
	}
};
int main() {
	Solution s;
	string str = "LEETCODEISHIRING";
	cout << s.reverse(1534236469) << endl;
	return 0;
}