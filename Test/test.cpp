#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
class Solution {
public:
	int countNumbersWithUniqueDigits(int n) {
		int dp[10] = {1};
		int num = 9;
		for (int i = 1; i <= n; i++) {
			dp[i] = num + dp[i-1];
			num *= (10 - i);
		}
		return dp[n];
	}
};
*/

class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int sum = 0;
		int ans = nums[0];
		for (int i = 0; i < nums.size(); i++) {
			sum = max(nums[i], sum + nums[i]);
			ans = max(ans, sum);
		}
		return ans;
	}
};
int main() {
	//Solution s;
	//vector<int> v = { 1,2,3 };
	//cout << s.maxSubArray(v) << endl;
	////cout << s.countNumbersWithUniqueDigits(3) << endl;
	int a[10] = { -1 };
	memset(a, 0x3f3f, sizeof(a));
	for (int i = 0; i < 10; ++i)
		cout << a[i] << endl;
	return 0;

}
