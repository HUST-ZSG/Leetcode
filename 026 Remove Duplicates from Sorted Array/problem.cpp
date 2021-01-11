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
	int removeDuplicates(vector<int>& nums) {
		int cnt = nums.size();
		int temp;
		for (vector<int>::iterator it = nums.begin(); it != nums.end();) {
			if (it == nums.begin())temp = *it++;
			else {
				if (*it == temp) {
					it = nums.erase(it);
					cnt--;
				}
				else {
					temp = *it;
					it++;
				}
			}
		}
		return cnt;
	}
};
int main() {
	Solution s;
	vector<int> nums({ 1,1});
	s.removeDuplicates(nums);
	return 0;
}