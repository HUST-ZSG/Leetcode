#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
	int *p;
	int row;
	int col;
	void init(int size) {
		p = new int[size];
		for (int i = 0; i < size; i++)
			p[i] = i;
	}

	void u(int node1, int node2) {
		int root1 = find(node1);
		int root2 = find(node2);
		if (root1 != root2)p[root2] = root1;
	}

	bool isconnect(int node1, int node2) {
		int root1 = find(node1);
		int root2 = find(node2);
		return root1 == root2;
	}

	int find(int node) {
		int i, j = node;
		while (p[node] != node)node = p[node];
		while (j != p[j]) {
			i = j;
			j = p[j];
			p[i] = node;
		}
		return node;
	}

	int seq(int i, int j) {
		return i * col + j;
	}
	void solve(vector<vector<char>>& board) {
		if (board.size() == 0 || board[0].size() == 0)return;
		row = board.size();
		col = board[0].size();
		init(row*col + 1);
		int vir = row * col;
		for (int i = 0; i < row; i++) 
			for (int j = 0; j < col; j++) {
				if (board[i][j] == 'O') {
					if (i == 0 || i == row - 1 || j == 0 || j == col - 1)
						u(vir, seq(i, j));
					else {
						if (i > 0 && board[i - 1][j] == 'O')
							u(seq(i, j), seq(i - 1, j));
						if (i < row - 1 && board[i + 1][j] == 'O')
							u(seq(i, j), seq(i + 1, j));
						if (j > 0 && board[i][j - 1] == 'O')
							u(seq(i, j), seq(i, j - 1));
						if (j < col - 1 && board[i][j + 1] == 'O')
							u(seq(i, j), seq(i, j + 1));
					}
				}
			}
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++) {
				if (isconnect(vir, seq(i, j)))board[i][j] = 'O';
				else board[i][j] = 'X';
			}
	}
};
int main() {
	Solution s;
	vector<vector<char> > v = { {'X','O','X','X'},{'O','X','O','X'},{'X','O','X','O'},{'O','X','O','X'},{'X','O','X','O'},{'O','X','O','X'} };
	s.solve(v);
	return 0;
}