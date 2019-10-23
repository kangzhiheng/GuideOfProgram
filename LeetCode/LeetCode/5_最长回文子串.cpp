//-----------------------------------------------------------------------------
// �� �� ��:  5_������Ӵ�.cpp
// ��    �ߣ� adoredee
// ����ʱ�䣺  2019.09.09
// ��    ���� ������Ӵ�
// ��    ����
// ��    �ӣ� https://leetcode-cn.com/problems/longest-palindromic-substring/
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
		// ��������ɢ
		nL--;
		nR++;
	}

	return nR - nL - 1;
}

// ������չ
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

// ��̬�滮
string longestPalindrome_DP(string s)
{
	if (s.size() < 1)
		return s;

	int nLen = s.size();

	vector<vector<int>> dp(nLen, vector<int>(nLen, false));
	string res = s.substr(0, 1);
	int nMaxLen = 1;    // ��С���Ĵ�����

	// ��ʵ������������
	for (int r = 1; r < nLen; ++r)
	{
		for (int l = 0; l < r; ++l)
		{
			// ���� r - l <= 2��˵����
			// 1����ԭ�ַ�����Ԫ�ظ���Ϊ 33 ����ʱ��������ұ߽���ȣ���ôȥ�������Ժ�ֻʣ�� 1 ���ַ�����һ���ǻ��Ĵ���
			//    ��ԭ�ַ���Ҳһ���ǻ��Ĵ���
			// 2����ԭ�ַ�����Ԫ�ظ���Ϊ 22 ����ʱ��������ұ߽���ȣ���ôȥ�������Ժ�ֻʣ�� 0 ���ַ���
			//    ��Ȼԭ�ַ���Ҳһ���ǻ��Ĵ���
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
	// ��������
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