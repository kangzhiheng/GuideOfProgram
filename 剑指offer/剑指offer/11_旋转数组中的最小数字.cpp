//-----------------------------------------------------------------------------
// 文 件 名: 11_转数组中的最小数字.cpp
// 作    者：adoredee
// 创建时间：2019.04.27
// 描    述：转数组中的最小数字
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
//      输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
//      {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。

/*
    思路：二分法
*/
#include <iostream>
#include <vector>

using namespace std;

int MinInOrder(vector<int>& arr, int left, int right);

int MinNumberInRotatedArray(vector<int> arr)
{
	// 异常判断
	if (arr.empty() || arr.size() <= 0)
		throw new exception("非法输入");

	int left = 0;    // 左边递增数组的指针
	int right = arr.size() - 1;  // 右边递增数组的指针
	int mid = left;

	// 如果第一个数字小于最后一个数字，那么第一个数字就是旋转数组的最小数字，即原数组本身也是旋转数组
	while (arr[left] >= arr[right])
	{
		// 结束条件，如果左索引在第一个递增数组的结束位置，右索引在第二个递增数组的起始位置，
		// 即右索引值在左索引的后一个位置，则最小数字就是在右索引的位置
		if (right - left == 1)
		{
			mid = right;
			break;
		}

		mid = (right + left) / 2;
		
		// 如果下标left、right、mid处的值都相等，
		// 则只能顺序查找
		if (arr[left] == arr[right] && arr[left] == arr[mid])
			return MinInOrder(arr, left, right);

		// 如果中间索引处的值大于左边索引的值，则表明mid指针在第一个递增数组里，
		// 最小数字还在后面，则移动左指针到中间指针
		if (arr[mid] >= arr[left])
			left = mid;
		// 如果中间索引处的值小于右边索引的值，则表明mid指针来到了第二个递增数组里，
		// 最小数字还在前面，移动右指针到之间指针
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
	cout << "输入数组的大小: ";
	cin >> n; // 共有几个数组

	cout << "输入旋转数组: ";

	for (int i = 0; i < n; i++)
	{
		int val;
		cin >> val;
		arr.push_back(val);
	}

	cout << "旋转数组的最小数字为: " << MinNumberInRotatedArray(arr) << endl;

	return 0;
}