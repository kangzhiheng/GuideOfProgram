//-----------------------------------------------------------------------------
// 文 件 名: 72_编辑距离.cpp
// 作    者：adoredee
// 创建时间： 2019.09.19
// 描    述：编辑距离
// 版    本：
// 链    接：https://leetcode-cn.com/problems/edit-distance/
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 参考：https://leetcode-cn.com/problems/edit-distance/solution/bian-ji-ju-chi-mian-shi-ti-xiang-jie-by-labuladong/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int min(int a, int b, int c)
{
	return min(a, min(b, c));
}

pair<int, int> min_pair(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
	pair<int, int> temp;
	if (a.first < b.first)
		temp = a;
	else
		temp = b;
	if (temp.first > c.first)
		temp = c;

	return temp;
}

pair<int, int> addTwoPair(pair<int, int> a, pair<int, int> b)
{
	int value = a.first + b.first;

	pair<int, int> sums(value, b.second);

	return sums;
}

/* DP[i][j] 表示 word1 的 i 位置转换到 word2 的 j 位置所需的最小步数
   1. word1[i] == word2[j], 跳过
   2. word1[i] != word2[j], 取删除、插入、替换的最小值
      DP[i - 1][j] + 1 表示删除，对word1的删除，故将 i 的索引值减1
	  DP[i][j - 1] + 1 表示插入，在word1的 i 的索引处插入word2的 j 处的值，故索引值 j - 1，进行下一次操作
	  DP[i-1][j-1] + 1 表示替换，用word2的 j 的索引处的值替换掉word1的 i 的索引处值，i, j 都减1
    其实，不管word1转换到word2，还是word2转换到word1，对称操作
 */
int minDistance(string word1, string word2)
{
	// 如果word1为空，将word1转换为word2需要word2的长度的步骤数，反之亦然
	if (word2.empty() || word1.empty())
		return max(word1.size(), word2.size());

	vector<vector<int>> DP(word1.size() + 1, vector<int>(word2.size() + 1));
	DP[0][0] = 0;
	for (int i = 1; i <= word1.size(); ++i)
		DP[i][0] = i;
	for (int j = 1; j <= word2.size(); ++j)
		DP[0][j] = j;

	for (int i = 1; i <= word1.size(); ++i)
	{
		for (int j = 1; j <= word2.size(); ++j)
		{
			if (word1[i - 1] == word2[j - 1])
				DP[i][j] = DP[i - 1][j - 1];    // 跳过
			else
				DP[i][j] = min(
					DP[i - 1][j] + 1,        // 删除
					DP[i][j - 1] + 1,        // 插入
					DP[i - 1][j - 1] + 1     // 替换
				);
		}
	}	

	for (auto i : DP)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	return DP[word1.size()][word2.size()];
}

// 返回每一步的操作
int minDistance_Output(string word1, string word2)
{
	// 如果word1为空，将word1转换为word2需要word2的长度的步骤数，反之亦然
	if (word2.empty() || word1.empty())
		return max(word1.size(), word2.size());

	// pair<int, int> 代表最小步数所对应的操作，0表示跳过，1表示删除，2表示插入，3表示替换
	vector<vector<pair<int, int>>> DP(word1.size() + 1, vector<pair<int, int>>(word2.size() + 1));
	DP[0][0] = { 0, 0 };
	for (int i = 1; i <= word1.size(); ++i)
		DP[i][0] = { i, 2 };
	for (int j = 1; j <= word2.size(); ++j)
		DP[0][j] = { j, 2 };

	pair<int, int> deletes(1, 1);
	pair<int, int> inserts(1, 2);
	pair<int, int> replace(1, 3);

	for (int i = 1; i <= word1.size(); ++i)
	{
		for (int j = 1; j <= word2.size(); ++j)
		{
			if (word1[i - 1] == word2[j - 1])
				DP[i][j] = DP[i - 1][j - 1];    // 跳过
			else
				DP[i][j] = min_pair(
					addTwoPair(DP[i - 1][j], deletes),        // 删除
					addTwoPair(DP[i][j - 1], inserts),        // 插入
					addTwoPair(DP[i - 1][j - 1], replace)     // 替换
			);
		}
	}

	for (auto i : DP)
	{
		for (auto j : i)
			cout << "(" << j.first << "," << j.second << ")  ";
		cout << endl;
	}

	return DP[word1.size()][word2.size()].first;
}

int main()
{
	int i = 0, nSpaceNum = 0;
	char *newstr = new char[length + nSpaceNum];

	string s1, s2;
	cin >> s1 >> s2;

	int nMinSteps = minDistance_Output(s1, s2);
	cout << nMinSteps << endl;

	return 0;
}