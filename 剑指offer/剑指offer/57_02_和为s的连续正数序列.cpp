// 文 件 名: 57_02_和为s的连续正数序列.cpp
// 作    者：adoredee
// 创建时间： 2019.08.05
// 描    述：和为s的连续正数序列
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题57（二）：为s的连续正数序列
// 题目：输入一个正数s，打印出所有和为s的连续正数序列（至少含有两个数）。
//      例如输入15，由于1+2+3+4+5=4+5+6=7+8=15，所以结果打印出3个连续序列1～5、
//      4～6和7～8。

#include <iostream>
#include <vector>
using namespace std;

void PrintArr(int nSmall, int nBig)
{
	cout << nSmall << "~" << nBig << ": ";
	int nLength = nBig - nSmall + 1;

	if (nLength >= 10)
		cout << "序列过长，不宜显示。" << endl;
	else
	{
		for (int i = nSmall; i <= nBig; ++i)
			cout << i << " ";
		cout << endl;
	}

}

void FindTheSOfSequence(long long nGivenSum)
{
	int nSmall = 1;
	int nBig = 2;

	int nMid = (1 + nGivenSum) / 2;
	long nSum = nSmall + nBig;

	while (nSmall < nMid)
	{		
		if (nSum == nGivenSum)
		{
			PrintArr(nSmall, nBig);
			nSum -= nSmall;
			++nSmall;
		}
		else if (nSum < nGivenSum)
		{
			++nBig;
			nSum += nBig;
		}
		else
		{
			nSum -= nSmall;
			++nSmall;		
		}
			
	}
}

int main()
{
	cout << "输入s: ";
	long long val;
	cin >> val;

	cout << "和为s的连续正数序列如下：" << endl;
	FindTheSOfSequence(val);

	return 0;
}