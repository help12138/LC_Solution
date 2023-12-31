/*
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1 。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。

示例 1:

输入: s = "III"
输出: 3
示例 2:

输入: s = "IV"
输出: 4
示例 3:

输入: s = "IX"
输出: 9
*/

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

/*
本题题目解析,就抓住如果右边的罗马数所代表的比左边罗马数大, 就减去左边罗马数
如果右边小,就加上左边罗马数
*/

// -----------------------------------------------
/*
解决方案
使用map方法, 构造一个键值对,然后进行查询对比
unordered_map和map的区别就是, 前者不会自动由小到大排序,其余方法几近相同
*/
unordered_map<char, int> RomanNums = {
	{'I',1},
	{'V',5},
	{'X',10},
	{'L',50},
	{'C',100},
	{'D',500},
	{'M',1000},
};

int romanToInt(string s) {
	int num = 0;
	int len = s.length();
	for (int i = 0; i < len; i++)
	{
		int value = RomanNums[s[i]]; // 将当前罗马值赋给value
		if (i < len && value < RomanNums[s[i + 1]]) {
			// 比较当前value与后一个罗马值的大小进行相应的加减运算
			num -= value;
		}
		else {
			num += value;
		}
	}
	return num;
}

int mainRomanToInt() {
	int result = romanToInt("MCMXCIV");
	cout << result;
	return 0;
}