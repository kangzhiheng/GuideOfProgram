//-----------------------------------------------------------------------------
// 文 件 名: 15_三数之和.cpp
// 作    者：adoredee
// 创建时间： 2019.09.15
// 描    述：三数之和
// 版    本：
// 链    接：https://leetcode-cn.com/problems/3sum/
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

// 第一种方法：不用set集合去重
vector<vector<int>> threeSum(vector<int>& nums)
{
	sort(nums.begin(), nums.end());
	
	// 异常检测
	if (nums.empty() || nums.size() < 3 || nums.front() > 0 || nums.back() < 0)
		return {};

	vector<vector<int>> arr;

	int nLen = nums.size();

	for (int left = 0; left < nLen - 2; ++left)
	{
		// 三数之中最小的数大于0，没戏
		if (nums[left] > 0)
			break;

		if (left > 0 && nums[left] == nums[left - 1])
			continue;

		for (int mid = left + 1, right = nLen - 1; mid < right;)
		{
			// 最小的和最大的数同号，无解
			if (nums[left] * nums[right] > 0)
				break;
			int sums = nums[left] + nums[mid] + nums[right];
			if (sums == 0)
			{
				arr.push_back(vector<int>{nums[left], nums[mid], nums[right]});
				mid++;
				right--;
				while (mid < right && nums[mid] == nums[mid - 1])
					mid++;
				while (mid < right && nums[right] == nums[right + 1])
					right--;
				
			}
			else if (sums > 0)
			{
				--right;
			}
			else
			{
				++mid;
			}
		}
	}

	return arr;
}

// 利用set集合去重
vector<vector<int>> threeSum_set(vector<int>& nums)
{
	sort(nums.begin(), nums.end());

	if (nums.empty() || nums.size() < 3 || nums.front() > 0 || nums.back() < 0)
		return {};

	int nLen = nums.size();
	vector<vector<int>> res;
	set<vector<int>> temp;

	for (int nLeft = 0; nLeft != nLen - 2; ++nLeft)
	{
		if (nums[nLeft] > 0)
			break;
		int nMid = nLeft + 1;
		int nRight = nLen - 1;
		while (nMid < nRight)
		{
			// 同号，跳出while循环
			if (nums[nLeft] > 0 && nums[nRight] > 0 || nums[nLeft] < 0 && nums[nRight] < 0)
				break;
			int sums = nums[nLeft] + nums[nMid] + nums[nRight];
			if (sums == 0)
			{
				temp.insert(vector<int>{nums[nLeft], nums[nMid], nums[nRight]});
				++nMid;
				--nRight;
			}
			else if (sums > 0)
				--nRight;
			else
				++nMid;
		}
	}

	for (auto i : temp)
		res.push_back(i);

	return res;
}

int main()
{
	int N;
	cin >> N;
	vector<int> arr;
	int nVal;
	for (int i = 0; i < N; ++i)
	{
		cin >> nVal;
		arr.push_back(nVal);
	}

	vector<vector<int>> nums = threeSum_set(arr);
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = 0; j < nums[0].size(); ++j)
			cout << nums[i][j] << " ";
		cout << endl;
	}

}