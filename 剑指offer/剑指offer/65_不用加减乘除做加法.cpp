//-----------------------------------------------------------------------------
// 文 件 名: 65_不用加减乘除做加法.cpp
// 作    者：adoredee
// 创建时间： 2019.08.12
// 描    述：不用加减乘除做加法
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题65：不用加减乘除做加法
// 题目：写一个函数，求两个整数之和，要求在函数体内不得使用＋、－、×、÷
//      四则运算符号。

#include <iostream>

using namespace std;

/*
    位运算
	假设num1 = 5, num2 = 17
	num1 =  5 =  0101,
	num2 = 17 = 10001,
	1. 对应位相加，不进位，得12，0 + 1 = 1，5 + 7 = 2
	2. 进位是10，；
	3. 相加 12 + 10 = 22；
	对应得位运算为：
	1. 先做 异或 运算，因为不进位，0101 ^ 10001 = 10100;
	2. 再做 与 运算，因为只获得进位，又因为是向高位进位，所以还要左移一位，即 (0101 & 10001) << 1 = 0001 << 1 = 0010，
	   0001中代表了产生的位置，左移一位是向高位进位，只有当与 运算的值为0时，结束；

	Note: 正负数都适用
*/
int AddTwoNum(int num1, int num2)
{
	int sum, carry;

	do
	{
		sum = num1 ^ num2;             // 对应位相乘，不进位
		carry = (num1 & num2) << 1;    // 产生进位了吗？ 

		num1 = sum;
		num2 = carry;
	} while (num2 != 0);

	return num1;
}

int main()
{
	int num1, num2;
	cout << "请输入两个数：";
	cin >> num1 >> num2;

	int nSum = AddTwoNum(num1, num2);

	cout << "两数之和为：" << nSum << endl;

	return 0;
}