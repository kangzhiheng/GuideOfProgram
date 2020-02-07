//-----------------------------------------------------------------------------
// ��    �ߣ�adoredee
// ����ʱ�䣺 2020.02.03
// ��    ������ҽ���
// ��    ����
// ��    �ӣ�https://leetcode-cn.com/problems/house-robber/
//-----------------------------------------------------------------------------
// Copyright (C) 2020 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int rob(vector<int>& nums)
{
	// �쳣�ж�
	if (nums.size() <= 0 || nums.empty())
		return {};

	if (nums.size() == 1)
		return nums[0];

	if (nums.size() == 2)
		return max(nums[0], nums[1]);

	// DP[i]��ʾ�ڵ�i��λ�õ����ֵ
	// DP[i] = max(DP[i] + DP[i-2], DP[i-1])
	vector<int> DP(nums.size());
	DP[0] = nums[0];
	DP[1] = max(nums[0], nums[1]);
	for (int i = 2; i != nums.size(); ++i)
		DP[i] = max(nums[i] + DP[i - 2], DP[i - 1]);

	return DP[nums.size() - 1];
}
int main()
{
	vector<int> nums = { 2, 1, 1, 2 };
	int robs = rob(nums);
	cout << robs << endl;

	return 0;
}