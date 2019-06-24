//-----------------------------------------------------------------------------
// 文 件 名: 38_字符串的排列(无重复字符).cpp
// 作    者：adoredee
// 创建时间： 2019.06.21
// 描    述：字符串的排列
// 版    本：
//-----------------------------------------------------------------------------
// 面试题38：字符串的排列(无重复字符)
// 题目：输入一个无重复字符的字符串，打印出该字符串中字符的所有排列。例如输入字符串abc，
//      则打印出由字符a、b、c所能排列出来的所有字符串abc、acb、bac、bca、cab和cba。

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void Permutation(vector<char>& pStr, int pBegin, int pEnd);

// 全排列一个字符串
void Permutation(vector<char>& pStr)
{
	if (pStr.empty())
		return;

	// 字符串pStr的第 0 位何第 n-1 位的全排列
	Permutation(pStr, 0, pStr.size() - 1);
}

// 交换pStr里的第i和第j个位置的字符
void swap(vector<char>& pStr, int i, int j)
{
	swap(pStr[i], pStr[j]);
}

// 打印字符串
void PrintStr(vector<char>& pStr)
{
	for (int i = 0; i < pStr.size(); ++i)
		cout << pStr[i];
}

/*
    函数Permutation(vector<char>& pStr, int pBegin, int pEnd)
	表示对字符串pStr的 第pBegin个位置 与 第pEnd个位置 之间的子字符串进行全排列
    1. pStr指向字符串的第一个字符
    2. pBegin指向执行排列操作的第一个字符的位置
    3. pEnd指向执行操作的最后一个字符的位置
*/
void Permutation(vector<char>& pStr, int pBegin, int pEnd)
{
	if (pBegin == pEnd)
	{
		static int i = 1;
		cout << "第" << i++ << "个排列 —> ";
		PrintStr(pStr);
	}
	else
	{
		for (int pCh = pBegin; pCh < pEnd; ++pCh)
		{
			swap(pStr, pBegin, pCh);     // 依次将pBegin后面的每一个字符与pBegin进行交换
			Permutation(pStr, pBegin + 1, pEnd);    // 对pBegin后面的字符串进行全排列
			swap(pStr, pBegin, pCh);	 // 为了不重复排列，需还原
		}
	}
}

int main()
{
	vector<char> str;
	cout << "请输入字符串:";
	char a;
	while (scanf("%c", &a))
		str.emplace_back(a);
	cout << "字符串";
	PrintStr(str);
	cout << "的全排列为：" << endl;
	Permutation(str);

	return 0;
}