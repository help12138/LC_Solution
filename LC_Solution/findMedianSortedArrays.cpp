/*
����������С�ֱ�Ϊ m �� n �����򣨴�С�������� nums1 �� nums2�������ҳ���������������������� ��λ�� ��

�㷨��ʱ�临�Ӷ�Ӧ��Ϊ O(log (m+n)) ��

ʾ�� 1��

���룺nums1 = [1,3], nums2 = [2]
�����2.00000
���ͣ��ϲ����� = [1,2,3] ����λ�� 2
ʾ�� 2��

���룺nums1 = [1,2], nums2 = [3,4]
�����2.50000
���ͣ��ϲ����� = [1,2,3,4] ����λ�� (2 + 3) / 2 = 2.5
*/


#include<iostream>
#include<string>
#include<vector>

using namespace std;
/*
����˼·
�Ƚ���������ϲ���һ��, Ȼ������������м�ֵ
�ϲ�:
  ��������ָ��, �ֱ�ָ�����������, �Ƚ���������Ĵ�С, ��С���Ǹ���ӽ�������
  ���һ��������, ����һ��ʣ�µ�ȫ��Ԫ��ֱ�Ӳ���������ĩβ
  ������������ĳ���, ���м�ֵ
*/
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	vector<int> newNums;
	int m = nums1.size();
	int n = nums2.size();
	int len = m + n;
	int i = 0, k = 0;
	while (len > 0)
	{
		// �ж����������Ѿ�������
		if (i > (m - 1)) {
			newNums.insert(newNums.end(), nums2.begin() + k, nums2.end());
			break;
		}
		else if (k > (n - 1)) {
			newNums.insert(newNums.end(), nums1.begin() + i, nums1.end());
			break;
		}
		// �Ƚ���������, ��С���Ǹ���ӽ�������
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
	// ����м�ֵ
	double result = (m + n) % 2 > 0 ? (double)newNums[(m + n) / 2] : (double)(newNums[(m + n) / 2] + newNums[(m + n) / 2 - 1]) / 2;
	cout << result;

	return result;
}