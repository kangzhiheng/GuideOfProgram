//-----------------------------------------------------------------------------
// 作    者：adoredee
// 创建时间： 2020.01.15
// 描    述：子集
// 版    本：
// 链    接：https://leetcode-cn.com/problems/reverse-integer/
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> subsets(vector<int>& nums)
{
	// 异常检测
	if (nums.empty() || nums.size() <= 0)
		return {};

	int nLength = nums.size();
	int N = pow(2, nums.size());
	vector<vector<int>> arr(N);

	for (int i = 1; i <= N; ++i)
	{
		int temp = 0x01;
		for (int j = 0; j < nLength; ++j)
		{
			if (i & temp)
				arr[i - 1].push_back(nums[j]);
			temp = temp << 1;
		}
	}

	return arr;
}

int main()
{
	vector<int> nums = { 1, 2, 3 };

	vector<vector<int>> arr = subsets(nums);

	for (int i = 0; i < arr.size(); ++i)
	{
		cout << i + 1 << ": " << "\t";
		for (int j = 0; j < arr[i].size(); ++j)
			cout << arr[i][j] << " ";
		cout << endl;
	}

	return 0;
}