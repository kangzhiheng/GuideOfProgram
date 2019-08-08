// 文 件 名: 59_02_队列的最大值.cpp
// 作    者：adoredee
// 创建时间： 2019.08.06
// 描    述：队列的最大值
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题59（二）：队列的最大值
// 题目：给定一个数组和滑动窗口的大小，请找出所有滑动窗口里的最大值。例如，
//      如果输入数组{2, 3, 4, 2, 6, 2, 5, 1}及滑动窗口的大小3，那么一共存在6个
//      滑动窗口，它们的最大值分别为{4, 4, 6, 6, 6, 5}，

#include <iostream>
#include <deque>

using namespace std;

template<typename T>
class QueneWithMax
{
public:
	QueneWithMax() : currentIndex(0)
	{
	}
	void push_back(T number)
	{
		// 始终将最大值放在最前面
		while (!maximums.empty() && number >= maximums.back().number)
			maximums.pop_back();

		InternalData internalData = { number, currentIndex };
		data.push_back(internalData);
		maximums.push_back(internalData);

		++currentIndex;
	}

	void pop_front()
	{
		if (maximums.empty())
			throw new exception("queue is empty");

		if (maximums.front().index == data.front().index)
			maximums.pop_front();

		data.pop_front();
	}

	// 实际中队列 maximums 的顶部存放的始终是进入该队列的最大值，后面的值小于该最大值
	// 故调用queue的max函数时，返回的队列的顶部的值即为最大值
	T max() const
	{
		if (maximums.empty())
			throw new exception("queue is empty");

		return maximums.front().number;
	}

private:
	struct InternalData
	{
		T number;
		int index;
	};

	deque<InternalData> data;      // 存放进入该队列的所有值
	deque<InternalData> maximums;  // 存放进入该队列的所有值的最大值，并将其放到顶部
	int currentIndex;
};

int main()
{
	QueneWithMax<int> queue;

	cout << "请向队列输入相应的值：";
	int val;
	while (scanf("%d", &val))    // Enter换行，再按两下Ctrl + z， 再按一下Enter 结束输入
	{
		queue.push_back(val);
	}
	
	// 实际中queue的顶部存放的始终是进入该队列的最大值，后面的值小于该最大值
	// 故调用queue的max函数
	int nMax = queue.max();
	cout << "此时队列的最大值为：";
	cout << nMax << endl;

	return 0;
}