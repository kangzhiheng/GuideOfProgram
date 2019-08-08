// 文 件 名: 56_01_数组中只出现一次的两个数字.cpp
// 作    者：adoredee
// 创建时间： 2019.08.04
// 描    述：数组中只出现一次的两个数字
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题56（一）：数组中只出现一次的两个数字
// 题目：一个整型数组里除了两个数字之外，其他的数字都出现了两次。请写程序
//      找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。

// 思路：位运算

#include <iostream>
#include <vector>

using namespace std;

bool IsBit_1(int num, size_t indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}

size_t FindTheFirstBit_1(int num)
{
	int indexBit = 0;
	while (((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
	{
		num = num >> 1;
		++indexBit;
	}

	return indexBit;
}

vector<int> FindNumsAppearOnce(vector<int>& aArr)
// int FindNumsAppearOnce(vector<int>& aArr)
{
	// 异常处理
	/*if (aArr.empty() || aArr.size() < 2)
		return aArr;*/

	int resultExclusiveOR = 0;
	// 循环异或，得出结果
	for (int i = 0; i < aArr.size(); ++i)
		resultExclusiveOR ^= aArr[i];
	// 找出异或结果最右边1出现的位置
	size_t indexOf_1 = FindTheFirstBit_1(resultExclusiveOR);

	vector<int> TheDiffTwoNum(2);

	for (int i = 0; i < aArr.size(); ++i)
	{
		// 因为这两个数字不相同，故在某一位的数字也不同，因此在这一位异或的结果为1，
		// 根据这个特点，该数组可被分为两组，再分别异或，每一组留下的即为整个数组不同的两个数字。
		if (IsBit_1(aArr[i], indexOf_1))    // 将aArr[i] 向右移动 indexOf_1 位，判断该位与1是否相同，是的分为一组
			TheDiffTwoNum[0] ^= aArr[i];
		else
			TheDiffTwoNum[1] ^= aArr[i];
	}

	return TheDiffTwoNum;
}

int main()
{
	vector<int> aArr = { 2, 4, 3, 6, 3, 2, 5, 5 };

	vector<int> AppearOnce = FindNumsAppearOnce(aArr);

	cout << "数组中只出现一次的两个数字：";
	for (int i = 0; i < AppearOnce.size(); ++i)
		cout << AppearOnce[i] << " ";
	cout << endl;

	return 0;
}