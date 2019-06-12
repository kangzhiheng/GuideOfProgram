//-----------------------------------------------------------------------------
// 文 件 名: 39_数组中出现次数超过一半的数字.cpp
// 作    者：adoredee
// 创建时间： 2019.06.11
// 描    述：数组中出现次数超过一半的数字
// 版    本：
//-----------------------------------------------------------------------------

// 面试题39：数组中出现次数超过一半的数字
//         题目：数组中有一个数字出现的次数超过数组长度的一半，请找出这个数字。例
//         如输入一个长度为9的数组{1, 2, 3, 2, 2, 2, 5, 4, 2}。由于数字2在数组中
//         出现了5次，超过数组长度的一半，因此输出2。

#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <iterator>
#include <time.h>

using namespace std;

bool g_bInputInvalid = false;    // 表示输入数组是否有效

bool CheckInvalidArray(vector<int>& numbers)
{
	g_bInputInvalid = false;

	if (numbers.empty())    // 如果数组为空
		g_bInputInvalid = true;

	return g_bInputInvalid;
}

bool CheckMoreThanHalf(vector<int>& numbers, int number)
{
	int times = 0;
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (numbers[i] == number)
			times++;
	}

	bool isMoreThanHalf = true;
	// 题目中说明该数组一定有一个数子在数组出现的次数超过数组长度的一半，但是现在不符合条件，则为非法输入
	if (times * 2 <= numbers.size())    
	{
		g_bInputInvalid = true;
		isMoreThanHalf = false;
	}

	return isMoreThanHalf;
}

// 方法一
// 返回分隔值的下标
int getPartition(vector<int>& array, int low, int high)
{
	srand(int(time(0)));    // 产生不一样的随机数
	int pivot = rand() % (high - low + 1) + low;    // 产生[low, high]里的随机数
	int key = array[pivot];    // 选取主元
	swap(array[pivot], array[low]);    // 将基准基放到第一个位置上
	while (low < high)
	{
		while (low < high && array[high] > key)
			high--;
		swap(array[low], array[high]);
		while (low < high && array[low] <= key)
			low++;
		swap(array[low], array[high]);
	}
	return low;

}

int Partition(vector<int>& data, int start, int end)
{
	if (data.empty() || data.size() <= 0 || start < 0 || end >= data.size())
		throw new std::exception("Invalid Parameters");

	srand(int(time(0)));    // 产生不一样的随机数
	int index = rand() % (end - start + 1) + start;    // 产生[low, high]里的随机数

	swap(data[index], data[end]);

	int small = start - 1;
	for (index = start; index < end; ++index)
	{
		if (data[index] < data[end])
		{
			++small;
			if (small != index)
				swap(data[index], data[small]);
		}
	}

	++small;
	swap(data[small], data[end]);

	return small;
}


int MoreThanHalfNum_BasedOnPartition(vector<int>& numbers)
{
	// 异常检测
	if (CheckInvalidArray(numbers))
		return 0;

	int middle = numbers.size() >> 1;    // 右移一位，数组一半长度
	int start = 0;
	int end = numbers.size() - 1;
	int index = getPartition(numbers, start, end);

	while (index != middle)
	{
		if (index > middle)
		{
			end = index - 1;
			index = getPartition(numbers, start, end);
		}
		else
		{
			start = index + 1;
			index = getPartition(numbers, start, end);
		}
	}
	int result = numbers[middle];
	if (!CheckMoreThanHalf(numbers, result))
		result = 0;

	return result;
}

// 方法二：数字中某一数字出现的次数超过长度的一半
// 2.1  遍历
int MoreThanHalfNum_Traversal(vector<int>& numbers)
{
	// 异常检测
	if (CheckInvalidArray(numbers))
		return 0;

	int result = 0;
	int times = 1;

	for (int i = 0; i < numbers.size(); i++)
	{
		if (times == 0)    // 该数字与前一个数字不同
		{
			result = numbers[i];
			// times = 0，表示无符合条件的数字，times = 1表示存在
			times = 1;
		}
		else if (numbers[i] == result)    // 如果Numbers[i]与前面的数字相同，则加一
			times++;
		else    // 不同则减一
			times--;
	}

	if (!CheckMoreThanHalf(numbers, result))
		result = 0;

	return result;    
}

// 2.2  map
int MoreThanHalfNum_Map(vector<int>& numbers)
{
	// 异常检测
	if (CheckInvalidArray(numbers))
		return 0;

	unordered_map<int, int> arr_map;

	for (int i = 0; i < numbers.size(); ++i)
		arr_map[numbers[i]]++;     // 统计数组中每个数字出现的频率

//	for (auto& key : arr_map)
//		cout << "Key:[" << key.first << "] Value:[" << key.second << "]" << endl;

	int result = 0;
	for (auto& key : arr_map)
	{
		if (key.second > (numbers.size() >> 1))    // 次数大于长度的一半
		{
			result = key.first;    
			break;
		}
	}

	if (!CheckMoreThanHalf(numbers, result))
		result = 0;

	return result;    // result = 0，表示无符合条件的数字，result = 1表示存在
}

int main()
{
	vector<int> arr;

	int length;
	cout << "请输入数组长度：";
	cin >> length;

	cout << "请输入长度为" << length << "的数组元素：";
	for (size_t i = 0; i < length; i++)
	{
		int val;
		cin >> val;
		arr.emplace_back(val);
	}

	int result_1 = MoreThanHalfNum_BasedOnPartition(arr);
	int result_2_1 = MoreThanHalfNum_Traversal(arr);
	int result_2_2 = MoreThanHalfNum_Map(arr);

	cout << "数组中出现次数超过一半的数字为：" << endl;
	cout << "方法1   —> " << result_1 << endl;
	cout << "方法2.1 —> " << result_2_1 << endl;
	cout << "方法2.2 —> " << result_2_2 << endl;

	return 0;
}