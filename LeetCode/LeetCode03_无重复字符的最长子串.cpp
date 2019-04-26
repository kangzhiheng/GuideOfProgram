//-----------------------------------------------------------------------------
// 作    者：adoredee
// 创建时间：2019.04.17
// 描    述：无重复字符的最长子串
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

/* 
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:

输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。
示例 2:

输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。
示例 3:

输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
*/

/*
    思路：滑动窗口思想
*/
/*
    坑：在本地IED运行正确，而在LeetCode里运行错误，很可能是类型转换问题，见line59.
*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <unordered_map>     // unordered_map是无序的，查询效率高

using namespace std;

#define _CRT_SECURE_NO_WARNINGS

// 方法一：使用unordered_map来实现哈希操作
int lengthOfLongestSubstring(vector<char>& s)
{
	int res;         // res记录最长无重复子串的长度
	size_t left = 0;    // left表示最左边的位置
	unordered_map<char, size_t> m;   // 无序的哈希表
	for (int i = 0; i < s.size(); i++)
	{
		left = max(left, m[s[i]]);
		m[s[i]] = i + 1;
		res = max(res, int(i - left + 1));    // 注意这里，LeetCode可能会在这一步出错，加一个强制类型转化
	}

	return res;
}


/*
// 方法二：常规操作，建立字符数组来实现哈希操作
int lengthOfLongestSubstring(vector<char>& s)
{
	int res;         // res记录最长无重复子串的长度
	int left = 0;    // left表示最左边的位置
	char m[256] = { 0 };    // 作用类似于哈希表，元素是否出现过
	for (int i = 0; i < s.size(); i++)
	{
		
		// 1. m[s[i]] == 0 这个条件表示s[i]从来没有被记录过
		// 2. m[s[i]] < left 表示s[i]已经被记录过，需要更新左边的临界值，跳转到else语句

		if (m[s[i]] == 0 || m[s[i]] < left)    // i表示最长无重复子串最右边的位置，left是最左边的位置
		{
			res = max(res, i - left + 1);
		}
		else
		{
			left = m[s[i]];                    // 因为该元素在前面出现过了，所以要更新元素的最新的位置
		}

		m[s[i]] = i + 1;    // 给每位元素打标签，从1开始
	}

	return res;
}
*/


int main()
{
	vector<char> str;
	char a;
	cout << "请输入一串字符串(依次按下回车键，Ctrl+z，回车键结束输入):" << endl;
	while (cin >> a)
	{
		str.push_back(a);
	}

	int nums = lengthOfLongestSubstring(str);

	cout << "该字符串最长无重复子串的长度为: " << nums << endl;

	return 0;
}