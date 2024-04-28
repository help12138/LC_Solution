#include<iostream>
#include<string>
#include<vector>

/*
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明：你不能倾斜容器。
输入：[1,8,6,2,5,4,8,3,7]
输出：49
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
示例 2：

输入：height = [1,1]
输出：1
*/

/*题解:
* 本题实际上求得就是面积,
* 因为水的面积是由两边最短的那个木板长度决定的
* 所以, 我们可以使用双指针法, 从左右不停的递进下一个围成的水槽面积
* 当另一边长度低于本来是低的那边长度时, 注定面积是要缩小的, 故以两边长度为判断条件
* 进行递进,替换最大值变量的数值, 
* 然后选出最大的就好
*/
using namespace std;

class Solution {
public:
	Solution() {};
	int maxArea(vector<int>& height) {
		int i = 0, j = height.size() - 1;
		while (i < j)
		{
			res = height[i] < height[j] ? max(res, (j - i) * height[i++]) : max(res, (j - i) * height[j--]);
		}
		cout << "---------" << res << "-----------";
		return res;
	}
private:
	int res = 0;
};