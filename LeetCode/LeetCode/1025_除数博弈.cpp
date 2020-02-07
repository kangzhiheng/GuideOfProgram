//-----------------------------------------------------------------------------
// 作    者：adoredee
// 创建时间： 2020.02.07
// 描    述：打家劫舍
// 版    本：
// 链    接：https://leetcode-cn.com/problems/divisor-game/
//-----------------------------------------------------------------------------
// Copyright (C) 2020 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------
#include <iostream>

using namespace std;

/* 思路：
    这道题的关键是，谁先到 N = 2，谁就赢。
	首先要明白一个情况：
	若N为奇数，则其因子只能为奇数；
	若N为偶数，则其因子可为奇数也可为偶数；
	因此，有两种情况（Alice先手）：
	1. 若N为奇数，Alice第一次选完，N必为偶数，此时Bob只需要一直选1，Bob稳赢；
	2. 若N为偶数，Alice只需要一直选1，总能轮到Alice等到N=2的情况，Alice稳赢；
*/
bool divisorGame(int N)
{
	return N % 2 == 0;
}

int main()
{
	int N = 333;

	bool flag = divisorGame(N);
	cout << flag << endl;

	return 0;
}