//-----------------------------------------------------------------------------
// 文 件 名:  5_最长回文子串.cpp
// 作    者： adoredee
// 创建时间：  2019.09.09
// 描    述： 最长回文子串
// 版    本：
// 链    接： https://leetcode-cn.com/problems/longest-palindromic-substring/
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int expandAroundCenter(string s, int left, int right)
{
	int nL = left, nR = right;

	while (nL >= 0 && nR < s.length() && s[nL] == s[nR])
	{
		// 向两边扩散
		nL--;
		nR++;
	}

	return nR - nL - 1;
}

// 中心扩展
string longestPalindrome_MidEx(string s)
{
	if (s.length() < 1)
		return s;

	int start = 0, end = 0;

	for (int i = 0; i < s.length(); ++i)
	{
		int len_odd = expandAroundCenter(s, i, i);
		int len_even = expandAroundCenter(s, i, i + 1);
		int len = max(len_odd, len_even);
		if (len > end - start)
		{
			start = i - (len - 1) / 2;
			end = i + len / 2;
		}
	}

	return s.substr(start, end - start + 1);
}

// 动态规划
string longestPalindrome_DP(string s)
{
	if (s.size() < 1)
		return s;

	int nLen = s.size();

	vector<vector<int>> dp(nLen, vector<int>(nLen, false));
	string res = s.substr(0, 1);
	int nMaxLen = 1;    // 最小回文串长度

	// 其实构成了上三角
	for (int r = 1; r < nLen; ++r)
	{
		for (int l = 0; l < r; ++l)
		{
			// 关于 r - l <= 2的说明：
			// 1、当原字符串的元素个数为 33 个的时候，如果左右边界相等，那么去掉它们以后，只剩下 1 个字符，它一定是回文串，
			//    故原字符串也一定是回文串；
			// 2、当原字符串的元素个数为 22 个的时候，如果左右边界相等，那么去掉它们以后，只剩下 0 个字符，
			//    显然原字符串也一定是回文串。
			if (s[l] == s[r] && (r - l <= 2 || dp[l + 1][r - 1]))
			{
				dp[l][r] = true;
				int cur_len = r - l + 1;
				if (cur_len > nMaxLen)
				{
					nMaxLen = cur_len;
					res = s.substr(l, nMaxLen);
				}
			}

		}
	}
	// 测试用例
	//for (int i = 0; i < nLen; ++i)
	//{
	//	for (int j = 0; j < nLen; ++j)
	//		cout << dp[i][j] << " ";
	//	cout << endl;
	//}

	return res;
}

int main()
{
	string str = "acbababcd";

	// string s = longestPalindrome_DP(str);
	string s = longestPalindrome_MidEx(str);

	cout << s << endl;

	return 0;
}