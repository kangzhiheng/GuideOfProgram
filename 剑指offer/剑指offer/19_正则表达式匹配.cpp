//-----------------------------------------------------------------------------
// 文 件 名: 19_正则表达式匹配.cpp
// 作    者：adoredee
// 创建时间： 2019.09.16
// 描    述：正则表达式匹配
// 版    本：
//-----------------------------------------------------------------------------

// 面试题19：正则表达式匹配
// 题目：请实现一个函数用来匹配包含'.'和'*'的正则表达式。模式中的字符'.'
//      表示任意一个字符，而'*'表示它前面的字符可以出现任意次（含0次）。在本题
//      中，匹配是指字符串的所有字符匹配整个模式。例如，字符串"aaa"与模式"a.a"
//      和"ab*ac*a"匹配，但与"aa.a"及"ab*a"均不匹配。

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool match(const char* str, const char* pattern)
{
	string s(str);
	string p(pattern);

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
	const char* s = "";
	const char* p = "c*";
	bool flags = match(s, p);

	if (flags)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	return 0;
}