//-----------------------------------------------------------------------------
// 文 件 名: 32_最长有效括号_DP.cpp
// 作    者：adoredee
// 创建时间： 2019.09.18
// 描    述：最长有效括号_DP
// 版    本：
// 链    接：https://leetcode-cn.com/problems/longest-valid-parentheses/
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

/*
    参考：
	1. https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode/
	2. https://leetcode-cn.com/problems/longest-valid-parentheses/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-7/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// DP[i]保存i位置处的有效括号长度
int longestValidParentheses(string s)
{
	if (s.empty() || s.size() <= 1)
		return 0;

	vector<int> DP(s.size(), 0);
	int MaxLen = 0;
	// 有效括号至少是两位
	for (int i = 1; i < s.size(); ++i)
	{
		// 一、s[i] = '(' 不可能是有效括号的结尾，直接赋值为0
		if (s[i] == '(')
			DP[i] = 0;
		// 二、s[i] = ')'
		else if (s[i] == ')')
		{
			// 2.1. s[i-1] = '(' && s[i] = ')' 
			if (s[i - 1] == '(')
			{
				// 如果 i < 2，直接加2，否则要加上该对括号前面的有效括号长度
				DP[i] = (i >= 2 ? DP[i - 2] : 0) + 2;
			}
			// 2.2 如果 s[i - 1] == ')' && s[i - DP[i - 1] - 1] == '('，有效
			// 解释：DP[i - 1]表示 i - 1 处的有效括号长度，i减去该值，再减去1，查看此时的索引值处是否为'('，如果是，则与i位置处的')'配对成功
			// 此时递推公式为 DP[i] = DP[i - 1] + 2 + DP[i - DP[i - 1] - 2]
			// 注意，DP[i - DP[i - 1] - 2]表示 i 位置左边的状态
			else if ((i - DP[i - 1] > 0) && s[i - 1] == ')' && s[i - DP[i - 1] - 1] == '(')
			{
				DP[i] = DP[i - 1] + 2 + ((i - DP[i - 1]) >= 2 ? DP[i - DP[i - 1] - 2] : 0);
			}
			else
				DP[i] = 0;
		}
		MaxLen = max(MaxLen, DP[i]);
	}

	return MaxLen;
}

int main()
{
	string str;
	cin >> str;

	int nMaxLen = longestValidParentheses(str);
	cout << nMaxLen << endl;

	return 0;
}