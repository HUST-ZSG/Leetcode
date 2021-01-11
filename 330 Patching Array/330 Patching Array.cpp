#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	int minPatches(vector<int>& nums, int n) {
		int ans = 0;
		int x = 1;
		int index = 0;
		while (x <= n) {
			if (index < nums.size() && nums[index] <= x) {
				x += nums[index++];
			}
			else {
				x *= 2;
				ans++;
			}
		}
		return ans;
	}
};

int main()
{

	return 0;
}

