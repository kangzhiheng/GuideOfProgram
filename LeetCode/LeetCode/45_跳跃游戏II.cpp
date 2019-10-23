//-----------------------------------------------------------------------------
// 文 件 名: 45_跳跃游戏II.cpp
// 作    者：adoredee
// 创建时间： 2019.09.16
// 描    述：跳跃游戏II
// 版    本：
// 链    接：https://leetcode-cn.com/problems/jump-game-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-10/
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int jump(vector<int>& nums)
{
	if (nums.empty() || nums.size() == 1)
		return 0;

	int nLen = nums.size();
	int reachRange = 0;
	int nextReachRange = nums[0];
	int steps = 0;
	for (int i = 0; i < nLen; ++i)
	{
		nextReachRange = max(i + nums[i], nextReachRange);
		if (nextReachRange >= nLen - 1)
			return steps + 1;
		if (i == reachRange)
		{
			steps++;
			reachRange = nextReachRange;
		}
	}

	return steps;
}

/*
    思路：
	比如2 3 1 1 4
	如果要跳到4，则需要从3开始跳；
	更新边界，如果要跳到3，从2开始跳即可
	即每次都要更新边界
	如果是全1的数组，会超时
*/
int jump_(vector<int>& nums)
{
	if (nums.empty() || nums.size() == 1)
		return 0;
	int nPos = nums.size() - 1;     // 要找的位置
	int steps = 0;
	while (nPos != 0)    // 确保有结果
	{
		for (int i = 0; i < nPos; ++i)
		{
			if (i + nums[i] >= nPos)    // 跳的范围是否涵盖了边界
			{
				nPos = i;    // 更新边界
				++steps;
			}
		}
	}

	return steps;
}

int main()
{
	int N;
	cin >> N;
	vector<int> nums(N);
	for (int i = 0; i != N; i++)
		cin >> nums[i];

	int index = jump(nums);

	cout << index << endl;

}