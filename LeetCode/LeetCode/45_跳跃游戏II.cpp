//-----------------------------------------------------------------------------
// �� �� ��: 45_��Ծ��ϷII.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.09.16
// ��    ������Ծ��ϷII
// ��    ����
// ��    �ӣ�https://leetcode-cn.com/problems/jump-game-ii/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-10/
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
    ˼·��
	����2 3 1 1 4
	���Ҫ����4������Ҫ��3��ʼ����
	���±߽磬���Ҫ����3����2��ʼ������
	��ÿ�ζ�Ҫ���±߽�
	�����ȫ1�����飬�ᳬʱ
*/
int jump_(vector<int>& nums)
{
	if (nums.empty() || nums.size() == 1)
		return 0;
	int nPos = nums.size() - 1;     // Ҫ�ҵ�λ��
	int steps = 0;
	while (nPos != 0)    // ȷ���н��
	{
		for (int i = 0; i < nPos; ++i)
		{
			if (i + nums[i] >= nPos)    // ���ķ�Χ�Ƿ񺭸��˱߽�
			{
				nPos = i;    // ���±߽�
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