//-----------------------------------------------------------------------------
// �� �� ��: 18_����֮��.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.09.16
// ��    ��������֮��
// ��    ����
// ��    �ӣ�https://leetcode-cn.com/problems/4sum/
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target)
{
	sort(nums.begin(), nums.end());

	// �쳣���
	if (nums.empty() || nums.size() < 4)
		return {};

	vector<vector<int>> res;
	set<vector<int>> temp;    // ȥ��

	int nLen = nums.size();

	for (int i = 0; i != nLen - 3; ++i)
	{
		if (target > 0 && nums[i] > target)
			break;
		for (int j = i + 1; j != nLen - 2; ++j)
		{
			int left = j + 1;
			int right = nLen - 1;
			while (left < right)
			{
				int sums = nums[i] + nums[j] + nums[left] + nums[right];
				if (sums == target)
				{
					temp.insert({ nums[i], nums[j], nums[left], nums[right] });
					++left;
					--right;
				}
				else if (sums > target)
					--right;
				else
					++left;

			}
		}
	}
	for (auto i : temp)
		res.push_back(i);

	return res;

}

int main()
{
	int N, target;
	cin >> N >> target;
	vector<int> arr;
	int nVal;
	for (int i = 0; i < N; ++i)
	{
		cin >> nVal;
		arr.push_back(nVal);
	}

	vector<vector<int>> nums = fourSum(arr, target);
	for (int i = 0; i < nums.size(); ++i)
	{
		for (int j = 0; j < nums[0].size(); ++j)
			cout << nums[i][j] << " ";
		cout << endl;
	}

}