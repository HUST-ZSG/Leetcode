#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <set>
using namespace std;

class Solution {
public:
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
		vector<vector<int>> r;
		sort(nums.begin(), nums.end());
		for (int m = 0; m < nums.size(); m++) {
			if (m != 0 && nums[m] == nums[m - 1])continue;
			int temp = target - nums[m];
			for (int i = m + 1; i < nums.size(); i++) {
				if (i != m + 1 && nums[i] == nums[i - 1])continue;
				int j, k;
				j = i + 1;
				k = nums.size() - 1;
				while (j < k) {
					if (nums[j] + nums[k] < temp-nums[i])j++;
					else if (nums[j] + nums[k] > temp - nums[i])k--;
					else {
						r.push_back({ nums[m],nums[i],nums[j],nums[k] });
						while (j < k&&nums[j + 1] == nums[j])j++;
						while (j < k&&nums[k - 1] == nums[k])k--;
						j++;
						k--;
					}
				}
			}
		}

		return r;
	}
};
int main() {
	Solution s;
	vector<int> v({ 1, 0, -1, 0, -2, 2 });
	//v.push_back(2);
	//v.push_back(-5);
	//s.threeSum(v);
	cout << s.fourSum(v,0).size() << endl;
	return 0;
}