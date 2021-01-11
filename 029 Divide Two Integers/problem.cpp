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
	int divide(int dividend, int divisor) {
		long long r = 0;
		int s = -1;
		if (dividend == INT_MIN && divisor == -1)return INT_MAX;
		if ((dividend >= 0 && divisor > 0) || (dividend <= 0 && divisor < 0))s = 1;
		long long x = dividend;
		long long y = divisor;
		x = (x > 0) ? x : -x;
		y = (y > 0) ? y : -y;
		while (x >= y) {
			long long temp = y;
			int mid = 1;
			while (x >= (temp << 1)) {
				mid <<= 1;
				temp <<= 1;
			}
			x -= temp;
			r += mid;
		}
		return s > 0 ? r : -r;
	}
};
int main() {
	Solution s;
	cout << s.divide(10,3) << endl;
	return 0;
}