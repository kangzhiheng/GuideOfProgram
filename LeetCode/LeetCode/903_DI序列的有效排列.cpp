//-----------------------------------------------------------------------------
// 文 件 名: 903_DI序列的有效排列.cpp
// 作    者：adoredee
// 创建时间： 2019.09.19
// 描    述：序列的有效排列
// 版    本：
// 链    接：https://leetcode-cn.com/problems/valid-permutations-for-di-sequence/solution/di-xu-lie-de-you-xiao-pai-lie-by-leetcode/
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------
// 参考：https://www.cnblogs.com/grandyang/p/11094525.html
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int numPermsDISequence(string str)
{
	int res = 0, nLen = str.size(), MOD = 1e9 + 7;
	vector<vector<int>> DP(nLen + 1, vector<int>(nLen + 1));
	DP[0][0] = 1;
	for (int i = 1; i <= nLen; ++i)
	{
		for (int j = 0; j <= i; ++j)
		{
			if (str[i - 1] == 'D')
			{
				for (int k = j; k <= i - 1; ++k)
				{
					DP[i][j] = (DP[i][j] + DP[i - 1][k]) % MOD;
				}
			}
			if (str[i - 1] == 'I')
			{
				for (int k = 0; k <= j - 1; ++k)
				{
					DP[i][j] = (DP[i][j] + DP[i - 1][k]) % MOD;
				}
			}
		}
	}
	for (int i = 0; i <= nLen; ++i)
		res = (res + DP[nLen][i]) % MOD;

	return res;
}

int main()
{
	string str;
	cin >> str;
	int nums = numPermsDISequence(str);
	cout << nums << endl;
	
	return 0;
}