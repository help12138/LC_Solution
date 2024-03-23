/*
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。

示例 1：

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
示例 2：

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5
*/


#include<iostream>
#include<string>
#include<vector>

using namespace std;
/*
解题思路
先将两个数组合并成一个, 然后求新数组的中间值
合并:
  定义两个指针, 分别指向两个数组的, 比较两个数组的大小, 将小的那个添加进新数组
  如果一方添加完毕, 则将另一方剩下的全部元素直接插进新数组的末尾
  最后根据新数组的长度, 求中间值
*/
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	vector<int> newNums;
	int m = nums1.size();
	int n = nums2.size();
	int len = m + n;
	int i = 0, k = 0;
	while (len > 0)
	{
		// 判断两个数组已经遍历完
		if (i > (m - 1)) {
			newNums.insert(newNums.end(), nums2.begin() + k, nums2.end());
			break;
		}
		else if (k > (n - 1)) {
			newNums.insert(newNums.end(), nums1.begin() + i, nums1.end());
			break;
		}
		// 比较两个数组, 将小的那个添加进新数组
		if (nums1[i] < nums2[k]) {
			newNums.push_back(nums1[i]);
			i++;
		}
		else {
			newNums.push_back(nums2[k]);
			k++;
		}
		len--;
	}
	// 获得中间值
	double result = (m + n) % 2 > 0 ? (double)newNums[(m + n) / 2] : (double)(newNums[(m + n) / 2] + newNums[(m + n) / 2 - 1]) / 2;
	cout << result;

	return result;
}