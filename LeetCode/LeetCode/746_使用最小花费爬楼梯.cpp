//-----------------------------------------------------------------------------
// ��    �ߣ�adoredee
// ����ʱ�䣺 2020.02.06
// ��    ����ʹ����С������¥��
// ��    ����
// ��    �ӣ�https://leetcode-cn.com/problems/min-cost-climbing-stairs/
//-----------------------------------------------------------------------------
// Copyright (C) 2020 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minCostClimbingStairs(vector<int>& cost)
{
	// dp[i] ��ʾ������Ϊ i λ����ѡ��������һ����Ҫ������������
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