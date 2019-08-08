// 文 件 名: 56_01_数组中唯一只出现一次的数字.cpp
// 作    者：adoredee
// 创建时间： 2019.08.04
// 描    述：数组中唯一只出现一次的数字
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题56（二）：数组中唯一只出现一次的数字
// 题目：在一个数组中除了一个数字只出现一次之外，其他数字都出现了三次。请
//      找出那个只出现一次的数字。

#include <iostream>
#include <vector>

using namespace std;

int FindNumAppearingOnce(vector<int>& aArr)
{
	// 异常判断
	if (aArr.empty() || aArr.size() < 1)
		throw new exception("Invalid input");

	int bitSum[32] = { 0 };    // 32 = 8 * 4;  int型是4个字节，每个字节是8位		
	for (int i = 0; i < aArr.size(); ++i)
	{
		int bitMask = 1;
		for (int j = 31; j >= 0; --j)
		{
			// 利用bitMask，是因为与aArr[i]进行位运算
			int bit = aArr[i] & bitMask;
			// bit为0说明aArr[i]对应的位为0，0 & 1 = 0，不为0，则进行if语句
			if (bit != 0)
				bitSum[j] += 1;    // 对应位累加
			bitMask = bitMask << 1;    // 左移一位，统计上一位
		}
	}

	int result = 0;
	for (int i = 0; i < 32; ++i)
	{
		result = result << 1;
		result += bitSum[i] % 3;
	}

	return result;

}

int main()
{
	vector<int> aNumber = { 2,3,2,2,4,4,4 };
	int nResult = FindNumAppearingOnce(aNumber);
	cout << "数组中唯一只出现一次的数字为：" << nResult << endl;

	return 0;
}