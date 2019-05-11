//-----------------------------------------------------------------------------
// 文 件 名: 10_02_青蛙普通跳台阶(最多跳2级).cpp
// 作    者：adoredee
// 创建时间：2019.04.21
// 描    述：跳上第n阶有多少种问题
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题10之二：青蛙跳台阶
// 题目：一只青蛙一次可以跳1级台阶，也可以跳两级台阶，求该青蛙可以上一个n级台阶有多少种跳法。

/*
    思路：斐波那契数列数列的变形，初始值不同
*/
#include <iostream>
#include <time.h>

using namespace std;

// 递归
long long Frog_Jumps_normally_Recursive(size_t n)
{
	if (n == 1)
		return 1;

	if (n == 2)
		return 2;

	return Frog_Jumps_normally_Recursive(n - 1) + Frog_Jumps_normally_Recursive(n - 2);
}

// 循环
long long Frog_Jumps_normally__Circulate(size_t n)
{
	if (n == 1)
		return 1;

	if (n == 2)
		return 2;

	long long Fib_front = 1;
	long long Fib_back = 2;
	long long Fib_N = 0;

	for (size_t i = 3; i <= n; ++i)
	{
		Fib_N = Fib_front + Fib_back;

		Fib_front = Fib_back;
		Fib_back = Fib_N;
	}
	return Fib_N;
}


int main()
{
	cout << "小青蛙想跳阶台阶: ";
	size_t n;
	cin >> n;
	clock_t Recursive_StartTime = clock();    // 递归开始时间
	size_t Recursive_value = Frog_Jumps_normally_Recursive(n);
	clock_t Recursive_EndTime = clock();      // 递归结束时间
	cout << "递归求解得共有：" << Frog_Jumps_normally_Recursive(n) << "种方法 —> 用时: " << (Recursive_EndTime - Recursive_StartTime) << "ms" << endl;

	clock_t Circulate_StartTime = clock();    // 递归开始时间
	size_t Circulate_value = Frog_Jumps_normally__Circulate(n);
	clock_t Circulate_EndTime = clock();      // 递归结束时间
	cout << "循环求解得共有：" << Frog_Jumps_normally__Circulate(n) << "种方法 —> 用时: " << (Circulate_EndTime - Circulate_StartTime) << "ms" << endl;

	return 0;
}