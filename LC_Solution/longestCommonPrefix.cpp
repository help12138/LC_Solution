/*
��дһ�������������ַ��������е������ǰ׺��

��������ڹ���ǰ׺�����ؿ��ַ��� ""��



ʾ�� 1��

���룺strs = ["flower","flow","flight"]
�����"fl"
ʾ�� 2��

���룺strs = ["dog","racecar","car"]
�����""
���ͣ����벻���ڹ���ǰ׺��
*/

/*
* ��Ŀ����
* ͨ��˫��ѭ��,��һ��ѡȡ��һ���ַ���Ԫ�ص�ÿ���ַ�
* �ڶ���ѭ��,����ѡȡ�󼸸�Ԫ��
* ͨ������Ƚ�ÿ��Ԫ����һ��Ԫ�ص��ַ��Ƿ����
* �������ӽ�һ���µ��ַ���
* ������򷵻�
* 
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs) {
	int firstLen = strs[0].length(); // ��Ԫ���ַ����ĳ���
	int elementNum = strs.size(); //�����ĳ���
	string prefix = "";  // Ҫ���ص����ַ���
	for (int i = 0; i < firstLen; i++) {

		for (int j = 1; j < elementNum; j++) {
			if (strs[0][i] != strs[j][i] || i > strs[j].length()) {
				// ͨ���ж�ÿ��Ԫ�صĶ�Ӧ�ַ�
				// ��ǰ��Ԫ�ص��ַ��±������Ԫ�صĳ��ȱȽ�
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
