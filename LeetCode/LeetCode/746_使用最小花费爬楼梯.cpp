//-----------------------------------------------------------------------------
// 作    者：adoredee
// 创建时间： 2020.02.06
// 描    述：使用最小花费爬楼梯
// 版    本：
// 链    接：https://leetcode-cn.com/problems/min-cost-climbing-stairs/
//-----------------------------------------------------------------------------
// Copyright (C) 2020 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCostClimbingStairs(vector<int>& cost)
{
	// dp[i] 表示到索引为 i 位置再选择向上爬一共需要的体力开销。
	vector<int> DP(cost.size());
	DP[0] = cost[0];
	DP[1] = cost[1];

	int len = cost.size();
	for (int i = 2; i < len; ++i)
		DP[i] = min(DP[i - 1], DP[i - 2]) + cost[i];

	return min(DP[len - 1], DP[len - 2]);
}

int main()
{
	vector<int> cost = { 0, 1, 1, 0 };

	int val = minCostClimbingStairs(cost);

	cout << val << endl;

	return 0;
}