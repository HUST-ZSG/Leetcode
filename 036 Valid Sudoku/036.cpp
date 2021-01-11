#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <stack>
using namespace std;

class Solution {
public:
	bool isValidSudoku(vector<vector<char>>& board) {
		int flag[3][9][10] = { 0 };
		for (int i = 0; i < board[0].size(); i++) 
			for (int j = 0; j < board.size(); j++) {
				if (board[i][j] != '.') {
					int temp = board[i][j] - '0';
					int k = j / 3 * 3 + i / 3;
					if (++flag[0][i][temp] != 1 || ++flag[1][j][temp] != 1 || ++flag[2][k][temp] != 1)return false;
				}
			}
		return true;
		
	}
};
int main() {
	Solution s;
	return 0;
}