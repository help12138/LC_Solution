/*
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。


示例 1：

输入：s = "()"
输出：true
示例 2：

输入：s = "()[]{}"
输出：true
示例 3：

输入：s = "(]"
输出：false
*/

/*
	题目解析
	本题可以使用栈来处理, 如果为左括号则填入栈内
	如果为右括号, 则要查看栈内是否有对应的左括号.
	如果有, 则从栈内删除左括号
	最后再根据栈内是否还有值来判断是否合格
*/
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<stack> // 栈的头文件

using namespace std;

bool isValid(string s) {
	// 使用map来定义数据. 在类中可定义为私有变量
	unordered_map <char, int> m {{'(', 1}, { '[',2 }, { '{',3 }, { ')',4 }, { ']',5 }, { '}',6 }, };

	// 定义栈
	stack <char> st;
	for (char t : s) {
		int flag = m[t];
		if (flag >= 1 && flag <= 3) {
			// 如果为左括号则存入栈
			st.push(t);
		}
		else if (!st.empty() && m[st.top()] == flag - 3) {
			// 判断右括号是否与左括号对应
			st.pop();
		}
		else {
			return false;
		}
	}
	// 判断栈内是否还有余值
	if (!st.empty()) return false;
	return true;
}

int mainIsValid() {
	bool isTrue = isValid("{()}");
	if (isTrue) {
		cout << "这是合格的";
	}
	else {
		cout << "不合格";
	}
	return 0;
}
