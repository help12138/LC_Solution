/*
* 1491. ȥ����͹��ʺ���߹��ʺ�Ĺ���ƽ��ֵ
* ����һ���������� salary ��������ÿ�������� Ψһ �ģ����� salary[i] �ǵ� i ��Ա���Ĺ��ʡ�

���㷵��ȥ����͹��ʺ���߹����Ժ�ʣ��Ա�����ʵ�ƽ��ֵ��

 

ʾ�� 1��

���룺salary = [4000,3000,1000,2000]
�����2500.00000
���ͣ���͹��ʺ���߹��ʷֱ��� 1000 �� 4000 ��
ȥ����͹��ʺ���߹����Ժ��ƽ�������� (2000+3000)/2= 2500
ʾ�� 2��

���룺salary = [1000,2000,3000]
�����2000.00000
���ͣ���͹��ʺ���߹��ʷֱ��� 1000 �� 3000 ��
ȥ����͹��ʺ���߹����Ժ��ƽ�������� (2000)/1= 2000
ʾ�� 3��

���룺salary = [6000,5000,4000,3000,2000,1000]
�����3500.00000
ʾ�� 4��

���룺salary = [8000,9000,2000,3000,6000,1000]
�����4750.00000
*/

#include<iostream>
#include<string>
#include<vector>

using namespace std;

double average(vector<int>& salary) {
	/*
	* �жϳ���, �趨��������,һ�����ֵ,һ����Сֵ
	* ѭ������ÿ��Ԫ��, ͬʱ�Ƚ����Ԫ���뵱ǰ���ֵ����Сֵ�Ĵ�С.
	* ���ÿ��Ԫ�ص��ܺͼ�ȥ���ֵ����Сֵ
	*/
	int maxNum = 0, minNum = 0;
	double result = 0.00;
	maxNum = minNum = salary[0];
	for (int i = 0; i < salary.size(); i++) {
		if (salary[i] >= maxNum) {
			maxNum = salary[i];
			cout << result << endl;
		}
		else if (salary[i] <= minNum) {
			minNum = salary[i];
			cout << result << endl;
		}
		result = result + salary[i];
	}
	return result = (result - minNum - maxNum) / (salary.size() - 2);
}