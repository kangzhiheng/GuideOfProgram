//-----------------------------------------------------------------------------
// 文 件 名: 51_数组中的逆序对.cpp
// 作    者：adoredee
// 创建时间： 2019.07.24
// 描    述：数组中的逆序对
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题51：数组中的逆序对
// 题目：在数组中的两个数字如果前面一个数字大于后面的数字，则这两个数字组
//      成一个逆序对。输入一个数组，求出这个数组中的逆序对的总数。

#include <iostream>
#include <vector>

using namespace std;

vector<int> cnt;    // 统计每次操作所产生的逆序对的个数

// 打印数组
void PrintArray(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << " ";
	cout << endl;
}

// 数组归并
int Merge(vector<int>& data, int start, int mid, int end, vector<int>& temp)
{
	int i = mid;    // 前半段最后一个数字的下标
	int j = end;    // 后半段最后一个数字的下标

	int k = 0;      // 临时数组的第一个下标
	int count = 0;

	while (i >= start && j > mid)
	{
		// 两段都是升序，故如果前半段最后一个数字大于后半段最后一个数子，
		// 则大于后半段所有的数字，故存在逆序对，即为后半段数字的个数
		if (data[i] > data[j])
		{
			temp[k++] = data[i--];
			count += j - mid;
		}
		else    // 否则后半段数字最大，放到临时数组里，临时数组是降序
		{
			temp[k++] = data[j--];
		}
	}

	cout << "本次归并时产生的逆序对为：" << count << endl;
	cnt.emplace_back(count);

	// 表示前半段数组中还有元素未放入临时数组
	while (i >= start)
	{
		temp[k++] = data[i--];
	}

	while (j > mid)
	{
		temp[k++] = data[j--];
	}
	// 将临时数组中的元素写回到原数组当中去
	for (int i = 0; i < k; ++i)
		data[end - i] = temp[i];

	// 打印出每次归并以后的数组形式
	PrintArray(data);

	return count;
}

int InversePairsCore(vector<int>& data, vector<int>& temp, int start, int end)
{
	int inversions = 0;

	if (start < end)
	{
		int mid = (start + end) / 2;
		inversions += InversePairsCore(data, temp, start, mid);
		inversions += InversePairsCore(data, temp, mid + 1, end);
		inversions += Merge(data, start, mid, end, temp);
	}

	return inversions;
}

// 找出所有逆序对
int InversePairs(vector<int>& data)
{
	if (data.empty() || data.size() < 0)
		throw "数组异常";

	vector<int> temp(data.size());

	int counts = InversePairsCore(data, temp, 0, data.size() - 1);

	return counts;
}

int main()
{
	vector<int> arr = { 1,3,7,8,2,4,6,5 };
	int counts = InversePairs(arr);

	cout << "总共进行了" << cnt.size() << "次归并操作，即" << endl;
	for (int i = 0; i < cnt.size(); ++i)
	{
		if (i == cnt.size() - 1)
		{
			cout << cnt[i] << " = " << counts << endl;
			break;
		}
		cout << cnt[i] << " + ";
	}

	cout << "总逆序对为：" << counts << endl;

	return 0;
}
