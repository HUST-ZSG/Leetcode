#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		int value[13] = { 1000,900,500,400,100,90,50,40,10,9,5,4,1 };
		string rep[13] = { "M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I" };
		string str;
		for (int i = 0; i < 13; i++) {
			while (num >= value[i]) {
				num -= value[i];
				str += rep[i];
			}
		}
		return str;
	}
};
int main() {
	Solution s;

	cout << s.intToRoman(1994) << endl;
	return 0;
}