#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
	bool canTransform(string start, string end) {
		int len = start.size();
		int i = 0, j = 0;
		if (len != end.size())return false;
		while(i < len && j < len){
			if (start[i] == end[j]) {
				if (end[j] == 'L'&&i < j)return false;
				if (end[j] == 'R'&&i > j)return false;
				i++;
				j++;
			}
			else if (start[i] == 'X')i++;
			else if (end[j] == 'X')j++;
			else return false;
		}
		while (i < len)
			if (start[i++] != 'X')return false;
		while (j < len)
			if (end[j++] != 'X')return false;
		return true;
	}
};
int main() {
	Solution s;
	cout << s.canTransform("XLLR","LXLX")<< endl;
	return 0;
}