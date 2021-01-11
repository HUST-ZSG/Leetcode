#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:

	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (matrix.size() == 0 || matrix[0].size() == 0)return false;
		int row = matrix.size();
		int col = matrix[0].size();
		int i = 0;
		int j = row * col - 1;
		while (i <= j) {
			int mid = (j + i) / 2;
			if (matrix[mid / col][mid%col] == target)return true;
			else if (matrix[mid / col][mid%col] < target)i = mid + 1;
			else j = mid - 1;
		}
		return false;
	}
};

int main() {
	Solution s;
	vector<vector<int> > v = { {1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 50} };
	cout << s.searchMatrix(v, 3) << endl;
	return 0;
}