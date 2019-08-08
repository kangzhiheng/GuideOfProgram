// 文 件 名: 60_n个骰子的点数.cpp
// 作    者：adoredee
// 创建时间： 2019.08.08
// 描    述：n个骰子的点数
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//----------------------------------------------------------------------------- 


// 面试题60：n个骰子的点数
// 题目：把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s
//      的所有可能的值出现的概率。

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// 递归
/*
    设n个骰子某次投掷点数和为s的出现次数是F(n, s)，那么，投第n个骰子的点数之和只与投第n-1个骰子有关，故，
	F(n, s)等于n - 1个骰子投掷的点数和为s - 1、s - 2、s - 3、s -4、s - 5、s - 6时的次数的总和：
	F(n , s) = F(n - 1, s - 1) + F(n - 1, s - 2) + F(n - 1, s - 3) + F(n - 1, s - 4) + F(n - 1, s - 5) + F(n - 1, s - 6)。
*/
int CountNum(int n, int s)
{
	// 异常判断
	if (s < n || s > 6 * n)
		return 0;

	// 递归出口
	if (n == 1)
		return 1;
	else
		return CountNum(n - 1, s - 1) + CountNum(n - 1, s - 2) + CountNum(n - 1, s - 3)
		+ CountNum(n - 1, s - 4) + CountNum(n - 1, s - 5) + CountNum(n - 1, s - 6);
}

void PrintRadio(int n)    // n个骰子
{
	double nRadio = 0;
	for (int i = n; i <= 6 * n; ++i)
	{
		printf("P( s = %d ) = %.4f (%d/%d)\n", i, CountNum(n, i) / pow(6, n), CountNum(n, i), int(pow(6, n)));
	}
		
}

int main()
{
	int n;
	cout << "你有几个骰子？";
	cin >> n;

	cout << n << "个骰子朝上的点数之和可能出现的概率为：" << endl;
	PrintRadio(n);

	return 0;
}