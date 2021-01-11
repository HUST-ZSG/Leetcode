#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
	double myPow(double x, int n) {
		long long N = n;
		double ans = 1;
		if (N < 0) {
			N = -N;
			x = 1 / x;
		}
		while (N) {
			if (N & 1) ans *= x;
			x *= x;
			N >>= 1;
		}
		return ans;
	}
};
int main() {
	Solution s;
	cout << s.myPow(1.2,-5) << endl;
	return 0;
}