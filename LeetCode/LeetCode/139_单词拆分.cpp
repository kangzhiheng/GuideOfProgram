//-----------------------------------------------------------------------------
// 作    者：adoredee
// 创建时间： 2020.02.12
// 描    述：单词拆分
// 版    本：
// 链    接：https://leetcode-cn.com/problems/word-break/
// Copyright (C) 2019 Shanghai Jiao Tong University

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>    // 哈希
#include <unordered_map>

using namespace std;

// 动态规划：https://www.youtube.com/watch?v=il8Oi21WZN0
// 记忆法递归：https://www.youtube.com/watch?v=ptlwluzeC1I

// 动态规划方法一
bool wordBreak_DP_1(string s, vector<string> wordDict)
{
	unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());    // 把vector类型转换成哈希表，方便查询
	int n = s.length();
	s = " " + s;
	vector<int> DP(n + 1, 0);    // 不推荐使用vector<bool>
	DP[0] = 1;

	// 大约是o(n^3)次方复杂度
	for (int i = 0; i <=n ; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (DP[j] == 1)
			{
				const string new_s = s.substr(j + 1, i- j);    // i - (j + 1) + 1
				if (dict.count(new_s))    // 查询右边新分割出来的子串是否在哈希表里
				{
					DP[i] = 1;
					break;
				}
			}
		}
	}

	return DP[n];
}

// 动态规划方法二
bool wordBreak_DP_2(string s, vector<string> wordDict)
{
	vector<int> DP(s.size() + 1, 0);
	DP[0] = 1;
	for (int i = 0; i <= s.size(); ++i)
	{
		for (auto word : wordDict)
		{
			int wordsize = word.size();
			if (i - wordsize >= 0)
			{
				int com = s.compare(i - wordsize, wordsize, word);    // s1.compare(ix,len,s2),从s1的ix位置起len长度的子串与s2相比，小于返回-1，相等返回0，大于返回1
				if (com == 0 && DP[i - wordsize] == 1)
					DP[i] = 1;
			}
		}
	}
	return DP[s.size()];
}


// 递归
class Solution
{
public:
	bool wordBreak_Re(string s, vector<string> wordDict)
	{
		unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());    // 把vector类型转换成哈希表，方便查询
		return wordBreak_Re(s, dict);
	}

	// 递归
	bool wordBreak_Re(string s, unordered_set<string> dict)
	{
		// 递归结束条件
		if (memo.count(s))
			return memo[s];
		if (dict.count(s))
			return memo[s] = true;

		for (int i = 1; i < s.length(); ++i)
		{
			const string left = s.substr(0, i);    // [0,i)，从0开始的长度为i的子串
			const string right = s.substr(i);

			if (dict.count(right) && wordBreak_Re(left, dict))
				return memo[s] = true;
		}

		return memo[s] = false;
	}

private:
	unordered_map<string, bool> memo;

};



int main()
{
	string s = "leetcode";
	vector<string> wordDict = { "leet","co", "de" };

	// Solution solution;
	// bool flag = solution.wordBreak_Re(s, wordDict);
	bool flag = wordBreak_DP_2(s, wordDict);
	cout << flag << endl;

	return 0;
}