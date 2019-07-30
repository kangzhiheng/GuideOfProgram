//-----------------------------------------------------------------------------
// 文 件 名: 53_02_0~n-1中缺失的数字.cpp
// 作    者：adoredee
// 创建时间： 2019.07.30
// 描    述：数字在排序数组中出现的次数
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题53（二）：0到n-1中缺失的数字
// 题目：一个长度为n-1的递增排序数组中的所有数字都是唯一的，并且每个数字
//      都在范围0到n-1之内。在范围0到n-1的n个数字中有且只有一个数字不在该数组
//      中，请找出这个数字。

#include <iostream>
#include <vector>

using namespace std;

// 二分法
int FindTheDiffNum(vector<int>& aArr)
{
	// 异常判断
	if (aArr.empty() || aArr.size() <= 0)
		return -1;

	int start = 0;
	int end = aArr.size() - 1;


	while (start <= end)
	{
		int mid = (start + end) >> 1;

		if (aArr[mid] != mid)
		{
			// 1. 如果aArr[mid] != mid 且 aArr[mid - 1] == mid - 1，则mid处即为缺失的数字
			// 2. 如果aArr[mid] != mid 且 mid = 0，说明在数组的开始处即为缺失的数字
			if (mid == 0 || aArr[mid - 1] == mid - 1)
				return mid;
			end = mid - 1;
		}
		else
			start = mid + 1;
	}

	if (start == aArr.size())
		return aArr.size();

	return -1;

}

int main()
{
	vector<int> aArr = { 0, 1, 2, 3, 4, 5, 7 };

	int nNum = FindTheDiffNum(aArr);

	cout << "0 ~ " << aArr.size() - 1 << "中缺失的数字为：" << nNum << endl;

	return 0;
}