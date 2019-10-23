//-----------------------------------------------------------------------------
// 作    者：adoredee
// 创建时间：2019.04.23
// 描    述：最小子序和
//-----------------------------------------------------------------------------
/*
给定一个整数数组 nums ，找到一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

示例:

输入: [-2,1,-3,4,-1,2,1,-5,4],
输出: 6
解释: 连续子数组 [4,-1,2,1] 的和最大，为 6。
进阶:

如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的分治法求解。
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int maxSubArray(vector<int>& nums)
{
	// 异常处理 —— 数组为空或者数组大小小于等于0
	if (nums.empty() || nums.size() <= 0)
	{
		return -1;
	}

	int sum = nums[0], max_sum = nums[0];
	for (int i = 1;	i < nums.size(); i++)
	{
		// 如果加上现在的nums[i]的累加值比nums[i]还要小，则舍去之前的累加和
		sum = max(sum + nums[i], nums[i]);
		if (sum > max_sum)
			max_sum = sum;
	}

	return max_sum;

}

int main()
{
	vector<int> arr = {-2, -1,-3, -4, -1, -2, -1, -5, -4};

	cout << "最大子序列和为" << maxSubArray(arr) << endl;

	return 0;
}