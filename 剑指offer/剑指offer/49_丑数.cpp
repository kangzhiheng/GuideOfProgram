//-----------------------------------------------------------------------------
// 文 件 名: 49_丑数.cpp
// 作    者：adoredee
// 创建时间： 2019.07.20
// 描    述：49_丑数
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题49：丑数
// 题目：我们把只包含因子2、3和5的数称作丑数（Ugly Number）。求按从小到
//      大的顺序的第1500个丑数。例如6、8都是丑数，但14不是，因为它包含因子7。
//      习惯上我们把1当做第一个丑数。

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int IsUgliNumber(int index)
{
	// 异常检测
	if (index <= 0)
		return 0;
	vector<int> num(index);    // 存放排好序的丑数，注意，此时要开辟长度为index的内存空间，不指定长度会发生内存泄漏。
	num[0] = 1;   // 1是第一个丑数
	int M2 = 0;   // 丑数是2的倍数的位置
	int M3 = 0;
	int M5 = 0;
	for (int i = 1; i < index; ++i)
	{
		/* 每一个丑数必是前面某三个对应倍数(是2，3，5的倍数的丑数)丑数的最小值
		i表示丑数的位置，num[i]存储i位置的丑数，M2表示丑数是2的倍数的丑数，M3和M5同理，更新位置表示对应倍数的丑数的位置，不是数组num的位置
		i = 0, num[i] = 1 ,M2 = 0, M3 = 0, M5 = 0
		i = 1, num[i] = 2 —> min(num[M2] * 2, num[M3] * 3, num[M5] * 5)，num[M2] * 2 = num[0] * 2 = 2最小，更新位置M2 = 1, M3 = 0, M5 = 0
		i = 2, num[i] = 3 —> min(num[M2] * 2, num[M3] * 3, num[M5] * 5)，num[M3] * 3 = num[0] * 3 = 3最小，更新位置M2 = 1, M3 = 1, M5 = 0
		*/
		int MinCadUglyNum = min(num[M2] * 2, min(num[M3] * 3, num[M5] * 5));
		// 找到对应倍数的丑数，对应倍数位置加1
		if (MinCadUglyNum == num[M2] * 2)
			++M2;
		else if (MinCadUglyNum == num[M3] * 3)
			++M3;
		else
			++M5;

		num[i] = MinCadUglyNum;
	}

	return num[index - 1];
}

int main()
{
	int index;
	cout << "请输入一个整数: ";
	cin >> index;

	int UglyNum = IsUgliNumber(index);
	cout << "第" << index << "个丑数是 " << UglyNum << endl;

	return 0;
}