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
	int removeElement(vector<int>& nums, int val) {
		int cnt = nums.size();
		for (vector<int>::iterator it = nums.begin(); it != nums.end();) {
			if (*it == val) {
				it = nums.erase(it);
				cnt--;
			}
			else it++;
		}
		return cnt;
	}
};
int main() {
	Solution s;
	vector<int> nums({ 1,1 });
	return 0;
}