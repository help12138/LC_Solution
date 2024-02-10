/*ɾ�����������е��ظ���*/


/*
* ����һ�� ���ϸ�������� ������ nums ������ ԭ�� ɾ���ظ����ֵ�Ԫ�أ�ʹÿ��Ԫ�� ֻ����һ�� ������ɾ����������³��ȡ�Ԫ�ص� ���˳�� Ӧ�ñ��� һ�� ��Ȼ�󷵻� nums ��ΨһԪ�صĸ�����

���� nums ��ΨһԪ�ص�����Ϊ k ������Ҫ����������ȷ����������Ա�ͨ����

�������� nums ��ʹ nums ��ǰ k ��Ԫ�ذ���ΨһԪ�أ���������������� nums �г��ֵ�˳�����С�nums ������Ԫ���� nums �Ĵ�С����Ҫ��
���� k ��
�����׼:

ϵͳ��������Ĵ���������������:

int[] nums = [...]; // ��������
int[] expectedNums = [...]; // ������ȷ��������

int k = removeDuplicates(nums); // ����

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
������ж��Զ�ͨ������ô������⽫�� ͨ����

 

ʾ�� 1��

���룺nums = [1,1,2]
�����2, nums = [1,2,_]
���ͣ�����Ӧ�÷����µĳ��� 2 ������ԭ���� nums ��ǰ����Ԫ�ر��޸�Ϊ 1, 2 ������Ҫ���������г����³��Ⱥ����Ԫ�ء�
ʾ�� 2��

���룺nums = [0,0,1,1,1,2,2,3,3,4]
�����5, nums = [0,1,2,3,4]
���ͣ�����Ӧ�÷����µĳ��� 5 �� ����ԭ���� nums ��ǰ���Ԫ�ر��޸�Ϊ 0, 1, 2, 3, 4 ������Ҫ���������г����³��Ⱥ����Ԫ�ء�
*/



/*����˫ָ�뷨, ��ͣ���жϵ�ǰԪ����ǰһ��Ԫ���Ƿ���ͬ, 
�������ͬ�ͽ���ǰԪ�ظ�ֵ��ǰһ��Ԫ��, ��Ϊ��ʼ�±�һ��, �����൱�����Ҹ�ֵ
���Ԫ����ͬ, �򽫿�ָ�����, ��ָ�벻��, ֱ���ҵ�����ͬ��Ԫ��,
������ͬ��Ԫ�ظ�ֵ����ͬʱ����ָ����ָԪ��, ��ָ�����
�Դ˲�ͣ��ɾ���ظ���
*/
#include<iostream>
#include<string>
#include<vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	int n = nums.size();
	if (n == 0) {
		return 0;
	}
	int second = 1, first = 1;
	while (second < n)
	{
		if (nums[second] != nums[second - 1]) {
			nums[first] = nums[second];
			++first;
		}
		++second;
	}
	return first;
}