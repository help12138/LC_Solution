
#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool test1(int x) {
    /**
    * ˼·: ������(��������������)���·�Ϊ�������,
    * һ��Ϊż��λ���Ļ�����,һ������λ���Ļ�����
    * �Ƚ���������תΪ�ַ�������, Ȼ���ж�λ��
    * ��������ָ��,�ֱ�ָ���ַ����ĵ�һ���ַ������һ���ַ�
    * ��������λ�ַ���, �����һ��λ������ָ���ַ��ͬ,��������λֻҪ�ж����ߵ���ֵ�Ƿ���ͬ����
    * ����ż��λ�ַ���, ��ֻ��ѭ��һ���λ��,�����Ƚ�������ֵ
    */
    string num = to_string(x);
    cout << size(num) << endl;
    char* beginNum, * endNum;  // ����˫ָ��
    beginNum = &num[0];
    endNum = &num[size(num) - 1];
    int len = size(num) / 2;
    if (size(num) % 2 == 0 && num[0] != '-') {
        while (beginNum != endNum && *beginNum == *endNum)  // �ж�������ֵ�Ƿ���ͬ
        {
            if (len > 0) {  
                beginNum++;
                endNum--;
                len--;
            }
            else {
                cout << "�ǻ�����";
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
            cout << "�ǻ�����";
            return true;
        }
        else {
            cout << "���ǻ�����";
            return false;
        }

    }
}

bool test2(int x) {
    /*
    * ����ѧ�ķ�ʽ�ж��Ƿ��ǻ�����
    * ������λ�������ת
    * �ȽϷ�ת��������ԭ�����Ƿ���ͬ
    */
    if (x < 0) return false;

    int rNum = 0;
    int xNum = x;
    while (xNum != 0)
    {  // ��ת
        rNum = rNum * 10 + xNum % 10;
        xNum /= 10;

    }
    // �Ƚ�
    return rNum == x;
}
int mainIsPalindrome() {
    bool flag = test1(1001);
    if (flag) {
        cout << "�ǻ�����";
    }
    else {
        cout << "���ǻ�����";
    }
    return 0;
}
