// 文 件 名: 59_滑动窗口的最大值.cpp
// 作    者：adoredee
// 创建时间： 2019.08.05
// 描    述：滑动窗口的最大值
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题59（一）：滑动窗口的最大值
// 题目：给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。例如，
//      如果输入数组{2, 3, 4, 2, 6, 2, 5, 1}及滑动窗口的大小3，那么一共存在6个
//      滑动窗口，它们的最大值分别为{4, 4, 6, 6, 6, 5}，

#include <iostream>
#include <vector>
#include <deque>

using namespace std;

vector<int> maxInWindows(const vector<int>& aArr, size_t size)
{
	vector<int> maxWindows;

	if (aArr.size() >= size && size >= 1)
	{
		deque<int> index;

		// 存储前size最大值的索引
		for (size_t i = 0; i < size; ++i)
		{
			while (!index.empty() && aArr[i] >= aArr[index.back()])
				index.pop_back();

			index.push_back(i);
		}
		
		for (size_t i = size; i < aArr.size(); ++i)
		{
			// index的队列头部保存的是滑动窗口的最大值的索引
			maxWindows.push_back(aArr[index.front()]);

			while (!index.empty() && aArr[i] >= aArr[index.back()])
				index.pop_back();

			// 保证滑动窗口的size
			if (!index.empty() && index.front() <= (int)(i - size))
				index.pop_front();

			index.push_back(i);
		}
		maxWindows.push_back(aArr[index.front()]);
	}

	return maxWindows;
}

int main()
{
	vector<int> aArr = { 2, 3, 4, 2, 6, 2, 5, 1 };
	
	cout << "原数组为: ";
	for (int i = 0; i < aArr.size(); ++i)
		cout << aArr[i] << " ";
	cout << endl;

	cout << "请输入滑动窗口的尺寸：";
	int size;
	cin >> size;
	vector<int> maxValue = maxInWindows(aArr, size);

	cout << "尺寸为 " << size << " 滑动窗口的最大值依次为：";
	for (int i = 0; i < maxValue.size(); ++i)
		cout << maxValue[i] << " ";
	cout << endl;

	return 0;
}
