#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <stack>
#include <unordered_map>
using namespace std;

class Solution {
public:
	vector<int> findSubstring(string s, vector<string>& words) {
		vector<int> v;
		if (words.size() == 0 || s.size() < words[0].size()*words.size())return v;
		int len = words[0].size()*words.size();
		int word_len = words[0].size();
		unordered_map<string, int> m;
		for (string word : words) {
			if (m.find(word) == m.end())m[word] = 1;
			else m[word]++;
		}
		for (int i = 0; i < s.size() - len + 1; i++) {
			string str = s.substr(i, len);
			unordered_map<string, int> t = m;
			bool flag = true;
			for (int j = 0; j < str.size(); j += word_len) {
				string temp = str.substr(j, word_len);
				if (t.find(temp) == t.end() || t[temp] == 0) {
					flag = false;
					break;
				}
				else t[temp]--;
			}
			if (flag)v.push_back(i);
		}
		return v;
	}
};
int main() {
	vector<string> ss({ "sadss","happy" });
	Solution s;
	cout << s.findSubstring("sadsshappy", ss).size() << endl;
	return 0;
}