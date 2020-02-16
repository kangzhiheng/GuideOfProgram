//-----------------------------------------------------------------------------
// 文 件 名: 40_最小的k个数.cpp
// 作    者：adoredee
// 创建时间： 2019.06.13
// 描    述：最小的k个数
// 版    本：
//-----------------------------------------------------------------------------

// 面试题40：最小的k个数
// 题目：输入n个整数，找出其中最小的k个数。例如输入4、5、1、6、2、7、3、8
//      这8个数字，则最小的4个数字是1、2、3、4。

#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

int Partition(vector<int>& arr, int start, int end)
{
	// 异常检测
	if (arr.empty() || arr.size() <= 0)
		return 0;

	srand(int(time(0)));
	int pivot = rand() % (end - start + 1) + start;
	int key = arr[pivot];

	swap(arr[pivot], arr[start]);    // 将基准基放到第一个位置上
	while (start < end)
	{
		while (start < end && arr[end] > key)
			end--;
		swap(arr[start], arr[end]);
		while (start < end && arr[start] <= key)
			start++;
		swap(arr[start], arr[end]);
	}

	return start;
}

vector<int> kLeastNumbers_Partition(vector<int>& arr, int k)
{
	// 异常检测
	if (arr.empty() || arr.size() <= 0 || k > arr.size() || k <= 0)
		return arr;

	int start = 0;
	int end = arr.size() - 1;

	int index = Partition(arr, start, end);    // 选取基准值

	while (index != k - 1)    // 判断是否是前k个数
	{
		if (index > k - 1)
		{
			end = index - 1;
			index = Partition(arr, start, end);
		}
		else    // index < k - 1
		{
			start = index + 1;
			index = Partition(arr, start, end);
		}
	}

	// 将前k个数存储起来
	vector<int> arr_kLeast;
	for (int i = 0; i < k; ++i)
		arr_kLeast.emplace_back(arr[i]);

	return arr_kLeast;
}

vector<int> kLeastNumbers_top_k(vector<int>& arr, int k)
{
	// 异常检测
	if (arr.empty() || arr.size() <= 0 || k > arr.size() || k < 0)
		return arr;
	if (k == 0)
		return {};

	/*
	top_k思路：先取数组中前k个数，按从小到大排列，
	如果剩余的数比这k个数中的最小值还要小，则用k中最大的数替换该数，再重新排序
	*/
	vector<int> arr_top_k;
	for (int i = 0; i < k; ++i)
		arr_top_k.emplace_back(arr[i]);
	sort(arr_top_k.begin(), arr_top_k.end());    // 对原数组的前k项进行升序排序

	for (int i = k; i < arr.size(); i++)
	{
		if (arr[i] < arr_top_k[k - 1])    // 如果剩下的元素小于arr_top_k里最大的，则替换掉arr_top_k里最大的数
		{
			arr_top_k[k - 1] = arr[i];
			sort(arr_top_k.begin(), arr_top_k.end());
		}
	}

	return arr_top_k;
}

int main()
{
	int length;
	cout << "请输入数组长度：";
	cin >> length;

	int k;
	cout << "请输入k值：";
	cin >> k;

	cout << "请输入长度为" << length << "数组元素: ";
	vector<int> arr;
	for (int i = 0; i < length; i++)
	{
		int val;
		cin >> val;
		arr.emplace_back(val);
	}

	cout << "输入的数组为：";
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;

	vector<int> arr_k_1 = kLeastNumbers_Partition(arr, k);
	cout << "数组中最小的前" << k << "个数为：" << endl;
	cout << "1. Partition方法:" << endl;
	for (int i = 0; i < arr_k_1.size(); i++)
		cout << arr_k_1[i] << " ";
	cout << endl;

	cout << "2. Top_k方法:" << endl;
	vector<int> arr_k_2 = kLeastNumbers_top_k(arr, k);
	for (int i = 0; i < arr_k_2.size(); i++)
		cout << arr_k_2[i] << " ";
	cout << endl;

	return 0;
}