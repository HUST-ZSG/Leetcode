#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int r = 0;
		int i = 0;
		int sign = 1;
		while (str[i] == ' ')i++;
		if (str[i] == '+')i++;
		else if (str[i] == '-') {
			i++;
			sign = -1;
		}
		for (; i < str.size(); i++) {
			int temp = str[i] - '0';
			if (temp >= 0 && temp <= 9) {
				temp = temp * sign;
				if (r > INT_MAX / 10 || (r == INT_MAX / 10 && temp > 7)) return INT_MAX;
				if (r < INT_MIN / 10 || (r == INT_MIN / 10 && temp < -8)) return INT_MIN;
				r = r * 10 + temp;
			}
			else break;
		}
		return r;
	}
};
int main() {
	Solution s;
	cout << s.myAtoi("-91283472332") << endl;
	return 0;
}