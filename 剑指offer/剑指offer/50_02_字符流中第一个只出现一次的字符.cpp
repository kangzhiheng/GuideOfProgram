//-----------------------------------------------------------------------------
// 文 件 名: 50_02_字符流中第一个只出现一次的字符.cpp
// 作    者：adoredee
// 创建时间： 2019.07.22
// 描    述：50_02_字符流中第一个只出现一次的字符
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题50（二）：字符流中第一个只出现一次的字符
// 题目：请实现一个函数用来找出字符流中第一个只出现一次的字符。例如，当从
//      字符流中只读出前两个字符"go"时，第一个只出现一次的字符是'g'。当从该字
//      符流中读出前六个字符"google"时，第一个只出现一次的字符是'l'。

#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class  CharStatistics
{
public:
	CharStatistics() : index(0)
	{
		for (int i = 0; i < 256; ++i)
			occurrence[i] = -1;
	}

	void Insert(char ch)
	{
		cout << ch << " ";
		if (occurrence[ch] == -1)    // 没有出现过
			occurrence[ch] = index;    // 等于索引值
		else if (occurrence[ch] >= 0)    // 再次出现，置于-2
			occurrence[ch] = -2;

		index++;
	}

	char FirstAppearingOnce()
	{
		char ch = '\0';
		int minIndex = numeric_limits<int>::max();    // 初始化minIndex为整型的最大值
		
		// 找出字符串中大于等于0的值对应的字符（确保这些数都是第一次出现）,且找到最小的索引值，才是第一次出现的只出现一次的字符
		for (int i = 0; i < 256; ++i)
		{
			if (occurrence[i] >= 0 && occurrence[i] < minIndex)
			{
				ch = (char)i;
				minIndex = occurrence[i];
			}
		}

		return ch;
	}

private:
	int occurrence[256];
	int index;
};

int main()
{
	CharStatistics chars;
	vector<char> chs;

	cout << "读取的字符流里的数据为：";
	chars.Insert('g');
	chars.Insert('o');
	cout << endl;

	char FirstChar = chars.FirstAppearingOnce();
	if (FirstChar == '\0')
		cout << "该字符流无只出现过一次的字符，请重新尝试。" << endl;
	else 
		cout << "此时的字符流中第一次只出现过一次的字符为：" << FirstChar << endl;

	cout << endl << "  字符流更新......" << endl;

	chars.Insert('o');
	chars.Insert('g');
	chars.Insert('l');
	chars.Insert('e');
	cout << endl;

	FirstChar = chars.FirstAppearingOnce();
	if (FirstChar == '\0')
		cout << "该字符流无只出现过一次的字符，请重新尝试。" << endl;
	else
		cout << "此时的字符流中第一次只出现过一次的字符为：" << FirstChar << endl;

	return 0;
}