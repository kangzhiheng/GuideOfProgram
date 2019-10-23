//-----------------------------------------------------------------------------
// 文 件 名: 55_跳跃游戏.cpp
// 作    者：adoredee
// 创建时间：2019.09.16
// 描    述：跳跃游戏
// 版    本：
// 链    接：https://leetcode-cn.com/problems/jump-game/solution/tiao-yue-you-xi-by-leetcode/
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

#include <iostream>
#include <vector>

using namespace std;

bool canJump(vector<int>& nums)
{
	if (nums.empty())
		return true;

	int lastPos = nums.size() - 1;

	for (int i = nums.size() - 1; i >= 0; --i)
	{
		if (i + nums[i] >= lastPos)
			lastPos = i;
	}

	return lastPos == 0;
}

int main()
{
	int N;
	cin >> N;
	vector<int> nums(N);

	for (int i = 0; i != N; ++i)
		cin >> nums[i];

	bool flags = canJump(nums);
	if (flags)
		cout << "true" << endl;
	else
		cout << "false" << endl;

}