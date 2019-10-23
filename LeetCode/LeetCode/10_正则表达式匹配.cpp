//-----------------------------------------------------------------------------
// �� �� ��: 10_������ʽƥ��.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.09.16
// ��    ������Ծ��Ϸ������ʽƥ��
// ��    ����
// ��    �ӣ�https://leetcode-cn.com/problems/regular-expression-matching/solution/zheng-ze-biao-da-shi-pi-pei-dong-tai-gui-hua-by-jy/
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// �ο���https://leetcode-cn.com/problems/regular-expression-matching/solution/dong-tai-gui-hua-zen-yao-cong-0kai-shi-si-kao-da-b/


#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isMatch(string s, string p)
{
	// �쳣�ж�
	if (p.empty() && !s.empty())
		return false;
	if (p.empty() && s.empty())
		return true;
	if (!p.empty() && p[0] == '*')
		return false;

	int nLen_s = s.length() + 1, nLen_p = p.length() + 1;
	// DP[i][j]�������ַ���s��ǰi���ַ���p�е�ǰj���ַ��Ƿ�ƥ��
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
				// *����ǰ����ַ�����0��
				if (i == 0 || (s[i - 1] != p[j - 2] && p[j - 2] != '.'))
					DP[i][j] = DP[i][j - 2];
				else    // s[i - 1] == p[j -2] || p[j -2] == '.'����Ӧ����������ֱ���*����ǰ����ַ�����0�Σ�1�κ�2�μ�����
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