//-----------------------------------------------------------------------------
// 文 件 名: 41_数据流中的中位数.cpp
// 作    者：adoredee
// 创建时间： 2019.06.26
// 描    述：数据流中的中位数
// 版    本：
//-----------------------------------------------------------------------------

// 面试题41：数据流中的中位数
// 题目：如何得到一个数据流中的中位数？如果从数据流中读出奇数个数值，那么
//      中位数就是所有数值排序之后位于中间的数值。如果从数据流中读出偶数个数值，
//      那么中位数就是所有数值排序之后中间两个数的平均值。

/*
    《剑指offer》第二版第216页第二段开头描述有误，最大堆的所有数据都要 小于 最小堆的所有数据
    将数据排序后分为两部分，左边部分的数据总是比右边的数据小。那么就可以用最大堆和最小堆来装载这些数据：
    1. 最大堆装左边的数据，取出堆顶（最大的数）的时间复杂度是O(1)
    2. 最小堆装右边的数据，同样，取出堆顶（最小的数）的时间复杂度是O(1)
	最小堆堆顶的数大于等于最大堆堆顶的数
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>

using namespace std;

template<typename T> class DynamicArray
{
public:
	void Insert(T num)
	{
		// 判断总个数是奇数还是偶数，偶数插入到最小堆，奇数插入到最大堆
		/* 
		     最大堆在左，最小堆在右
		     偶数情况下，新元素插入到最小堆，有两种情况：
			 1. 该元素小于最大堆的最大值，则先把该元素插入到最大堆，取最大堆里最大的那个元素放入到最小堆即可；
			 2. 该元素大于等于最大堆的最大值，直接插入到最小堆
		*/
		int size = MinSubArray.size() + MaxSubArray.size();    // 数据流长度
		if ((size & 1) == 0)    // 数据流是偶数
		{			
			// MaxSubArray[0]表示最大堆里最大的数字，插入的数据小于最大堆里最大的数字，则先把该数据插入到最大堆
			if (MaxSubArray.size() > 0 && num < MaxSubArray[0])
			{
				MaxSubArray.push_back(num);
				push_heap(MaxSubArray.begin(), MaxSubArray.end(), less<T>());    // 生成最大堆

				num = MaxSubArray[0];    // 取出最大堆里最大的数字

										 // 将堆顶（最大值）移到数组末尾，再将前面的元素重新生成一个最大堆，再用pop_back()删除末尾元素
				pop_heap(MaxSubArray.begin(), MaxSubArray.end(), less<T>());
				MaxSubArray.pop_back();    // 删除容器里最后一个原数
			}

			// 不管是否经过最大堆处理，总要把数据插入到最小堆 
			MinSubArray.push_back(num);
			// 添加元素，生成最小堆
			push_heap(MinSubArray.begin(), MinSubArray.end(), greater<T>());
		}
		/*
		    奇数情况下，最小堆元素个数比最大堆个数多1，新元素插入到最大堆，有两种情况：
			1. 该元素大于最小堆的最小值，则先把该元素插入到最小堆，取最小堆里最小的那个元素放入到最大堆即可；
			2. 该元素小于等于最小堆的最小值，直接插入到最大堆
		*/
		else
		{
			// MinSubArray[0]为最小堆里的最小值
			if (MinSubArray.size() > 0 && num > MinSubArray[0])
			{
				MinSubArray.push_back(num);
				push_heap(MinSubArray.begin(), MinSubArray.end(), greater<T>());    // 重新生成最小堆

				num = MinSubArray[0];    // 取最小堆的里的最小值

				pop_heap(MinSubArray.begin(), MinSubArray.end(), greater<T>());     // 将最小值放到最后，将前面的值重新生成最小堆
				MinSubArray.pop_back();     // 删除最后一个元素
			}

			// 不管是否经过最小堆处理，总要把数据插入到最大堆 
			MaxSubArray.push_back(num);
			push_heap(MaxSubArray.begin(), MaxSubArray.end(), less<T>());
		}
	}

	T GetMedian()
	{
		int size = MinSubArray.size() + MaxSubArray.size();
		if (size == 0)
			throw("No Numbers are available");

		T middle = 0;
		// 数据流总长度为奇数，最小堆长度比最大堆长度大1
		if ((size & 1) == 1)
			middle = MinSubArray[0];
		else
			middle = (MaxSubArray[0] + MinSubArray[0]) / 2;    // 不能用位运算 >> 1， 整型可以用，浮点型用不了

		return middle;
	}

private:
	vector<T> MinSubArray;    // 最小堆
	vector<T> MaxSubArray;    // 最大堆
};

int main()
{
	DynamicArray<float> arr;

	vector<float> arrStream;
	int val;
	cout << "请输入数据流(先按enter，再ctrl+z,再按两次enter结束输入,或者换行之后按两次ctrl+z(中间再按一下换行),再按一次enter结束输入)：" << endl;
	while (scanf("%d", &val))
	{
		arrStream.emplace_back(val);
		arr.Insert(val);
	}

	cout << "原数据流中的元素为：";
	for (int i = 0; i < arrStream.size(); ++i)
		cout << arrStream[i] << " ";
	cout << endl;

	cout << "请输入你想插入到数据流的数字：";
	int value;
	cin >> value;
	arr.Insert(value);

	float middle = arr.GetMedian();

	cout << "数据流的中位数为 —> " << middle << endl;

	return 0;
}