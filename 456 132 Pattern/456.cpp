#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
	bool find132pattern(vector<int>& nums) {
		stack<int> s;
		int len = nums.size();
		vector<int> min_j(len, 0);
		int ml = nums[0];
		for (int i = 0; i < len; ++i)
		{
			if (nums[i] < ml)
				ml = nums[i];
			min_j[i] = ml;
		}

		for (int i = len - 1; i >= 0; --i) {
			if (nums[i] > min_j[i]) {
				
				while (!s.empty() && s.top() <= min_j[i])s.pop();
				if (!s.empty() && nums[i] > s.top())return true;
				if (s.empty() || nums[i] < s.top())
					s.push(nums[i]);
			}
		}
		return false;
	}
};

int main() {

	return 0;
}