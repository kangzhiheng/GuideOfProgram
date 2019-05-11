//-----------------------------------------------------------------------------
// 文 件 名: 03_01_找出数组中重复的数字.cpp
// 作    者：adoredee
// 创建时间：2019.04.14
// 描    述：不修改数组找出重复的数字
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题3（二）：不修改数组找出重复的数字
// 题目：在一个长度为n+1的数组里的所有数字都在1到n的范围内，所以数组中至
//		少有一个数字是重复的。请找出数组中任意一个重复的数字，但不能修改输入的
//		数组。例如，如果输入长度为8的数组{2, 3, 5, 4, 3, 2, 6, 7}，那么对应的
//      输出是重复的数字2或者3。

// 思路：二分法，统计每一对半区间的里的数字个数，如果区间里每个数字出现的个数之和大于区间里的数字的个数，则有重复。
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 统计区间内的每个数字出现的次数之和
int countRange(const vector<int>& numbers, int start, int end)
{
	// 异常处理
	if (numbers.empty())    // 如果数组为空
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

	// 异常处理
	if (numbers.empty() || length <= 0)
		return -1;

	int start = 1;
	int end = length - 1;

	while (end >= start)
	{
		int middle = start + ((end - start) >> 1);
		int count = countRange(numbers, start, middle);

		if (end == start)    // 结束条件
		{
			if (count > 1)    // 重复出现的次数大于1
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