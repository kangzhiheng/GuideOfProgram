//-----------------------------------------------------------------------------
// �� �� ��: 11_ת�����е���С����.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.04.27
// ��    ����ת�����е���С����
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������11����ת�������С����
// ��Ŀ����һ�������ʼ�����ɸ�Ԫ�ذᵽ�����ĩβ�����ǳ�֮Ϊ�������ת��
//      ����һ����������������һ����ת�������ת�������СԪ�ء���������
//      {3, 4, 5, 1, 2}Ϊ{1, 2, 3, 4, 5}��һ����ת�����������СֵΪ1��

/*
    ˼·�����ַ�
*/
#include <iostream>
#include <vector>

using namespace std;

int MinInOrder(vector<int>& arr, int left, int right);

int MinNumberInRotatedArray(vector<int> arr)
{
	// �쳣�ж�
	if (arr.empty() || arr.size() <= 0)
		throw new exception("�Ƿ�����");

	int left = 0;    // ��ߵ��������ָ��
	int right = arr.size() - 1;  // �ұߵ��������ָ��
	int mid = left;

	// �����һ������С�����һ�����֣���ô��һ�����־�����ת�������С���֣���ԭ���鱾��Ҳ����ת����
	while (arr[left] >= arr[right])
	{
		// ��������������������ڵ�һ����������Ľ���λ�ã��������ڵڶ��������������ʼλ�ã�
		// ��������ֵ���������ĺ�һ��λ�ã�����С���־�������������λ��
		if (right - left == 1)
		{
			mid = right;
			break;
		}

		mid = (right + left) / 2;
		
		// ����±�left��right��mid����ֵ����ȣ�
		// ��ֻ��˳�����
		if (arr[left] == arr[right] && arr[left] == arr[mid])
			return MinInOrder(arr, left, right);

		// ����м���������ֵ�������������ֵ�������midָ���ڵ�һ�����������
		// ��С���ֻ��ں��棬���ƶ���ָ�뵽�м�ָ��
		if (arr[mid] >= arr[left])
			left = mid;
		// ����м���������ֵС���ұ�������ֵ�������midָ�������˵ڶ������������
		// ��С���ֻ���ǰ�棬�ƶ���ָ�뵽֮��ָ��
		if (arr[mid] <= arr[right])
			right = mid;
	}

	return arr[mid];
}

int MinInOrder(vector<int>& arr, int left, int right)
{
	int result = arr[left];
	for (int i = left + 1; i <= right; ++i)
	{
		if (result > arr[i])
			result = arr[i];
	}
	return result;
}

int main()
{
	vector<int> arr;

	int n;
	cout << "��������Ĵ�С: ";
	cin >> n; // ���м�������

	cout << "������ת����: ";

	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		arr.push_back(val);
	}

	cout << "��ת�������С����Ϊ: " << MinNumberInRotatedArray(arr) << endl;

	return 0;
}