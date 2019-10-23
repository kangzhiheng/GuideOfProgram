//-----------------------------------------------------------------------------
// 文 件 名: 754_到达终点数字.cpp
// 作    者：adoredee
// 创建时间： 2019.09.12
// 描    述：到达终点数字_BFS
// 版    本：
// 链    接：https://leetcode-cn.com/problems/reach-a-number/
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

#include <iostream>

using namespace std;

int reachNumber(int target)
{
	target = target > 0 ? target : -target;    // 因为target为正为负，走的步数都是一样的，所以只考虑正的情况
	int sums = 0;
	int i = 0;
	/*
	    1. sums < target, 依次累加 0 + 1 + 2 + ... + i = sums;
		2. 恰好 sums == target， 输出 i - 1, 因为sums和i刚开始都被初始化为0，多了一步，最后输出的时候要减一步;
		3. 如果 sums > target, 此时sums - target的差为偶数，可以由前面的某个数字变负可得，
		   比如 target = 8，则 0 + 1 + 2 + 3 + 4 = 10，10 - 8 = 2, 此时把 1 变为 -1, 即可得到 8；
		   如果 sums - target 的差为奇数，则一直累加知道差为第一个偶数即可
		   
	*/
	while (sums < target || (sums - target) % 2 != 0)
	{
		sums += i;
		++i;
	}
	return --i;
}

int main()
{
	int N;
	cin >> N;
	int nums = reachNumber(N);
	cout << nums << endl;
}