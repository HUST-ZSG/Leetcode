#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int maximalRectangle(vector<vector<char>>& matrix) {
		int m = matrix.size();
		if (m == 0) return 0;
		int n = matrix[0].size();
		vector<vector<int> > left(m, vector<int>(n, 0));
		int cnt;
		for (int i = 0; i < m; ++i) {
			cnt = 0;
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == '0')
					cnt = 0;
				else
					++cnt;
				left[i][j] = cnt;
			}
		}

		int ans = 0;
		int width, length, area;
		for(int i = 0; i < m ; ++i)
			for (int j = 0; j < n; ++j) {
				width = n;
				length = 0;
				for (int k = i; k >= 0; --k) {
					length++;
					width = min(width, left[k][j]);
					area = length * width;
					ans = max(ans, area);
				}
			}
		return ans;
	}
};

int main()
{
	
}

