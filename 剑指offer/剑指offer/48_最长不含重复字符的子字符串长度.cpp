//-----------------------------------------------------------------------------
// 文 件 名: 48_最长不含重复字符的子字符串长度.cpp
// 作    者：adoredee
// 创建时间： 2019.06.14
// 描    述：最长不含重复字符的子字符串长度
// 版    本：
//-----------------------------------------------------------------------------

// 面试题48：最长不含重复字符的子字符串
// 题目：请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子
//      字符串的长度。假设字符串中只包含从'a'到'z'的字符。

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

int g_InvalidInput = false;

int LongestSubArray(vector<char>& str)
{
	// 异常检测
	if (str.empty() || str.size() <= 0)
	{
		return 0;
		g_InvalidInput = true;
		cout << "非法字符串" << endl;
	}

	int res = 0;         // 记录无重复最大子字符串长度
	size_t left = 0;     // 无重复最大子字符串长度的最左边的位置

	unordered_map<char, size_t> nums;    // 建立哈希表，记录字符串内每一个字符最新出现的位置

	for (int i = 0; i < str.size(); i++)
	{
		// 更新无重复最大子字符串长度的最左边的位置，如果无重复字串，nums[str[i]] 
		left = max(left, nums[str[i]]);
		nums[str[i]] = i + 1;      // 记录str[i]最新的位置，+1 表明又出现了一次
		res = max(res, int(i - left + 1));
	}

	return res;
}

int main()
{
	cout << "请输入一串字符串：";
	char cElement;
	vector<char> str;
	while (scanf("%c", &cElement))
		str.emplace_back(cElement);

	for (int i = 0; i < str.size(); ++i)
		cout << str[i] << " ";
	cout << endl;

	int res = LongestSubArray(str);

	cout << res << endl;

	return 0;
}