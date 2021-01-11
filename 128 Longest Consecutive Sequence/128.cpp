#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		/*
			C++11标准新增的 Unordered_set 
			以散列代表set 内部的红黑树(一种自平衡二叉查找树)实现，处理只去重不排序的需求
		*/
		unordered_set<int> st;
		for (int num : nums) {
			st.insert(num);
		}
		int maxlen = 0;
		for (int num : nums) {   //for(auto num : nums) 简化了遍历
			if (st.find(num - 1) == st.end()) {  //对连续序列的第一个数开始寻找最长序列
				int temp = num; 
				int len = 1;
				while (st.find(temp + 1) != st.end()) {
					len++;
					temp++;
				}
				maxlen = max(maxlen, len);
			}
		}
		return maxlen;
	}
};
int main() {
	Solution s;
	vector<vector<int> > v = { { 1, 3, 5, 7 },{ 10, 11, 16, 20 },{ 23, 30, 34, 50 } };
	return 0;
}