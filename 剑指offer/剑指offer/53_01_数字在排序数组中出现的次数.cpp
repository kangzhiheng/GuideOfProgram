//-----------------------------------------------------------------------------
// �� �� ��: 53_01_���������������г��ֵĴ���.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.07.24
// ��    �������������������г��ֵĴ���
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������53��һ�������������������г��ֵĴ���
// ��Ŀ��ͳ��һ�����������������г��ֵĴ���������������������{1, 2, 3, 3,
//      3, 3, 4, 5}������3������3����������г�����4�Σ�������4��

/*
    ����һ����ϣ��O(n)��
	�����������ַ���O(logn)��
*/


#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// ����һ����ϣ��
size_t FindCountsOfANumber_Hash(vector<size_t>& arr, size_t num)
{
	// �쳣����
	if (arr.empty() || arr.size() <= 0)
		throw "����Ϊ��";

	unordered_map<size_t, size_t> arrhash;   // ��������ֵĴ���
	size_t counts = 0;    // num�����������г��ֵĴ���
	size_t k;
	for (size_t i = 0; i < arr.size(); ++i)
	{
		if (arr[i] == num)
		{
			arrhash[arr[i]]++;    // ͳ��num������ֳ��ֵĴ���
			k = i;     // ��¼�±�
		}
	}
	
	// ��ϣ��arrhash��ֻ��һ��Ԫ��
	if (!arrhash.empty())
		return arrhash[arr[k]];
	else
		throw "�޴�����";
}

// ���ַ�

size_t GetFirstNumPos(vector<size_t>&arr, size_t num, size_t start, size_t end)
{
	if (start > end)
		return -1;

	size_t midIndex = (start + end) / 2;
	size_t midData = arr[midIndex];

	if (midData == num)
	{
		// �������Ч��midIndex-1����Ԫ�ز�����num����midIndexΪnum���������г��ֵĵ�һ��λ��
		if (midIndex > 0 && arr[midIndex - 1] != num || midIndex == 0)
			return midIndex;
		else
			end = midIndex - 1;
	}
	else if (midData > num)
		end = midIndex - 1;
	else
		start = midIndex + 1;

	return GetFirstNumPos(arr, num, start, end);
}

size_t GetLastNumPos(vector<size_t>& arr, size_t num, size_t start, size_t end)
{
	if (start > end)
		return -1;

	size_t midIndex = (start + end) / 2;
	size_t midData = arr[midIndex];

	if (midData == num)
	{
		if (midIndex < arr.size() - 1 && arr[midIndex + 1] != num || midIndex == arr.size() - 1)
			return midIndex;
		else
			start = midIndex + 1;
	}
	else if (midData < num)
		start = midIndex + 1;
	else
		end = midIndex - 1;

	return GetLastNumPos(arr, num, start, end);
}

size_t FindCountsOfANumber_Dichotomy(vector<size_t>& arr, size_t num)
{
	// �쳣���
	if (arr.empty() || arr.size() < 0)
		throw "����Ϊ��";

	size_t start = 0;
	size_t end = arr.size() - 1;

	size_t FirstNumPos = GetFirstNumPos(arr, num, start, end);
	size_t LastNumPos = GetLastNumPos(arr, num, start, end);

	return LastNumPos - FirstNumPos + 1;
}

size_t main()
{
	vector<size_t> arr = { 1, 2, 3, 3, 3, 3, 3, 5 };
	size_t num = 3;

	size_t counts_1 = FindCountsOfANumber_Hash(arr, num);
	size_t counts_2 = FindCountsOfANumber_Dichotomy(arr, num);

	cout << "��ϣ����\t" << counts_1 << endl;
	cout << "���ַ���\t" << counts_2 << endl;

	return 0;
}