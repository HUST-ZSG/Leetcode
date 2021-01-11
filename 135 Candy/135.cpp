#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	int candy(vector<int>& ratings) {
		
		int len = ratings.size();
		vector<int> v(len, 1);
		int ans = len;

		for (int i = 1; i < len; ++i) {
			if (ratings[i] > ratings[i - 1] && v[i] <= v[i-1]) {
				ans += v[i - 1] - v[i] + 1;
				v[i] = v[i - 1] + 1;
			}
		}

		int right = v[len - 1];
		for (int i = len - 2; i >= 0; --i) {
			if (ratings[i] > ratings[i + 1] && v[i] <= v[i + 1]) {
				ans += v[i + 1] - v[i] + 1;
				v[i] = v[i + 1] + 1;
			}
		}

		return ans;
	}
};

int main() {
	Solution s;
	vector<int> v{ 1,3,1 };
	cout << s.candy(v) << endl;
	return 0;
}