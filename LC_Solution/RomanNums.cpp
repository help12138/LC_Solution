/*
�������ְ������������ַ�: I�� V�� X�� L��C��D �� M��

�ַ�          ��ֵ
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
���磬 �������� 2 д�� II ����Ϊ�������е� 1 ��12 д�� XII ����Ϊ X + II �� 27 д��  XXVII, ��Ϊ XX + V + II ��

ͨ������£�����������С�������ڴ�����ֵ��ұߡ���Ҳ�������������� 4 ��д�� IIII������ IV������ 1 ������ 5 ����ߣ�����ʾ�������ڴ��� 5 ��С�� 1 �õ�����ֵ 4 ��ͬ���أ����� 9 ��ʾΪ IX���������Ĺ���ֻ�������������������

I ���Է��� V (5) �� X (10) ����ߣ�����ʾ 4 �� 9��
X ���Է��� L (50) �� C (100) ����ߣ�����ʾ 40 �� 90��
C ���Է��� D (500) �� M (1000) ����ߣ�����ʾ 400 �� 900��
����һ���������֣�����ת����������

ʾ�� 1:

����: s = "III"
���: 3
ʾ�� 2:

����: s = "IV"
���: 4
ʾ�� 3:

����: s = "IX"
���: 9
*/

#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>

using namespace std;

/*
������Ŀ����,��ץס����ұߵ��������������ı������������, �ͼ�ȥ���������
����ұ�С,�ͼ������������
*/

// -----------------------------------------------
/*
�������
ʹ��map����, ����һ����ֵ��,Ȼ����в�ѯ�Ա�
unordered_map��map���������, ǰ�߲����Զ���С��������,���෽��������ͬ
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
		int value = RomanNums[s[i]]; // ����ǰ����ֵ����value
		if (i < len && value < RomanNums[s[i + 1]]) {
			// �Ƚϵ�ǰvalue���һ������ֵ�Ĵ�С������Ӧ�ļӼ�����
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