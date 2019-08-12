// 文 件 名: 63_股票的最大利润.cpp
// 作    者：adoredee
// 创建时间： 2019.08.11
// 描    述：股票的最大利润
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题63：股票的最大利润
// 题目：假设把某股票的价格按照时间先后顺序存储在数组中，请问买卖交易该股
//      票可能获得的利润是多少？例如一只股票在某些时间节点的价格为{9, 11, 8, 5,
//      7, 12, 16, 14}。如果我们能在价格为5的时候买入并在价格为16时卖出，则能
//      收获最大的利润11。

#include <iostream>
#include <vector>

using namespace std;

int TheMaxDiff(vector<int>& aNum)
{
	// 异常判断
	if (aNum.empty() || aNum.size() < 2)
		return 0;

	int nSmall = aNum[0];
	int nDiff = aNum[1] - nSmall;

	for (size_t i = 2; i < aNum.size(); ++i)
	{
		if (aNum[i - 1] < nSmall)
			nSmall = aNum[i - 1];

		int nCurrentDiff = aNum[i] - nSmall;
		if (nCurrentDiff > nDiff)
			nDiff = nCurrentDiff;
	}

	return nDiff;
}

int main()
{
	vector<int> aNumber = { 9, 11, 8, 5, 7, 12, 16, 14 };

	cout << "股票价格为：";
	for (size_t i = 0; i < aNumber.size(); ++i)
		cout << aNumber[i] << " ";
	cout << endl;

	int nDiff = TheMaxDiff(aNumber);

	cout << "此时的最大利润为：" << nDiff << endl;

	return 0;
}