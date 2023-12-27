
#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool test1(int x) {
    string num = to_string(x);
    cout << size(num) << endl;
    char* beginNum, * endNum;
    beginNum = &num[0];
    endNum = &num[size(num) - 1];
    int len = size(num) / 2;
    if (size(num) % 2 == 0 && num[0] != '-') {
        while (beginNum != endNum && *beginNum == *endNum)
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
    if (x < 0) return false;

    int rNum = 0;
    int xNum = x;
    while (xNum != 0)
    {
        rNum = rNum * 10 + xNum % 10;
        xNum /= 10;

    }
    return rNum == x;
}
int main() {
    bool flag = test1(1001);
    if (flag) {
        cout << "是回文数";
    }
    else {
        cout << "不是回文数";
    }
    return 0;
}
