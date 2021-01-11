#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
	bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
		int num = 0;
		vector<int> inDegree(numCourses, 0);
		vector<vector<int> > out(numCourses);
		queue<int> q;
		for (int i = 0; i < prerequisites.size(); i++) {
			inDegree[prerequisites[i][1]]++;
			out[prerequisites[i][0]].push_back(prerequisites[i][1]);
		}
		for (int i = 0; i < numCourses; i++) {
			if (inDegree[i] == 0) q.push(i);
		}

		while (!q.empty()) {
			int u = q.front();
			q.pop();
			for (int i = 0; i < out[u].size(); i++) {
				int v = out[u][i];
				inDegree[v]--;
				if (inDegree[v] == 0) {
					q.push(v);
				}
			}
			num++;
		}
		if (num == numCourses)return true;
		return false;
	}
};
int main() {
	Solution s;
	vector<vector<int> > v = { { 1, 3, 5, 7 },{ 10, 11, 16, 20 },{ 23, 30, 34, 50 } };
	return 0;
}