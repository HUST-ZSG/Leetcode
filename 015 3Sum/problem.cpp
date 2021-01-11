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
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> r;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if (i != 0&&nums[i] == nums[i-1])continue;
			if (nums[i] > 0)break;
			int j, k;
			j = i + 1;
			k = nums.size() - 1;
			while (j < k) {
				if (nums[j] + nums[k] < -nums[i])j++;
				else if (nums[j] + nums[k] > -nums[i])k--;
				else {
					r.push_back({ nums[i],nums[j],nums[k] });
					while (j < k&&nums[j + 1] == nums[j])j++;
					while (j < k&&nums[k - 1] == nums[k])k--;
					j++;
					k--;
				}
			}
		}

		return r;
	}
};
int main() {
	Solution s;
	vector<int> v({ -1,0,1,2,-1,-4});
	//v.push_back(2);
	//v.push_back(-5);
	//s.threeSum(v);
	cout << s.threeSum(v).size() << endl;
	return 0;
}