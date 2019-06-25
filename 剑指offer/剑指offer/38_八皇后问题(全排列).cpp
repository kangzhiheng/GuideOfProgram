//-----------------------------------------------------------------------------
// 文 件 名: 38_八皇后问题(全排列).cpp
// 作    者：adoredee
// 创建时间： 2019.06.25
// 描    述：八皇后问题(全排列)
// 版    本：
//-----------------------------------------------------------------------------

#include <iostream>
#include <algorithm>
#include <vector>

#define Max 8

using namespace std;

static int TotalNums = 0;

void swap(vector<int>& pStr, int i, int j)
{
	swap(pStr[i], pStr[j]);
}

// 筛选符合条件的皇后
bool check(vector<int>& pStr)
{
	for (int i = 0; i < pStr.size(); i++)
	{
		for (int j = i + 1; j < pStr.size(); j++)
		{
			// 判断主对角线和副对角线上是否已经呗占领
			if (i - j == pStr[i] - pStr[j] || j - i == pStr[i] - pStr[j])
				return false;
		}
	}
	return true;
}

// 对8个皇后进行全排列，这样子就保证了每一行，每一列都互不相关
void Permutation(vector<int>& pStr, int pBegin, int pEnd)
{
	if (pBegin == pEnd)
	{
		if (check(pStr))
		{
			++TotalNums;
			cout << "第" << TotalNums << "种解法：";
			for (int i = 0; i < pStr.size(); ++i)
				cout << "(" << i << "," << pStr[i] << ") ";
			cout << endl;
		}
			
	}
	else
	{
		for (int pCh = pBegin; pCh < pEnd; ++pCh)
		{
			swap(pStr, pBegin, pCh);
			Permutation(pStr, pBegin + 1, pEnd);
			swap(pStr, pBegin, pCh);
		}
	}
}

void EightQuene()
{
	// 创建数组，下标表示行，元素值表示列
	vector<int> Queen;
	// 对数组Quene赋值0~7
	for (int i = 0; i < Max; ++i)
		Queen.emplace_back(i);
	// 对0~7进行全排列，并筛选符合条件的check()函数
	Permutation(Queen, 0, Max);
}

int main()
{
	// 八皇后问题
	EightQuene();
	cout << Max << "皇后总共有" << TotalNums << "种解法" << endl;

	return 0;
}