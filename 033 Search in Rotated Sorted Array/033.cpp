﻿#include <iostream>
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
	int search(vector<int>& nums, int target) {
		int l = 0;
		int r = nums.size() - 1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (target == nums[mid])return mid;
			if (nums[mid] >= nums[l]) {
				if (nums[mid] >= target) {
					if(target>=nums[l])r = mid - 1;
					else l = mid + 1;
				}
				else l = mid + 1;
			}
			else { 
				if (nums[mid] < target) {
					if (target > nums[r])r = mid - 1;
					else l = mid + 1;
				}
				else r = mid - 1;
			}
		}
		return -1;
	}
};
int main() {
	Solution s;
	vector<int> v({ 3,1});
	cout << s.search(v,1) << endl;
	return 0;
}