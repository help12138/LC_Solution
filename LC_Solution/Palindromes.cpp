
#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool test1(int x) {
    /**
    * 思路: 回文数(仅限整数回文数)大致分为两种情况,
    * 一种为偶数位数的回文数,一种奇数位数的回文数
    * 先将整数类型转为字符串类型, 然后判断位数
    * 定义两个指针,分别指向字符串的第一个字符和最后一个字符
    * 若是奇数位字符串, 则必有一个位置两个指针地址相同,所以奇数位只要判断两边的数值是否相同即可
    * 若是偶数位字符串, 则只需循环一般的位数,用来比较两边数值
    */
    string num = to_string(x);
    cout << size(num) << endl;
    char* beginNum, * endNum;  // 定义双指针
    beginNum = &num[0];
    endNum = &num[size(num) - 1];
    int len = size(num) / 2;
    if (size(num) % 2 == 0 && num[0] != '-') {
        while (beginNum != endNum && *beginNum == *endNum)  // 判断两侧数值是否相同
        {
            if (len > 0) {  
                beginNum++;
                endNum--;
                len--;
            }
            else {
                cout << "是回文数";
                return true;
            }

        }
        cout << "no";
        return false;

    }

    if (size(num) % 2 != 0 && num[0] != '-') {
        while (beginNum != endNum && *beginNum == *endNum)
        {
            beginNum++;
            endNum--;
        }
        if (beginNum == endNum) {
            cout << "是回文数";
            return true;
        }
        else {
            cout << "不是回文数";
            return false;
        }

    }
}

bool test2(int x) {
    /*
    * 用数学的方式判断是否是回文数
    * 将数字位数逐个翻转
    * 比较翻转后数字与原数字是否相同
    */
    if (x < 0) return false;

    int rNum = 0;
    int xNum = x;
    while (xNum != 0)
    {  // 翻转
        rNum = rNum * 10 + xNum % 10;
        xNum /= 10;

    }
    // 比较
    return rNum == x;
}
int mainIsPalindrome() {
    bool flag = test1(1001);
    if (flag) {
        cout << "是回文数";
    }
    else {
        cout << "不是回文数";
    }
    return 0;
}
