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
	int threeSumClosest(vector<int>& nums, int target) {
		int sum=nums[0]+nums[1]+nums[2];
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if (i != 0 && nums[i] == nums[i - 1])continue;
			int j, k;
			j = i + 1;
			k = nums.size() - 1;
			while (j < k) {
				if (abs(target - nums[i] - nums[j] - nums[k]) < abs(sum-target)) 
					sum = nums[i] + nums[j] + nums[k];
				if (target == nums[i] + nums[j] + nums[k])break;
				if (nums[j] + nums[k] < target-nums[i])j++;
				else if (nums[j] + nums[k] > target -nums[i])k--;
				
			}
		}
		return sum;
	}
};
int main() {
	Solution s;
	vector<int> v({ -1,0,1,2,-1,-4 });
	//v.push_back(2);
	//v.push_back(-5);
	//s.threeSum(v);
	int k = 1;
	cout << s.threeSumClosest(v,k) << endl;
	return 0;
}