//-----------------------------------------------------------------------------
// �� �� ��: 33_������ת��������.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.10.24
// ��    ����������ת��������
// ��    ����
// ��    �ӣ�https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

#include <iostream>
#include <vector>

using namespace std;

int search(vector<int>& nums, int target) 
{
	// �쳣���
	if (nums.empty())
		return -1;
	// ����ֻ��һ��Ԫ�ص����
	if (nums.size() == 1 && nums[0] == target)
		return 0;
	if (nums.size() == 1 && nums[0] != target)
		return -1;

	int left = 0;
	int right = nums.size() - 1;

	// ��ת��
	int flags = 0;

	if (nums[left] < nums[right])
		flags = 0;
	else
	{
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (((mid + 1) <= nums.size() - 1) && nums[mid] > nums[mid + 1])
			{
				flags = mid;    // �ҵ���ת��
				break;
			}
			else
			{
				if (nums[mid] > nums[left])
					left = mid;   // ����1
				else 
					right = mid;  // ����1
			}
		}
	}

	// �ж�target�������ĸ�����
	if (target >= nums[0] && target <= nums[flags])
	{
		left = 0;
		right = flags;
	}
	else
	{
		if (flags + 1 <= (nums.size() - 1))
		{
			left = flags + 1;
			right = nums.size() - 1;
		}
		else
			return -1;
	}

	// ���ַ�
	while (left <= right)
	{
		int mid = left + (right - left) / 2;
		if (nums[mid] == target)
			return mid;
		else if (target < nums[mid])
			right = mid - 1;
		else
			left = mid + 1;
	}

	return -1;
}

int main()
{
	vector<int> nums = { 2 };
	int flags = search(nums, 2);
	cout << flags << endl;

	return 0;
}