//-----------------------------------------------------------------------------
// 作    者：adoredee
// 创建时间： 2020.02.12
// 描    述：不同的二叉搜索树
// 版    本：
// 链    接：https://leetcode-cn.com/problems/unique-binary-search-trees/
// Copyright (C) 2019 Shanghai Jiao Tong University

#include <iostream>
#include <vector>

using namespace std;

// 卡特兰数
int numTrees(int n)
{
	vector<int> G(n + 1);
	G[0] = 1;
	G[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			G[i] += G[j - 1] * G[i - j];	// 以i为根时的个数
		}
	}

	return G[n];
}

int main()
{
	int n = 3;
	int nums = numTrees(n);
	cout << nums << endl;
}