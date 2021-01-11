#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		vector<vector<int> > ans;
		vector<int> cur;
		sort(candidates.begin(), candidates.end());
		backtracking(ans, candidates, cur, target, 0);
		return ans;
	}

	void backtracking(vector<vector<int> >& ans, vector<int>& candidates, vector<int>& cur, int target, int pos) {
		if (pos == candidates.size())
			return;
		cur.push_back(candidates[pos]);
		if (target - candidates[pos] == 0)
			ans.push_back(cur);
		else if (target > candidates[pos])
			backtracking(ans, candidates, cur, target - candidates[pos], pos + 1);
		cur.pop_back();
		while (pos + 1 < candidates.size() && candidates[pos + 1] == candidates[pos])	//去重
			pos++;
		backtracking(ans, candidates, cur, target, pos + 1);
		return;
	}
};

int main() {
	vector<int> v = { 10,1,2,7,6,1,5 };
	Solution s;
	s.combinationSum2(v, 8);
	return 0;
}