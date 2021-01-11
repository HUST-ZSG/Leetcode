#include<iostream>
#include<queue>

using namespace std;

/*
	方法一，单队列实现，需要额外判断双方是否还剩余有成员
*/
class Solution1 {
public:
	string predictPartyVictory(string senate) {
		int r, d;
		r = d = 0;
		int cnt1, cnt2;
		cnt1 = cnt2 = 0;
		queue<int> q;
		for (int i = 0; i < senate.size(); ++i) {
			if (senate[i] == 'R') {
				q.push(1);
				cnt1++;
			}
			else {
				q.push(0);
				cnt2++;
			}
		}
		while (!q.empty()) {
			int temp = q.front();
			if (temp == 1) {
				if (r > 0) {
					r--;
					cnt1--;
				}
				else {
					q.push(1);
					d++;
				}
			}
			else {
				if (d > 0) {
					d--;
					cnt2--;
				}
				else {
					q.push(0);
					r++;
				}
			}
			q.pop();
			if(cnt1 == 0)
				return "Dire";
			if(cnt2 == 0)
				return "Radiant";
		}
		return "";
	}
};

/*
	方法二：使用双队列循环实现
*/
class Solution2 {
public:
	string predictPartyVictory(string senate) {
		int n = senate.size();
		queue<int> r, d;
		for (int i = 0; i < n; ++i) {
			if (senate[i] == 'R')
				r.push(i);
			else
				d.push(i);
		}
		while (!r.empty() && !d.empty()) {
			if (r.front() < d.front())
				r.push(r.front() + n);
			else
				d.push(d.front() + n);
			r.pop();
			d.pop();
		}
		return r.empty() ? "Dire" : "Radiant";
	}
};

int main() {
	return 0;
}