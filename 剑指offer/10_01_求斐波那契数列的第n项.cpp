//-----------------------------------------------------------------------------
// 文 件 名: 10_01_求斐波那契数列的第n项.cpp
// 作    者：adoredee
// 创建时间：2019.04.21
// 描    述：求斐波那契数列的第n项
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题10之一：求斐波那契数列的第n项
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项

/*
思路：
    1. 递归 —— 代码简洁但是效率低，不推荐
	2. 循环 —— 实用解法，推荐
*/
#include <iostream>
#include <time.h>

using namespace std;

// 递归
long long Fibonacci_Recursive(size_t n)
{
	if (n <= 0)
		return 0;

	if (n == 1)
		return 1;

	return Fibonacci_Recursive(n - 1) + Fibonacci_Recursive(n - 2);
}

// 循环
long long Fibonacci_Circulate(size_t n)
{
	size_t result[] = { 0,1 };
	if (n < 2)
		return result[n];

	long long Fib_front = 0;
	long long Fib_back = 1;
	long long Fib_N = 0;

	for (size_t i = 2; i <= n; ++i)
	{
		Fib_N = Fib_front + Fib_back;

		Fib_front = Fib_back;
		Fib_back = Fib_N;
	}
	return Fib_N;
}


int main()
{
	cout << "您想知道斐波那契数列的第几项的值，请输入一个正整数: ";
	size_t n;
	cin >> n;
	clock_t Recursive_StartTime = clock();    // 递归开始时间
	size_t Recursive_value = Fibonacci_Recursive(n);
	clock_t Recursive_EndTime = clock();      // 递归结束时间
	cout << "递归求解得：" << Fibonacci_Recursive(n) << " —> 用时: " << (Recursive_EndTime - Recursive_StartTime) << "ms"<< endl;

	clock_t Circulate_StartTime = clock();    // 递归开始时间
	size_t Circulate_value = Fibonacci_Circulate(n);
	clock_t Circulate_EndTime = clock();      // 递归结束时间
	cout << "循环求解得：" << Fibonacci_Circulate(n) << " —> 用时: " << (Circulate_EndTime - Circulate_StartTime) << "ms" << endl;

	return 0;
}