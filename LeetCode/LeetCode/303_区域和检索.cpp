//-----------------------------------------------------------------------------
// 作    者：adoredee
// 创建时间： 2020.02.03
// 描    述：打家劫舍
// 版    本：
// 链    接：https://leetcode-cn.com/problems/range-sum-query-immutable/
//-----------------------------------------------------------------------------
// Copyright (C) 2020 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------		 

#include <iostream>
#include <vector>

using namespace std;

// 思路：因为要多次调用sumRange()函数，直接累加会超出内存
// 因此 sumRange[i, j] = sumRange[0, j] - sumRange[0, i - 1]

class NumArray
{
public:
	vector<int> DP;
	// 构造函数初始化
	NumArray(vector<int>& nums)
	{
		DP.resize(nums.size() + 1, 0);    // DP[0] = 0 
		int tmp_sum = 0;
		for (int i = 0; i != nums.size(); ++i)
		{
			tmp_sum += nums[i];
			DP[i + 1] = tmp_sum;
		}
		
	}

	int sumRange(int i, int j)
	{
		return DP[j + 1] - DP[i];
	}

	
};

int main()
{
	vector<int> nums = { -2, 0, 3, -5, 2, -1 };
	NumArray* obj = new NumArray(nums);
	int sums = obj->sumRange(0, 2);
	cout << sums << endl;

	return 0;
}