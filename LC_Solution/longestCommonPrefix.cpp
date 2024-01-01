/*
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。



示例 1：

输入：strs = ["flower","flow","flight"]
输出："fl"
示例 2：

输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
*/

/*
* 题目解析
* 通过双重循环,第一层选取第一个字符串元素的每个字符
* 第二层循环,用来选取后几个元素
* 通过纵向比较每个元素与一个元素的字符是否相等
* 相等则添加进一个新的字符串
* 不相等则返回
* 
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	int firstLen = strs[0].length(); // 首元素字符串的长度
	int elementNum = strs.size(); //容器的长度
	string prefix = "";  // 要返回的新字符串
	for (int i = 0; i < firstLen; i++) {

		for (int j = 1; j < elementNum; j++) {
			if (strs[0][i] != strs[j][i] || i > strs[j].length()) {
				// 通过判断每个元素的对应字符
				// 当前首元素的字符下标与后续元素的长度比较
				return prefix;
			}
		}
		prefix.push_back(strs[0][i]);
	}

	return prefix;
}

int main_longestCommonPrefix() {
	vector<string> strs {"a", "ac"};
	string str = longestCommonPrefix(strs);
	cout << str;
	return 0;
}
