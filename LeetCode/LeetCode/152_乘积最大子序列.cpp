//-----------------------------------------------------------------------------
// 作    者：adoredee
// 创建时间： 2020.02.12
// 描    述：乘积最大子序列
// 版    本：
// 链    接：https://leetcode-cn.com/problems/maximum-product-subarray/
// Copyright (C) 2020 Shanghai Jiao Tong University

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxProduct(vector<int>& nums)
{
	int maxnums = nums[0];
	int minnums = nums[0];
	int _max = nums[0];

	for (int i = 1; i < nums.size(); ++i)
	{
		int temp_max = maxnums * nums[i];
		int temp_min = minnums * nums[i];
		maxnums = max(max(temp_max, temp_min), nums[i]);
		minnums = min(min(temp_max, temp_min), nums[i]);
		_max = max(maxnums, _max);
	}

	return _max;
}

int main()
{
	vector<int> nums = { -2, -3, -2,- 4 };
	int maxnum = maxProduct(nums);
	cout << maxnum << endl;
	return 0;
}