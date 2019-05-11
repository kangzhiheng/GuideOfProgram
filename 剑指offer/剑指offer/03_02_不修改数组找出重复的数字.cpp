//-----------------------------------------------------------------------------
// �� �� ��: 03_01_�ҳ��������ظ�������.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.04.14
// ��    �������޸������ҳ��ظ�������
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������3�����������޸������ҳ��ظ�������
// ��Ŀ����һ������Ϊn+1����������������ֶ���1��n�ķ�Χ�ڣ�������������
//		����һ���������ظ��ġ����ҳ�����������һ���ظ������֣��������޸������
//		���顣���磬������볤��Ϊ8������{2, 3, 5, 4, 3, 2, 6, 7}����ô��Ӧ��
//      ������ظ�������2����3��

// ˼·�����ַ���ͳ��ÿһ�԰������������ָ��������������ÿ�����ֳ��ֵĸ���֮�ʹ�������������ֵĸ����������ظ���
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// ͳ�������ڵ�ÿ�����ֳ��ֵĴ���֮��
int countRange(const vector<int>& numbers, int start, int end)
{
	// �쳣����
	if (numbers.empty())    // �������Ϊ��
		return 0;

	int length = numbers.size();

	int counts = 0;

	for (int i = 0; i < length; i++)
		if (numbers[i] >= start && numbers[i] <= end)
			++counts;

	return counts;

}

int getDuplication(const vector<int>& numbers)
{
	int length = numbers.size();

	// �쳣����
	if (numbers.empty() || length <= 0)
		return -1;

	int start = 1;
	int end = length - 1;

	while (end >= start)
	{
		int middle = start + ((end - start) >> 1);
		int count = countRange(numbers, start, middle);

		if (end == start)    // ��������
		{
			if (count > 1)    // �ظ����ֵĴ�������1
				return start;
			else
				break;
		}

		if (count > (middle - start) + 1)
			end = middle;
		else
			start = middle + 1;
	}

	return -1;
}

int main()
{
	int n;
	cin >> n;

	vector<int> arr;

	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		arr.push_back(val);
	}

	cout << getDuplication(arr) << endl;

	return 0;
}