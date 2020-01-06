//-----------------------------------------------------------------------------
// 文 件 名: 121_买卖股票的最佳时机.cpp
// 作    者：adoredee
// 创建时间： 2020.01.06
// 描    述：买卖股票的最佳时机
// 版    本：
// 链    接：https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock/submissions/
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int maxProfit(vector<int>& prices)
{
	// 异常检测
	if (prices.empty() || prices.size() <= 1)
		return 0;

	int last = 0, maxValue = 0;

	for (int i = 1; i != prices.size(); ++i)
	{
		last = max(0, last + prices[i] - prices[i - 1]);
		maxValue = max(last, maxValue);
	}

	return maxValue;
}
int main()
{
	vector<int> arr = { 7,6,4,3,1 };
	cout << maxProfit(arr) << endl;

	return 0;
}