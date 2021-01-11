#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
using namespace std;

class Solution {
public:
	void nextPermutation(vector<int>& nums) {
		int end;
		int start = -1;
		for (int i = nums.size() - 1; i > 0; i--) {
			if (nums[i] > nums[i-1]) {
				start = i - 1;
				break;
			}
		}
		if (start == -1)sort(nums.begin(), nums.end());
		else {
			for (int i = nums.size() - 1; i > start; i--) {
				if (nums[i] > nums[start]) {
					end = i;
					break;
				}
			}
			swap(nums[start], nums[end]);
			int i = start + 1;
			int j = nums.size() - 1;
			while (i < j) {
				swap(nums[i], nums[j]);
				i++;
				j--;
			}
		}
	}
	
	void swap(int& a, int &b) {
		int temp = a;
		a = b;
		b = temp;
	}
};
int main() {
	Solution s;
	vector<int> v({1,2,3 });
	s.nextPermutation(v);
	return 0;
}