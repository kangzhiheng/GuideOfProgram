// 文 件 名: 58_翻转单词顺序.cpp
// 作    者：adoredee
// 创建时间： 2019.08.05
// 描    述：翻转单词顺序
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题58（一）：翻转单词顺序
// 题目：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。
//      为简单起见，标点符号和普通字母一样处理。例如输入字符串"I am a student. "，
//      则输出"student. a am I"。

#include <iostream>
#include <algorithm>

using namespace std;

void Reverse(char *pBegin, char *pEnd)
{
	if (pBegin == nullptr || pEnd == nullptr)
		return;

	while (pBegin < pEnd)
	{
		swap(*pBegin, *pEnd);
		pBegin++;
		pEnd--;
	}
}

// 先翻转整个句子，再翻转单词
char* ReverseSentence(char* pData)
{
	// 异常处理
	if (pData == nullptr)
		return nullptr;

	char* pBegin = pData;

	char* pEnd = pData;

	while (*pEnd != '\0')
		pEnd++;
	pEnd--;

	// 翻转整个句子
	Reverse(pBegin, pEnd);

	// 翻转每个单词
	pBegin = pEnd = pData;
	while (*pBegin != '\0')    // '\0'为字符串结束符
	{
		if (*pBegin == ' ')
		{
			pBegin++;
			pEnd++;
		}
		else if (*pEnd == ' ' || *pEnd == '\0')
		{
			Reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		}
		else
		{
			pEnd++;
		}
	}

	return pData;
}

char* ReverseSentence1(char *pData)
{
	if (pData == nullptr)
		return nullptr;

	char *pBegin = pData;

	char *pEnd = pData;
	while (*pEnd != '\0')
		pEnd++;
	pEnd--;

	// 翻转整个句子
	Reverse(pBegin, pEnd);

	// 翻转句子中的每个单词
	pBegin = pEnd = pData;
	while (*pBegin != '\0')
	{
		if (*pBegin == ' ')
		{
			pBegin++;
			pEnd++;
		}
		else if (*pEnd == ' ' || *pEnd == '\0')
		{
			Reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		}
		else
			pEnd++;
	}
}

void PrintCharArr(char* inputs)
{
	// 异常检测
	if (inputs == nullptr)
	{
		cout << "空数组" << endl;
		return;
	}

	for (int i = 0; inputs[i] != '\0'; ++i)
	{
		cout << inputs[i];
	}
	cout << endl;
}

int main()
{
	// char inputs[] = "I am a Student.";
	cout << "请输入一个字符串：" << endl;
	char inputs[1000];
	cin.get(inputs, 1000);

	cout << "该字符串为：";
	PrintCharArr(inputs);

	cout << "翻转单词顺序：";
	char* ReverseSe = ReverseSentence(inputs);
	PrintCharArr(ReverseSe);

	return 0;
}