/*
* 1491. 去掉最低工资和最高工资后的工资平均值
* 给你一个整数数组 salary ，数组里每个数都是 唯一 的，其中 salary[i] 是第 i 个员工的工资。

请你返回去掉最低工资和最高工资以后，剩下员工工资的平均值。

 

示例 1：

输入：salary = [4000,3000,1000,2000]
输出：2500.00000
解释：最低工资和最高工资分别是 1000 和 4000 。
去掉最低工资和最高工资以后的平均工资是 (2000+3000)/2= 2500
示例 2：

输入：salary = [1000,2000,3000]
输出：2000.00000
解释：最低工资和最高工资分别是 1000 和 3000 。
去掉最低工资和最高工资以后的平均工资是 (2000)/1= 2000
示例 3：

输入：salary = [6000,5000,4000,3000,2000,1000]
输出：3500.00000
示例 4：

输入：salary = [8000,9000,2000,3000,6000,1000]
输出：4750.00000
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

double average(vector<int>& salary) {
	/*
	* 判断长度, 设定两个变量,一个最大值,一个最小值
	* 循环遍历每个元素, 同时比较这个元素与当前最大值和最小值的大小.
	* 最后将每个元素的总和减去最大值和最小值
	*/
	int maxNum = 0, minNum = 0;
	double result = 0.00;
	maxNum = minNum = salary[0];
	for (int i = 0; i < salary.size(); i++) {
		if (salary[i] >= maxNum) {
			maxNum = salary[i];
			cout << result << endl;
		}
		else if (salary[i] <= minNum) {
			minNum = salary[i];
			cout << result << endl;
		}
		result = result + salary[i];
	}
	return result = (result - minNum - maxNum) / (salary.size() - 2);
}