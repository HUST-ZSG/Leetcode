#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
using namespace std;

/*
	方法一
	利用归并的思想
	算法复杂度为  log(m + n)
*/
/*
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		double sum = 0;
		double temp = 0;
		int len1 = 0, len2 = 0;
		int count = 0;
		int count1 = nums1.size() + nums2.size() - 1;
		while (count <= (count1 + 1) / 2) {

			if (len1 < nums1.size()&&(len2 == nums2.size() || nums1[len1] < nums2[len2]&&len1 < nums1.size()))
			{
				temp = nums1[len1];
				len1++;
			}
			else
			{
				temp = nums2[len2];
				len2++;
			}
			if (count == count1 / 2 || count == (count1 + 1) / 2)
				sum += temp;
			count++;
		}
		return count1%2 ? sum / 2 : sum;
	}
};
*/


/*
	方法二
	利用寻找第K小的思想
*/
class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

		int m = nums1.size();

		int n = nums2.size();

		int left = (m + n + 1) / 2;

		int right = (m + n + 2) / 2;
		
		//合并奇数和偶数的情况
		return (getKth(nums1, 0, m - 1, nums2, 0, n - 1, left) + getKth(nums1, 0, m - 1, nums2, 0, n - 1, right)) / 2;

	}

	double getKth(vector<int>& nums1, int start1, int end1, vector<int>& nums2, int start2, int end2, int k) {

		int len1 = end1 - start1 + 1;

		int len2 = end2 - start2 + 1;

		if (len1 > len2)return getKth(nums2, start2, end2, nums1, start1, end1, k);

		if (len1 == 0)return nums2[start2 + k - 1];

		if (k == 1)return min(nums1[start1], nums2[start2]);

		int i = start1 + min(len1, k / 2) - 1;   //查看是否超过数组长度

		int j = start2 + min(len2, k / 2) - 1;

		if (nums1[i] > nums2[j]) {

			return getKth(nums1, start1, end1, nums2, j + 1, end2, k - (j - start2 + 1));

		}
		else {

			return getKth(nums1, i + 1, end1, nums2, start2, end2, k - (i - start1 + 1));

		}
	}
};
int main() {
	Solution s;
	vector<int> nums1 = {1, 3};
	vector<int> nums2 = {2, 4};
	cout << s.findMedianSortedArrays(nums1, nums2) << endl;
	return 0;
}