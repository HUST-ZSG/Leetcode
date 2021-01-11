#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
	int maxArea(vector<int>& height) {
		int r = height.size() - 1, l = 0, maxarea = 0;
		while (l < r) {
			maxarea = max(maxarea, min(height[l], height[r])*(r - l));
			if (height[l] < height[r])l++;
			else r--;
		}
		return maxarea;
	}
};
int main() {
	Solution s;
	vector<int> v(5,1);

	cout << s.maxArea(v) << endl;
	return 0;
}