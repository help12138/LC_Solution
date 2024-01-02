/*
����һ��ֻ���� '('��')'��'{'��'}'��'['��']' ���ַ��� s ���ж��ַ����Ƿ���Ч��

��Ч�ַ��������㣺

�����ű�������ͬ���͵������űպϡ�
�����ű�������ȷ��˳��պϡ�
ÿ�������Ŷ���һ����Ӧ����ͬ���͵������š�


ʾ�� 1��

���룺s = "()"
�����true
ʾ�� 2��

���룺s = "()[]{}"
�����true
ʾ�� 3��

���룺s = "(]"
�����false
*/

/*
	��Ŀ����
	�������ʹ��ջ������, ���Ϊ������������ջ��
	���Ϊ������, ��Ҫ�鿴ջ���Ƿ��ж�Ӧ��������.
	�����, ���ջ��ɾ��������
	����ٸ���ջ���Ƿ���ֵ���ж��Ƿ�ϸ�
*/
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map>
#include<stack> // ջ��ͷ�ļ�

using namespace std;

bool isValid(string s) {
	// ʹ��map����������. �����пɶ���Ϊ˽�б���
	unordered_map <char, int> m {{'(', 1}, { '[',2 }, { '{',3 }, { ')',4 }, { ']',5 }, { '}',6 }, };

	// ����ջ
	stack <char> st;
	for (char t : s) {
		int flag = m[t];
		if (flag >= 1 && flag <= 3) {
			// ���Ϊ�����������ջ
			st.push(t);
		}
		else if (!st.empty() && m[st.top()] == flag - 3) {
			// �ж��������Ƿ��������Ŷ�Ӧ
			st.pop();
		}
		else {
			return false;
		}
	}
	// �ж�ջ���Ƿ�����ֵ
	if (!st.empty()) return false;
	return true;
}

int mainIsValid() {
	bool isTrue = isValid("{()}");
	if (isTrue) {
		cout << "���Ǻϸ��";
	}
	else {
		cout << "���ϸ�";
	}
	return 0;
}
