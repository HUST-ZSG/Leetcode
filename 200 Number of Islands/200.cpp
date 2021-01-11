#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;
/*
	给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。一个岛被水包围，
	并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。你可以假设网格的四个边均被水包围。

*/
class Solution {
public:
	int *p;
	int row;
	int col;
	void init(int size) {  // 初始化操作
		p = new int[size];
		for (int i = 0; i < size; i++)
			p[i] = i;
	}

	void u(int node1, int node2) {  // 合并操作
		int root1 = find(node1);
		int root2 = find(node2);
		if (root1 != root2)p[root2] = root1;
	}

	bool isconnect(int node1, int node2) {
		int root1 = find(node1);
		int root2 = find(node2);
		return root1 == root2;
	}

	int find(int node) {  //查找父亲结点并进行路径压缩
		int i, j = node;
		while (p[node] != node)node = p[node];
		while (j != p[j]) {   //路径压缩
			i = j;
			j = p[j];
			p[i] = node;
		}
		return node;
	}

	int seq(int i, int j) {  //计算对应矩阵元素在一维数组中的下标
		return i * col + j;
	}

	int numIslands(vector<vector<char>>& grid) {
		int ans = 0;
		if (grid.size() == 0 || grid[0].size() == 0)return 0;
		row = grid.size();
		col = grid[0].size();
		init(row*col);
		for(int i = 0; i < row; i++)
			for (int j = 0; j < col; j++) {
				if (grid[i][j] == '1') {  //对相邻陆地进行合并操作
					int temp = seq(i, j);
					if (i > 0 && grid[i - 1][j] == '1')u(temp, seq(i - 1, j));
					if (i < row - 1 && grid[i + 1][j] == '1')u(temp, seq(i + 1, j));
					if (j > 0 && grid[i][j - 1] == '1')u(temp, seq(i, j - 1));
					if (j < col - 1 && grid[i][j + 1] == '1')u(temp, seq(i, j + 1));
				}
			}

		for (int i = 0; i < row; i++)     
			for (int j = 0; j < col; j++) {
				int temp = seq(i, j);
				if (grid[i][j] == '1'&&p[temp] == temp)ans++;    //计算岛屿数量
			}
		return ans;
	}
};
int main() {
	Solution s;
	vector<vector<char> > v = { { 'X','O','X','X' },{ 'O','X','O','X' },{ 'X','O','X','O' },{ 'O','X','O','X' },{ 'X','O','X','O' },{ 'O','X','O','X' } };
	return 0;
}