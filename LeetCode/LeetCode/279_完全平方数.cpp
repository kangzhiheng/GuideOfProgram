//-----------------------------------------------------------------------------
// 文 件 名: 279_完全平方数.cpp
// 作    者：adoredee
// 创建时间：2019.08.17
// 描    述：完全平方数
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

/*
	给定正整数 n，找到若干个完全平方数（比如 1, 4, 9, 16, ...）使得它们的和等于 n。你需要让组成和的完全平方数的个数最少。

	示例 1:
	输入: n = 12
	输出: 3
	解释: 12 = 4 + 4 + 4.

	示例 2:
	输入: n = 13
	输出: 2
	解释: 13 = 4 + 9.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;

/*
   BFS
   说明是经过若干个完全平方数之和，因此每次我们可以减去一个平方数
   //并且记录减去多少个平方数，使得结果为0
   //我们想到广度优先遍历，就是记录层数，从当前位置到目标位置需要经过多少层
                      13
                  /   |   \
             (-1)/(-4)|(-9)\
               12     9     4
			      /   |   \
             (-1)/(-4)|(-9)\
			    8     5     0
	参考：
	https://leetcode-cn.com/problems/perfect-squares/solution/c-bfsdp-by-zero4eva/
	https://leetcode-cn.com/problems/perfect-squares/solution/bfs-c-by-liang-ren/
*/
int numSquares_BFS(int n)
{
	if (n < 1)
	{
		return 0;
	}

	queue<int> q;
	vector<bool> visited(n + 1, false);

	q.push(n);
	int steps = 0;

	while (!q.empty())
	{
		++steps;
		const int size = q.size();

		for (int i = 0; i < size; ++i)
		{
			int temp = q.front();
			q.pop();
			visited[temp] = true;
			
			for (int j = 1; j * j <= temp; ++j)
			{
				if (j * j == temp)
					return steps;
				if (!visited[temp - j * j])
					q.push(temp - j * j);
			}
		}
	}
	return 0;
}

// 方法二：DP
/*
	对数组进行遍历，下标为i，每次都将当前数字先更新为最大的结果，即dp[i]=i，比如i=4，最坏结果为4=1+1+1+1即为4个数字
	动态转移方程为：dp[i] = MIN(dp[i], dp[i - j * j] + 1)，i表示当前数字，j*j表示平方数
	时间复杂度：O(n*sqrt(n))，sqrt为平方根
*/
int numSquares_DP(long n)
{
	if (n < 1)
	{
		return 0;
	}
	vector<long> dp(n + 1);

	for (int i = 1; i <= n; ++i)
	{
		dp[i] = i;
		for (int j = 1; i - j * j >= 0; ++j)
		{
			dp[i] = min(dp[i], dp[i - j * j] + 1);
		}
	}

	return dp[n];	
}

int main()
{
	cout << "请输入一个数: ";
	long nVal;
	cin >> nVal;

	int nSteps_BFS = numSquares_BFS(nVal);
	int bSteps_DP = numSquares_DP(nVal);

	cout << nVal << "最少由" << "__" << "个平方数组成。" << endl;
	cout << "BFS解法：\t" << nSteps_BFS << endl;
	cout << "DP解法：\t" << bSteps_DP << endl;

	return 0;
}