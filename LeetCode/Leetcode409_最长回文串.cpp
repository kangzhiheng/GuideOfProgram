//-----------------------------------------------------------------------------
// 作    者：adoredee
// 创建时间：2019.04.22
// 描    述：验证回文串
//-----------------------------------------------------------------------------
/*
    思路：统计每个字符出现的次数，两种情况：
	1. 都是偶数，次数全部相加即可，因为可以直接对称；
	2. 有奇数有偶数，字符出现的次数为偶数依然全部相加，字符出现的次数为奇数，
	   则，所有的奇数-1取为偶数，最后加个1即可，这个1为对称中心，即保留了最大奇数。
	
	例子：
	s = "aaabbxxxxx"
	a -> 3次
	b -> 2次
	x -> 5次
	构造最大回文串形式之一为 baxxxxxab，2 + (3 - 1) + (5 - 1) + 1 = 9，保留最大奇数。
*/

#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

int longestPalindrome(string s)
{
	unordered_map<int, int> counts;    // 字典，存放每个字符出现的次数
	for (int i = 0; i < s.size(); i++)
		counts[s[i]] += 1;                // 统计s里面的字符出现的个数

	bool hasoddnum = false;   // 是否有奇数
	int res = 0;   // 存放最大回文串长度
	for (unordered_map<int, int>::iterator it = counts.begin(); it != counts.end(); it++)
	{
		if (it->second % 2 != 0)    // 奇数
		{
			hasoddnum = true;
			res += it->second - 1;
		}
		else
			res += it->second;
	}

	return hasoddnum ? res + 1 : res;
}

int main()
{
	string s = "Aa";

	cout << longestPalindrome(s) << endl;

	return 0;
}