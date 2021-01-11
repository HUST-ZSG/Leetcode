#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		int len = nums.size();
		vector<vector<int>> ans;	//存储当前解
		vector<int> v;	//存储当前已经排列过的数字
		vector<int> flag(len, 0);	//标记数组
		backtracking(nums, v, flag, ans, len);
		return ans;
	}

	void backtracking(vector<int>& nums, vector<int>& v, vector<int>& flag, vector<vector<int> >& ans, int n) {
		if (n == 0) {
			ans.push_back(v);
			return;
		}
		for (int i = 0; i < nums.size(); ++i) {
			if (!flag[i]) {
				flag[i] = 1;
				v.push_back(nums[i]);
				backtracking(nums, v, flag, ans, n - 1);
				v.pop_back();
				flag[i] = 0;
			}
		}
		return;
	}
};

int main()
{
	vector<int> v = { 10,1,2 };
	Solution s;
	s.permute(v);
	return 0;
}


