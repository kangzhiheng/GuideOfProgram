//-----------------------------------------------------------------------------
// 文 件 名: 53_02_0~n-1中缺失的数字.cpp
// 作    者：adoredee
// 创建时间： 2019.07.30
// 描    述：数字在排序数组中出现的次数
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题53（三）：数组中数值和下标相等的元素
// 题目：假设一个单调递增的数组里的每个元素都是整数并且是唯一的。请编程实
//      现一个函数找出数组中任意一个数值等于其下标的元素。例如，在数组{-3, -1,
//      1, 3, 5}中，数字3和它的下标相等。

#include <iostream>
#include <vector>

using namespace std;

int FindTheIndexEqualNum(vector<int>& aArr)
{
	// 异常检测
	if (aArr.empty() || aArr.size() <= 0)
	{
		cout << "无合适数字" << endl;
		return -1;
		exit(1);    // 不正常退出程序
	}

	int left = 0;
	int right = aArr.size() - 1;

	while (left <= right)
	{
		/*
		关于mid求法有两种:
		1. mid = (left + right) / 2;
		2. mid = left + (right - left) / 2;
		其实,
		(left + right) / 2 = (left + left + right - left) / 2 = left + (right - left) / 2
		为什么会出现第二种写法呢？是因为 加法 可能会造成计算机内存溢出，所以第二种使用更为保险
		另外，
		除法在计算机中实际上是一种唯一操作，所以将 / 2 写成 >> 1，因为位运算使得计算机运算效率较快
		*/
		int mid = (left + right) >> 1;

		if (aArr[mid] == mid)
			return aArr[mid];
		else if (aArr[mid] > mid)
			right = mid - 1;
		else
			left = mid + 1;
	}
	
	cout << "无合适数字" << endl;
	exit(1);
	return -1;
	
}

int main()
{
	vector<int> aArr = { -3, -1, 1, 3, 5 };

	int nNum = FindTheIndexEqualNum(aArr);

	cout << "该数组中数值和下标相等的元素为：" << nNum << endl;

	return 0;
}