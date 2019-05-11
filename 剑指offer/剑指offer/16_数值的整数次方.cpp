//-----------------------------------------------------------------------------
// 文 件 名: 16_数值的整数次方.cpp
// 作    者：adoredee
// 创建时间：2019.05.08
// 描    述：数值的整数次方
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题16：数值的整数次方
// 题目：实现函数double Power(double base, int exponent)，求base的exponent
//      次方。不得使用库函数，同时不需要考虑大数问题。

// 注意事项：判断底数或者指数是否为负数

#include <iostream>

using namespace std;

// 方法一：常规方法
double Power_Normal(double base, int exponent)
{
	/*
	base ——> 底数
	exponent ——> 指数
	*/
	// 异常情况 ——> 底数或者指数为零
	if (base == 0.0)
	{
		if (exponent < 0)
		{
			cout << "非法输入" << endl;
			return 0;
		}
		else
			return 0;
	}

	// 取指数绝对值
	size_t abs_exponent = exponent > 0 ? exponent : -exponent;

	// 核心算法
	double sum = 1.0;
	for (size_t i = 0; i < abs_exponent; i++)
		sum *= base;

	// 返回真实值
	return exponent > 0 ? sum : 1 / sum;
}


// 方法二：公式计算
/*
    n为偶数 ——> a^n = a^(n/2) * a^(n/2)
	n为奇数 ——> a^n = a^((n-1)/2) * a^((n-1)/2) * a
*/
double PowerWithFormula(double base, size_t exponent)
{
	// 递归结束条件
	if (exponent == 0)
		return 1;
	if (exponent == 1)
		return base;

	double result = PowerWithFormula(base, exponent >> 1);
	result *= result;

	// 上面的几条语句是递归函数体，满足递归条件后，exponent恢复原值，此时判断指数奇偶性
	if (exponent & 0x1 == 1)    // exponent为奇数
		result *= base;

	return result;
}
double Power_Formula(double base, int exponent)
{
	/*
	base ——> 底数
	exponent ——> 指数
	*/
	// 异常情况 ——> 底数或者指数为零
	if (base == 0.0)
	{
		if (exponent < 0)
		{
			cout << "非法输入" << endl;
			return 0;
		}
		else
			return 0;
	}

	// 取指数绝对值
	size_t abs_exponent = exponent > 0 ? exponent : -exponent;

	// 核心算法
	double sum = PowerWithFormula(base, exponent);

	// 返回真实值
	return exponent > 0 ? sum : 1 / sum;
}


int main()
{
	cout << "请输入底数(double型):";
	double base;
	cin >> base;

	cout << "请输入指数:";
	int exponent;
	cin >> exponent;

	double sum_1 = Power_Normal(base, exponent);
	cout << "常规方法: " << base << "的" << exponent << "次方为: " << sum_1 << endl;

	double sum_2 = Power_Formula(base, exponent);
	cout << "公式方法: " << base << "的" << exponent << "次方为: " << sum_2 << endl;

	return 0;
}