//-----------------------------------------------------------------------------
// �� �� ��: 32_���Ч����_DP.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.09.18
// ��    �������Ч����_DP
// ��    ����
// ��    �ӣ�https://leetcode-cn.com/problems/longest-valid-parentheses/
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

/*
    �ο���
	1. https://leetcode-cn.com/problems/longest-valid-parentheses/solution/zui-chang-you-xiao-gua-hao-by-leetcode/
	2. https://leetcode-cn.com/problems/longest-valid-parentheses/solution/xiang-xi-tong-su-de-si-lu-fen-xi-duo-jie-fa-by-w-7/
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// DP[i]����iλ�ô�����Ч���ų���
int longestValidParentheses(string s)
{
	if (s.empty() || s.size() <= 1)
		return 0;

	vector<int> DP(s.size(), 0);
	int MaxLen = 0;
	// ��Ч������������λ
	for (int i = 1; i < s.size(); ++i)
	{
		// һ��s[i] = '(' ����������Ч���ŵĽ�β��ֱ�Ӹ�ֵΪ0
		if (s[i] == '(')
			DP[i] = 0;
		// ����s[i] = ')'
		else if (s[i] == ')')
		{
			// 2.1. s[i-1] = '(' && s[i] = ')' 
			if (s[i - 1] == '(')
			{
				// ��� i < 2��ֱ�Ӽ�2������Ҫ���ϸö�����ǰ�����Ч���ų���
				DP[i] = (i >= 2 ? DP[i - 2] : 0) + 2;
			}
			// 2.2 ��� s[i - 1] == ')' && s[i - DP[i - 1] - 1] == '('����Ч
			// ���ͣ�DP[i - 1]��ʾ i - 1 ������Ч���ų��ȣ�i��ȥ��ֵ���ټ�ȥ1���鿴��ʱ������ֵ���Ƿ�Ϊ'('������ǣ�����iλ�ô���')'��Գɹ�
			// ��ʱ���ƹ�ʽΪ DP[i] = DP[i - 1] + 2 + DP[i - DP[i - 1] - 2]
			// ע�⣬DP[i - DP[i - 1] - 2]��ʾ i λ����ߵ�״̬
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