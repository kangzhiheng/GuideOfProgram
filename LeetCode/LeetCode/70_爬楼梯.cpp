//-----------------------------------------------------------------------------
// 作    者：adoredee
// 创建时间：2019.04.23
// 描    述：爬楼梯
//-----------------------------------------------------------------------------
/*
假设你正在爬楼梯。需要 n 阶你才能到达楼顶。

每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？

注意：给定 n 是一个正整数。

示例 1：

输入： 2
输出： 2
解释： 有两种方法可以爬到楼顶。
1.  1 阶 + 1 阶
2.  2 阶
示例 2：

输入： 3
输出： 3
解释： 有三种方法可以爬到楼顶。
1.  1 阶 + 1 阶 + 1 阶
2.  1 阶 + 2 阶
3.  2 阶 + 1 阶
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int ClimStaires(int n)
{
	if (n < 1)
		return 0;
	/*if (n == 1)
		return 1;
	if (n == 2)
		return 2;*/
	return (n == 1 || n == 2) ? n : ClimStaires(n - 1) + ClimStaires(n - 2);
}

// 递归
int test01(int n)
{
	return ClimStaires(n);
}

// 动态规划
int test02(int n)
{
	if (n < 1)
		return 0;
	if (n == 1)
	return 1;
	if (n == 2)
	return 2;

	int sum = 0;
	int sum1 = 1, sum2 = 2;

	for (int i = 2; i < n; i++)
	{
		sum = sum1 + sum2;
		sum1 = sum2;
		sum2 = sum;
	}
	return sum;

}

int main()
{
	int n;
	cout << "输入n个台阶: ";
	cin >> n;

	cout << test01(n) << endl;
	cout << test02(n) << endl;

	return 0;
}