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
	vector<int> searchRange(vector<int>& nums, int target) {
		vector<int> v({ -1,-1 });
		int l = searchIndex(nums, target, true);
		if (l == nums.size() || nums[l] != target)return v;
		int r = searchIndex(nums,target, false) - 1;
		v[0] = l;
		v[1] = r;
		return v;
	}

	int searchIndex(vector<int>& nums, int target, bool left) {
		int l = 0;
		int h = nums.size();
		int mid;
		while (l < h) {
			mid = (l + h) / 2;
			if (nums[mid] > target || (left&&nums[mid] == target)) h = mid;
			else l = mid+1;
		}
		return l;
	}
};
int main() {
	Solution s;
	vector<int> v({ 3,1 });
	cout << s.searchRange(v, 1)[0] << endl;
	return 0;
}