/*删除有序数组中的重复项*/


/*
* 给你一个 非严格递增排列 的数组 nums ，请你 原地 删除重复出现的元素，使每个元素 只出现一次 ，返回删除后数组的新长度。元素的 相对顺序 应该保持 一致 。然后返回 nums 中唯一元素的个数。

考虑 nums 的唯一元素的数量为 k ，你需要做以下事情确保你的题解可以被通过：

更改数组 nums ，使 nums 的前 k 个元素包含唯一元素，并按照它们最初在 nums 中出现的顺序排列。nums 的其余元素与 nums 的大小不重要。
返回 k 。
判题标准:

系统会用下面的代码来测试你的题解:

int[] nums = [...]; // 输入数组
int[] expectedNums = [...]; // 长度正确的期望答案

int k = removeDuplicates(nums); // 调用

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
如果所有断言都通过，那么您的题解将被 通过。

 

示例 1：

输入：nums = [1,1,2]
输出：2, nums = [1,2,_]
解释：函数应该返回新的长度 2 ，并且原数组 nums 的前两个元素被修改为 1, 2 。不需要考虑数组中超出新长度后面的元素。
示例 2：

输入：nums = [0,0,1,1,1,2,2,3,3,4]
输出：5, nums = [0,1,2,3,4]
解释：函数应该返回新的长度 5 ， 并且原数组 nums 的前五个元素被修改为 0, 1, 2, 3, 4 。不需要考虑数组中超出新长度后面的元素。
*/



/*利用双指针法, 不停的判断当前元素与前一个元素是否相同, 
如果不相同就将当前元素赋值给前一个元素, 因为初始下标一样, 所以相当于自我赋值
如果元素相同, 则将快指针后移, 慢指针不变, 直到找到不相同的元素,
将不相同的元素赋值给相同时的慢指针所指元素, 慢指针后移
以此不停的删除重复项
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	int n = nums.size();
	if (n == 0) {
		return 0;
	}
	int second = 1, first = 1;
	while (second < n)
	{
		if (nums[second] != nums[second - 1]) {
			nums[first] = nums[second];
			++first;
		}
		++second;
	}
	return first;
}