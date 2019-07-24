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

//#include<iostream>
//#include<stdlib.h>
//using namespace std;
//
//void printArray(int arry[], int len)
//{
//	for (int i = 0; i<len; i++)
//		cout << arry[i] << " ";
//	cout << endl;
//}
//int MergeArray(int arry[], int start, int mid, int end, int temp[])//数组的归并操作
//{
//	//int leftLen=mid-start+1;//arry[start...mid]左半段长度
//	//int rightLlen=end-mid;//arry[mid+1...end]右半段长度
//
//	int i = mid;
//	int j = end;
//	int k = 0;//临时数组末尾坐标
//	int count = 0;
//	//设定两个指针ij分别指向两段有序数组的头元素，将小的那一个放入到临时数组中去。
//	while (i >= start && j>mid)
//	{
//		if (arry[i]>arry[j])
//		{
//			temp[k++] = arry[i--];//从临时数组的最后一个位置开始排序
//			count += j - mid;//因为arry[mid+1...j...end]是有序的，如果arry[i]>arry[j]，那么也大于arry[j]之前的元素，从a[mid+1...j]一共有j-(mid+1)+1=j-mid
//
//		}
//		else
//		{
//			temp[k++] = arry[j--];
//		}
//	}
//	cout << "调用MergeArray时的count：" << count << endl;
//	while (i >= start)//表示前半段数组中还有元素未放入临时数组
//	{
//		temp[k++] = arry[i--];
//	}
//
//	while (j>mid)
//	{
//		temp[k++] = arry[j--];
//	}
//
//	//将临时数组中的元素写回到原数组当中去。
//	for (i = 0; i<k; i++)
//		arry[end - i] = temp[i];
//
//	printArray(arry, 4);//输出进过一次归并以后的数组，用于理解整体过程
//	return count;
//
//}
//
//int InversePairsCore(int arry[], int start, int end, int temp[])
//{
//	int inversions = 0;
//	if (start<end)
//	{
//		int mid = (start + end) / 2;
//		inversions += InversePairsCore(arry, start, mid, temp);//找左半段的逆序对数目
//		inversions += InversePairsCore(arry, mid + 1, end, temp);//找右半段的逆序对数目
//		inversions += MergeArray(arry, start, mid, end, temp);//在找完左右半段逆序对以后两段数组有序，然后找两段之间的逆序对。最小的逆序段只有一个元素。
//	}
//	return inversions;
//}
//
//
//int InversePairs(int arry[], int len)
//{
//	int *temp = new int[len];
//	int count = InversePairsCore(arry, 0, len - 1, temp);
//	delete[] temp;
//	return count;
//}
//
//void main()
//{
//	//int arry[]={7,5,6,4};
//	int arry[] = { 7, 5, 6, 4 };
//	int len = sizeof(arry) / sizeof(int);
//	//printArray(arry,len);
//	int count = InversePairs(arry, len);
//	//printArray(arry,len);
//	cout<<count<<endl;
//	system("pause");
//}

