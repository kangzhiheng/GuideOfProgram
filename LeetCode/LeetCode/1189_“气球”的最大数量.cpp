//-----------------------------------------------------------------------------
// 文 件 名: 1189_“气球”的最大数量.cpp
// 作    者：adoredee
// 创建时间： 2019.09.19
// 描    述：“气球”的最大数量
// 版    本：
// 链    接：https://leetcode-cn.com/problems/maximum-number-of-balloons/
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int maxNumberOfBalloons(string text)
{
	if (text.size() < 7)
		return 0;

	unordered_map<char, int> nums;

	for (int i = 0; i < text.size(); ++i)
	{
		if (text[i] == 'b' || 'a' || 'l' || 'o' || 'n')
		    nums[text[i]]++;
	}

	if (nums.size() < 5)
		return 0;

	return min(min(nums['a'], nums['b']), min(min(nums['l'] / 2, nums['o'] / 2), nums['n']));
}

int main()
{
	string str;
	cin >> str;

	int a = maxNumberOfBalloons(str);
	cout << a << endl;

	return 0;
}