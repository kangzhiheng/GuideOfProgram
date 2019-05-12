//-----------------------------------------------------------------------------
// �� �� ��: 21_��������˳��ʹ����λ��ż��ǰ��.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.05.11
// ��    ������������˳��ʹ����λ��ż��ǰ��
// ��    ����
//-----------------------------------------------------------------------------

/*
	������21����������˳��ʹ����λ��ż��ǰ��
	��Ŀ������һ���������飬ʵ��һ�����������������������ֵ�˳��ʹ������
		 ����λ�������ǰ�벿�֣�����ż��λ������ĺ�벿�֣���ʹ�����ֽ�С�����ڽϴ����ǰ��
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*
�ж���ż�ԣ�����һ������a
1. a & 0x1 == 0����aΪż��������aΪ6��������Ϊ0110��0110 & 0001 = 0000
2. a & 0x1 != 0����aΪ����������aΪ7��������Ϊ0111��0111 & 0001 = 0001
*/
bool isEven(int n)
{
	return (n & 0x01) == 0;
}

void ReOrganizationArray(vector<int>& arr)
{
	// �쳣���
	if (arr.empty())
		return;

	// ����˫ָ��
	int left = 0;                  // ��ָ��
	int right = arr.size() - 1;    // ��ָ��

	while (left < right)
	{

		// ���ƶ���ָ�룬ֱ���ҵ�ż��ʱ��ֹͣ�ƶ�
		while (left < right && !isEven(arr[left]))
			left++;
		// ���ƶ���ָ�룬ֱ���ҵ�����ʱ��ֹͣ�ƶ�
		while (left < right && isEven(arr[right]))
			right--;
		// ����ż�������������ҵ������������������
		if (left < right)
		{
			swap(arr[left], arr[right]);
			// �������䲻Ҫ�ӣ����ǵ�Ŀ����Ϊ����������ָ������������Ϊ�˺��������
			// left++;
			// right--;
		}
		if (left == right)
		{
			cout << left << " " << right << endl;
			sort(arr.begin(), arr.begin() + left);     // ������������
			sort(arr.begin() + left, arr.begin() + arr.size());  // ż����������
		}
		
	}
	// cout << left << " " << right << endl;
}

int main()
{
	// vector<int> arr = { 3, 2, 1, 4, 5, 0, 7, 8, 1, 6 };
	vector<int> arr;
	int val;
	cout << "����������Ԫ��: ";
	while (scanf("%d", &val))
		arr.emplace_back(val);

	cout << "ԭ����Ϊ: ";
	for (size_t i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	
	// ��������
	ReOrganizationArray(arr);
	
	cout << "����ǰż�ں������Ϊ: ";
	for (size_t i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";

	return 0;
}