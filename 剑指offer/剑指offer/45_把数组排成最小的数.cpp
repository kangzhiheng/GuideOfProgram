//-----------------------------------------------------------------------------
// 文 件 名: 45_把数组排成最小的数.cpp
// 作    者：adoredee
// 创建时间：2019.07.10
// 描    述：把数组排成最小的数
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------


// 面试题45：把数组排成最小的数
// 题目：输入一个正整数数组，把数组里所有数字拼接起来排成一个数，打印能拼
//      接出的所有数字中最小的一个。例如输入数组{3, 32, 321}，则打印出这3个数
//      字能排成的最小数字321323。

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

// 定义一个新的比较法则
static int compare(int strNumber1, int strNumber2)
{
	// 使用to_string将int型转换成string
	string m = to_string(strNumber1);
	string n = to_string(strNumber2);

	// 字符串方便拼接
	string mn = m + n;
	string nm = n + m;

	return mn < nm;    // 从小到大排序
}

string PrintMinNumber(vector<int>& numbers)
{
	// 异常检测
	string result;
	if (numbers.size() <= 0)
		return result;

	// 对数组进行排序
	sort(numbers.begin(), numbers.end(), compare);

	// 字符串拼接
	for (int i = 0; i < numbers.size(); ++i)
		result += to_string(numbers[i]);

	return result;
}

int main()
{
	vector<int> test{ 9, 8, 5, 1, 4, 7 };
	cout << "原数组为：";
	for (auto i : test)
		cout << i << " ";
	cout << endl;

	string result = PrintMinNumber(test);
	cout << "该数组排列的最小的数字为:";
	cout << result << endl;

	return 0;
}