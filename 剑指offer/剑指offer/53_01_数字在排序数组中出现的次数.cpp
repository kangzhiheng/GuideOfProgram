//-----------------------------------------------------------------------------
// 文 件 名: 53_01_数字在排序数组中出现的次数.cpp
// 作    者：adoredee
// 创建时间： 2019.07.24
// 描    述：数字在排序数组中出现的次数
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题53（一）：数字在排序数组中出现的次数
// 题目：统计一个数字在排序数组中出现的次数。例如输入排序数组{1, 2, 3, 3,
//      3, 3, 4, 5}和数字3，由于3在这个数组中出现了4次，因此输出4。

/*
    方法一：哈希表（O(n)）
	方法二：二分法（O(logn)）
*/


#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// 方法一：哈希表
size_t FindCountsOfANumber_Hash(vector<size_t>& arr, size_t num)
{
	// 异常处理
	if (arr.empty() || arr.size() <= 0)
		throw "数组为空";

	unordered_map<size_t, size_t> arrhash;   // 数字与出现的次数
	size_t counts = 0;    // num数字在数组中出现的次数
	size_t k;
	for (size_t i = 0; i < arr.size(); ++i)
	{
		if (arr[i] == num)
		{
			arrhash[arr[i]]++;    // 统计num这个数字出现的次数
			k = i;     // 记录下标
		}
	}
	
	// 哈希表arrhash里只有一个元素
	if (!arrhash.empty())
		return arrhash[arr[k]];
	else
		throw "无此数字";
}

// 二分法

size_t GetFirstNumPos(vector<size_t>&arr, size_t num, size_t start, size_t end)
{
	if (start > end)
		return -1;

	size_t midIndex = (start + end) / 2;
	size_t midData = arr[midIndex];

	if (midData == num)
	{
		// 如果还有效且midIndex-1处的元素不等于num，则midIndex为num的在数组中出现的第一个位置
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
	// 异常检测
	if (arr.empty() || arr.size() < 0)
		throw "数组为空";

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

	cout << "哈希表法：\t" << counts_1 << endl;
	cout << "二分法：\t" << counts_2 << endl;

	return 0;
}