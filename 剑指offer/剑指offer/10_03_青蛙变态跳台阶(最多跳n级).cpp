//-----------------------------------------------------------------------------
// 文 件 名: 10_03_青蛙变态跳台阶(最多跳n级).cpp
// 作    者：adoredee
// 创建时间：2019.04.21
// 描    述：跳上第n阶有多少种问题
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题10之二：青蛙变态跳台阶
// 题目：一只青蛙一次可以跳1级台阶，也可以跳两级台阶，，也可以跳n级，求该青蛙可以上一个n级台阶有多少种跳法。

/*
思路：
   令f(n)表示从第一级台阶跳上第 n 级台阶有几种跳法。
   逆向思维，将问题改为：跳上第 n 级台阶该怎么跳？
   要跳上第 n 级台阶，可以从第 n−1 级台阶一次跳上来，也可以可以从第 n−2 级台阶一次跳上来，
   也可以可以从第 n−3 级台阶一次跳上来，…，也可以可以从第 1 级台阶一次跳上来：，故
   f(n) = f(n-1) + f(n-2) + f(n-3) + ... + f(2) + f(1)，那么
   f(n-1) = f(n-2) + f(n-3) + ... + f(2) + f(1),将上式合并可得，
   f(n) = f(n-1) + f(n-1) = 2f(n-1)，以此类推可得，
   f(n) = 2f(n-1）= 4f(n-2) = 8f(n-3) = ... = 2^(n-2)f(2) = 2^(n-1)f(1) = 2^(n-1)，即得到规律
   f(n) = 2^(n-1)
*/
#include <iostream>
#include <time.h>

using namespace std;

// 递归
long long Frog_Jumps_unusual_Recursive(size_t n)
{
	return n <= 1 ? 1 : 2 * Frog_Jumps_unusual_Recursive(n - 1);
}

// 循环
long long Frog_Jumps_unusual_Circulate(size_t n)
{
	if (n == 1)
		return 1;

	long long Fib_N = 1;

	for (size_t i = 2; i <= n; ++i)
	{
		Fib_N = 2 * Fib_N;
	}
	return Fib_N;
}


int main()
{
	cout << "小青蛙想跳阶台阶: ";
	size_t n;
	cin >> n;
	clock_t Recursive_StartTime = clock();    // 递归开始时间
	size_t Recursive_value = Frog_Jumps_unusual_Recursive(n);
	clock_t Recursive_EndTime = clock();      // 递归结束时间
	cout << "递归求解得共有：" << Frog_Jumps_unusual_Recursive(n) << "种方法 —> 用时: " << (Recursive_EndTime - Recursive_StartTime) << "ms" << endl;

	clock_t Circulate_StartTime = clock();    // 递归开始时间
	size_t Circulate_value = Frog_Jumps_unusual_Circulate(n);
	clock_t Circulate_EndTime = clock();      // 递归结束时间
	cout << "循环求解得共有：" << Frog_Jumps_unusual_Circulate(n) << "种方法 —> 用时: " << (Circulate_EndTime - Circulate_StartTime) << "ms" << endl;

	return 0;
}