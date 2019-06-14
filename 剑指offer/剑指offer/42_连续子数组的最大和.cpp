//-----------------------------------------------------------------------------
// 文 件 名: 42_连续子数组的最大和.cpp
// 作    者：adoredee
// 创建时间： 2019.06.14
// 描    述：连续子数组的最大和
// 版    本：
//-----------------------------------------------------------------------------

// 面试题42：连续子数组的最大和
// 题目：输入一个整型数组，数组里有正数也有负数。数组中一个或连续的多个整
//      数组成一个子数组。求所有子数组的和的最大值。要求时间复杂度为O(n)。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool g_InvalidInput = false;    // 区别非法数组的

int GreatestSumOfSubarray_Myself(vector<int>& arr)
{
	if (arr.empty() || arr.size() <= 0)
	{
		return 0;
		g_InvalidInput = true;
		cout << "非法数组!";
	}	

	g_InvalidInput = false;

	int sum_num = arr[0];
	int max_subarray = arr[0];

	for (int i = 1; i < arr.size(); ++i)
	{
		// 从第二个元素开始，比较当前子序和与当前元素
		sum_num = max(sum_num + arr[i], arr[i]);
		// 如果当前子序和大于历史最大子序和，则替换
		if (sum_num > max_subarray)
			max_subarray = sum_num;
	}

	return max_subarray;
}

int GreatestSumOfSubarray_Book(vector<int>& arr)
{
	if (arr.empty() | arr.size() <= 0)
	{
		return 0;
		g_InvalidInput = true;
		cout << "非法数组!";
	}

	g_InvalidInput = false;

	int nCurNum = arr[0];
	int nGreatNum = arr[0];

	for (int i = 1; i < arr.size(); i++)
	{
		if (nCurNum <= 0)
			nCurNum = arr[i];
		else
			nCurNum += arr[i];

		if (nCurNum > nGreatNum)
			nGreatNum = nCurNum;
	}

	return nGreatNum;
}

int main()
{
	vector<int> arr;

	cout << "请输入一个数组：";
	int val;
	while (scanf("%d", &val))
		arr.emplace_back(val);    // 换行，按下ctrl+x停止输入

	//for (int i = 0; i < arr.size(); ++i)
	//	cout << arr[i] << " ";
	//cout << endl;
	cout << "该序列的最大子序列之和为：" << endl;
	int Max_Numsubarray_1 = GreatestSumOfSubarray_Myself(arr);
	cout << "1. 我自己的方法：" << Max_Numsubarray_1 << endl;

	int Max_Numsubarray_2 = GreatestSumOfSubarray_Book(arr);
	cout << "2. <<剑指offer>>上的方法（修改）：" << Max_Numsubarray_2 << endl;

	return 0;
}