//-----------------------------------------------------------------------------
// �� �� ��: 32_���Ч����_ջ.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.09.18
// ��    �������Ч����_ջ
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
#include <stack>

using namespace std;

int longestValidParentheses(string s)
{
	if (s.empty() || s.size() <= 1)
		return 0;

	int MaxLen = 0;

	stack<int> s_stack;
	s_stack.push(-1);

	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == '(')
			s_stack.push(i);
		else
		{
			// ����ջ��Ԫ��
			s_stack.pop();
			if (s_stack.empty())
				s_stack.push(i);
			else // ��ƥ���"("��һ���������
			    MaxLen = max(MaxLen, i - s_stack.top());
		}
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