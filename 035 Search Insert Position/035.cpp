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
	int searchInsert(vector<int>& nums, int target) {
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] >= target)return i;
		}
		return nums.size();
	}
};
int main() {
	Solution s;
	vector<int> v({ 3,1 });
	cout << s.searchInsert(v, 1) << endl;
	return 0;
}