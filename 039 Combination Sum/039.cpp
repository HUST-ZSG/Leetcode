#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

class Solution {
public:
	vector<vector<int> > ans;
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<int> cur;
		sort(candidates.begin(), candidates.end());
		backtracking(cur, candidates, 0, target);
		return ans;
	}

	void backtracking(vector<int>& cur, vector<int>& candidates, int pos, int target) {
		if (pos == candidates.size())
			return;
		cur.push_back(candidates[pos]);
		if (target - candidates[pos] == 0)
		{
			ans.push_back(cur);
			cur.pop_back();
			return;
		}
		if (candidates[pos] > target)
		{
			cur.pop_back();
			return;
		}
		backtracking(cur, candidates, pos, target - candidates[pos]);
		cur.pop_back();
		backtracking(cur, candidates, pos + 1, target);
		return;
	}
};

int main() {
	
	return 0;
}