//-----------------------------------------------------------------------------
// 文 件 名: 50_01_第一个只出现一次的字符.cpp
// 作    者：adoredee
// 创建时间： 2019.07.20
// 描    述：50_01_第一个只出现一次的字符
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题50（一）：字符串中第一个只出现一次的字符
// 题目：在字符串中找出第一个只出现一次的字符。如输入"abaccdeff"，则输出
//     'b'。

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

char TheOnlyChar(vector<char>& ch)
{
	// 异常检测
	if (ch.empty())
		return '\0';

	unordered_map<char, size_t> counts;

	// 利用哈希表统计每个字符出现的次数
	for (size_t i = 0; i < ch.size(); ++i)
	{
		counts[ch[i]]++;
	}
	// 从中找出第一个次数为1的那个字符
	for (size_t i = 0; i < ch.size(); i++)
	{
		if (counts[ch[i]] == 1)
			return ch[i];
	}
	return '\0';
}

int main()
{
	// vector<char> ch = { 'a', 'b', 'b', 'c', 'd' };
	vector<char> ch;
	char chm;
	cout << "请输入一串字符串：";
	while (scanf("%c", &chm))    // 结束输入：1. 按一下Enter； 2. ctrl+Z；3. 再按两下Enter
	{
		ch.emplace_back(chm);
	}

	char a = TheOnlyChar(ch);

	cout << a << endl;

	return 0;
}