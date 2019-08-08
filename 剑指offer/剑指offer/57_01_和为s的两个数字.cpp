// 文 件 名: 57_01_和为s的两个数字.cpp
// 作    者：adoredee
// 创建时间： 2019.08.05
// 描    述：和为s的两个数字
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题57（一）：和为s的两个数字
// 题目：输入一个递增排序的数组和一个数字s，在数组中查找两个数，使得它们
//      的和正好是s。如果有多对数字的和等于s，输出任意一对即可。

#include <iostream>
#include <vector>

using namespace std;

void FindThePairSumIs_s(vector<int> aNum, int nGivenSum)
{
	// 异常判断
	if (aNum.empty() || aNum.size() <= 0)
		throw new exception("Invalid Input!");

	int nLeft = 0;
	int nRight = aNum.size() - 1;

	bool flag = false;    // 是否找到
	long long nSum = 0;

	while (nLeft < nRight)
	{
		nSum = aNum[nLeft] + aNum[nRight];
		if (nSum == nGivenSum)
		{
			flag = true;
			cout << aNum[nLeft] << " " << aNum[nRight] << endl;
			--nRight;    // 严格递增的情况下
		}

		else if (nSum > nGivenSum)
			--nRight;
		else
			++nLeft;
	}

	if (flag == false)
		cout << "无满足此条件的数对！" << endl;
}

int main()
{
	vector<int> aArr = { 1, 2, 3, 4, 7, 11, 12, 15 };
	cout << "原数组为：";
	for (int i = 0; i != aArr.size(); ++i)
		cout << aArr[i] << " ";
	cout << endl;

	cout << "输入一个整数，表示该数组中某两个元素的和: ";
	int nGivenSum;
	cin >> nGivenSum;

	cout << "满足和为" << nGivenSum << "两个数为: " << endl;
	FindThePairSumIs_s(aArr, nGivenSum);

	return 0;
}