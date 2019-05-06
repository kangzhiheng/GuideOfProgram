//-----------------------------------------------------------------------------
// 文 件 名: 14_剪绳子.cpp
// 作    者：adoredee
// 创建时间：2019.05.06
// 描    述：反转链表
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题14：剪绳子
// 题目：给你一根长度为n绳子，请把绳子剪成m段（m、n都是整数，n>1并且m≥1）。
//      每段的绳子的长度记为k[0]、k[1]、……、k[m]。k[0]*k[1]*…*k[m]可能的最大乘
//      积是多少？例如当绳子的长度是8时，我们把它剪成长度分别为2、3、3的三段，此
//      时得到最大的乘积18。

#include <iostream>

using namespace std;

int MaxProductAfterCuttingRope_DP(int length)
{
	// 特殊情况处理
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	int* product = new int[length + 1];
	// 当绳子长度大于等于4时，需要辅助条件，并不代表存放的最大值
	/* 例如，当绳子长度为4时，可能的情况有：
	   1. 1和3，1 x 3 = 3;
	   2. 2和2，2 x 2 = 4;
	   3. 1,1和2，1 x 1 x 2 = 2;
	   4. 1,1,1和1，1 x 1 x 1 x 1 = 1;
	   如若再推断几次，可以得出结论：
	   1. 绳子切割后的最终结果，不可能存在长度为1的子段。
	*/
	product[0] = 0;
	product[1] = 1;
	product[2] = 2;
	product[3] = 3;

	int max = 0;

	for (int i = 4; i <= length; ++i)
	{
		for (int j = 1; j <= i / 2; ++j)
		{
			int products = product[j] * product[i - j];
			if (products > max)
				max = products;

			product[i] = max;
		}
	}

	max = product[length];
	delete[] product;

	return max;
}

int MaxProductAfterCuttingRope_Greedy(int length)
{
	/*
	根据经验和推导，可以得出：
	    绳子切割后的最终结果，只可能存在三种长度的子段(长度为1，2，3)。
		因此如作者所说，尽可能使长度为3的绳子多一些，其次使长度为2的绳子多一些
	*/
	// 特殊情况处理
	if (length < 2)
		return 0;
	if (length == 2)
		return 1;
	if (length == 3)
		return 2;

	// 尽可能使长度为3的绳子多一些
	int length_3 = length / 3;

	// 特殊情况，如果长度为4，则更好的方法是把绳子剪成长度为2的两段，因为 2 x 2 > 3 x 1
	if (length - length_3 * 3 == 1)
		length_3 -= 1;

	// 统计长度为2的绳子出现的次数
	int length_2 = (length - length_3 * 3) / 2;
	
	return (int)(pow(3, length_3)) * (int)(pow(2, length_2));
}

int main()
{
	cout << "请输入一个绳子的长度(为一个整数): ";
	int value;
	cin >> value;

	int ProductMax_DP = MaxProductAfterCuttingRope_DP(value);
	cout << "动态规划 —— 子段最大乘积为: " << ProductMax_DP << endl;

	int ProductMax_Greedy = MaxProductAfterCuttingRope_Greedy(value);
	cout << "贪婪算法 —— 子段最大乘积为: " << ProductMax_Greedy << endl;

	return 0;
}