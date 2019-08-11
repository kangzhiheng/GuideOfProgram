// 文 件 名: 61_扑克牌中的顺子.cpp
// 作    者：adoredee
// 创建时间： 2019.08.10
// 描    述：扑克牌中的顺子
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//----------------------------------------------------------------------------- 

// 面试题61：扑克牌的顺子
// 题目：从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。
//      2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王可以看成任意数字。

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void PrintNum(vector<int>& aNum);

bool IsContinuous(vector<int>& aNumbers)
{
	// 异常判断
	if (aNumbers.empty() || aNumbers.size() < 5)
		return false;

	sort(aNumbers.begin(), aNumbers.end(), less<int>());    // less<int>()是从小到大排序，greater<int>()是从大到小排序

	// PrintNum(aNumbers);
	size_t nNumOfZero = 0;
	size_t nNumOfGap = 0;

	for (size_t i = 0; i < aNumbers.size() && aNumbers[i] == 0; ++i)
		++nNumOfZero;

	// 统计数组中的间隔数目
	size_t nSmall = nNumOfZero;
	size_t nBig = nSmall + 1;

	while (nBig < aNumbers.size())
	{
		// 两个数相等，有对子，不可能是顺子
		if (aNumbers[nSmall] == aNumbers[nBig])
			return false;

		/*
		   比如 { 0，1，2，5，6 }, 如果2和5要连续，则需要补 2(5 -2 - 1 = 2) 个0；
		   但是该数组有1个0，故该数组不能是顺子
		*/
		nNumOfGap += aNumbers[nBig] - aNumbers[nSmall] - 1;
		nSmall = nBig;
		++nBig;

	}

	return nNumOfGap > nNumOfZero ? false : true;
}

template <typename T>
void PrintNum(vector<T>& aNum)
{
	if (aNum.empty() || aNum.size() < 1)
		return;

	for (auto i : aNum)
		cout << i << " ";

	cout << endl;
}

// 将输入流中的数字转换成对应的数字
int read_ChartoInt()
{
	int value = 0;
	int ch;    // 对应的字符的ASCII码
	// 转换成从标准输入读入的数字，当我们得到一个非数字字符时就停止
	while ((ch = getchar()) != EOF && isdigit(ch))
	{
		value *= 10;		
		value += ch - '0'; 
	}
	// 把非数字字符退回到流中，这样它就不会丢失
	ungetc(ch, stdin);
	return value;
}

int main()
{
	vector<string> pStr;
	vector<int> aNum;
	string a;

	cout << "随机抽5张扑克牌（大小王可代表任何数，大小王为0，J为11，Q为12，K为13）：";
	for (size_t i = 0; i < 5; i++)
	{
		cin >> a;               // 输入5张扑克牌，1~10, A, J, Q, K
		pStr.emplace_back(a);
	}

	for (size_t i = 0; i < 5; i++)
	{
		if (pStr[i] == "A")
			aNum.emplace_back(0);
		else if (pStr[i] == "J")
			aNum.emplace_back(11);
		else if (pStr[i] == "Q")
			aNum.emplace_back(12);
		else if (pStr[i] == "K")
			aNum.emplace_back(13);
		else
			aNum.emplace_back(stoi(pStr[i]));    // stoi()，字符串转换成数字，"1234" —> 1234
	}

	bool b_flag = IsContinuous(aNum);    // 是不是顺子

	if (b_flag)
		cout << "恭喜，喜得顺子！" << endl;
	else
		cout << "不是顺子。" << endl;

	return 0;
}