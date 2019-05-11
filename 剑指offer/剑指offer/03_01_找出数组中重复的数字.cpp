//-----------------------------------------------------------------------------
// 文 件 名: 03_01_找出数组中重复的数字.cpp
// 作    者：adoredee
// 创建时间：2019.04.10
// 描    述：找出数组中重复的数字
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
//      也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
//      那么对应的输出是重复的数字2或者3。

#include <iostream>

using namespace std;

bool duplicate(int number[], int length, int* duplication)
{
	if (number == nullptr || length <= 0)    // 如果数组为空或者数组长度小于0
		return false;

	for (size_t i = 0; i != length; i++)
	{
		if (number[i] < 0 || number[i] > length - 1)
			return false;
	}

	for (size_t i = 0; i != length; i++)
	{
		while (number[i] != i)
		{
			if (number[i] == number[number[i]])
			{
				*duplication = number[i];
				return true;
			}
			else    // 交换
			{
				int temp = number[i];
				number[i] = number[temp];
				number[temp] = temp;
			}
		}
	}
	return false;
}

int main()
{
	int a[] = { 4, 0, 1, 2, 3 };
	int length = sizeof(a) / sizeof(a[0]);

	int x;
	cout << duplicate(a, length, &x) << endl;

	//cout << length << endl;

	return 0;
}