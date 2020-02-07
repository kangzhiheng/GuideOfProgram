//-----------------------------------------------------------------------------
// ��    �ߣ�adoredee
// ����ʱ�䣺 2020.02.04
// ��    �����ж�������
// ��    ����
// ��    �ӣ�https://leetcode-cn.com/problems/is-subsequence/
//-----------------------------------------------------------------------------
// Copyright (C) 2020 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------		

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// ˫ָ��
bool isSubsequence_1(string s, string t)
{
	int i = 0, j = 0;
	while (i < s.size())
	{
		while (j < t.size() && s[i] != t[j])
			++j;
		if (j == t.size())
			return false;
		++i;
		++j;
	}

	return true;
}

// DP
bool isSubsequence_2(string s, string t)
{
	int s_len = s.size();
	int t_len = t.size();

	vector<vector<int>> DP(s_len + 1, vector<int>(t_len + 1));

	for (int i = 0; i <= t_len; ++i)
		DP[0][i] = 1;

	for (int i = 1; i <= s_len; ++i)
	{
		for (int j = 1; j <= t_len; ++j)
		{
			if (s[i - 1] == t[j - 1])
				DP[i][j] = DP[i - 1][j - 1];
			else
				DP[i][j] = DP[i][j - 1];
		}
	}

	return DP[s_len][t_len];
}

// ��ϣ��������չ����Դ��ģ�ַ���s
bool isSubsequence_3(string s, string t)
{
	// ��¼�ַ�����ÿ���ַ���λ��
	unordered_map<char, vector<int>> pos;
	for (int i = 0; i < t.size(); ++i)
		pos[t[i]].push_back(i);

	int i = 0, j = -1;
	while (i < s.size())
	{
		auto c = s[i];
		auto it = upper_bound(pos[c].begin(), pos[c].end(), j);    // �����׸�����j��Ԫ�صĵ����������򷵻ص�����pos[c].end()
		if (it == pos[c].end())
			return false;
		j = *it;
		++i;
	}
	return true;

}

int main()
{
	string s = "abc";
	string t = "ahabgdc";
	cout << isSubsequence_3(s, t) << endl;

	return 0;
}