//-----------------------------------------------------------------------------
// 文 件 名: 10_正则表达式匹配.cpp
// 作    者：adoredee
// 创建时间： 2019.09.16
// 描    述：跳跃游戏正则表达式匹配
// 版    本：
// 链    接：https://leetcode-cn.com/problems/regular-expression-matching/solution/zheng-ze-biao-da-shi-pi-pei-dong-tai-gui-hua-by-jy/
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 参考：https://leetcode-cn.com/problems/regular-expression-matching/solution/dong-tai-gui-hua-zen-yao-cong-0kai-shi-si-kao-da-b/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isMatch(string s, string p)
{
	// 异常判断
	if (p.empty() && !s.empty())
		return false;
	if (p.empty() && s.empty())
		return true;
	if (!p.empty() && p[0] == '*')
		return false;

	int nLen_s = s.length() + 1, nLen_p = p.length() + 1;
	// DP[i][j]，代表字符串s的前i个字符和p中的前j个字符是否匹配
	vector<vector<bool>> DP(nLen_s, vector<bool>(nLen_p, false));

	DP[0][0] = true;

	for (int i = 0; i < nLen_s; ++i)
	{
		for (int j = 1; j < nLen_p; ++j)
		{
			if ((i > 0) && (p[j - 1] == '.' || p[j - 1] == s[i - 1]))
				DP[i][j] = DP[i - 1][j - 1];
			if (p[j - 1] == '*')
			{
				// *号让前面的字符出现0次
				if (i == 0 || (s[i - 1] != p[j - 2] && p[j - 2] != '.'))
					DP[i][j] = DP[i][j - 2];
				else    // s[i - 1] == p[j -2] || p[j -2] == '.'，对应三种情况，分别是*号让前面的字符出现0次，1次和2次及以上
					DP[i][j] = DP[i][j - 2] || DP[i][j - 1] || DP[i - 1][j];
			}
		}
	}

	return DP[nLen_s - 1][nLen_p - 1];
}

int main()
{
	string s = "", p = "c*";
	bool flags = isMatch(s, p);

	if (flags)
		cout << "true" << endl;
	else
		cout << "false" << endl;
	
	return 0;
}