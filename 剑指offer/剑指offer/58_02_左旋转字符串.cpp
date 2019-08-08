// 文 件 名: 58_02_左旋转字符串.cpp
// 作    者：adoredee
// 创建时间： 2019.08.05
// 描    述：左旋转字符串
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题58（二）：左旋转字符串
// 题目：字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。
//      请定义一个函数实现字符串左旋转操作的功能。比如输入字符串"abcdefg"和数
//      字2，该函数将返回左旋转2位得到的结果"cdefgab"。

#include <iostream>

using namespace std;

void Reverse(char* pBegin, char* pEnd)
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

/*
     例如，abcdefg, 数字2
	 第一步，翻转字符串的前2位，得bacdefg;
	 第二步，翻转后面的字符串，得bagfedc;
	 第三步，翻转整个字符串，得cdefgab;

*/
char* LeftRotateString(char* pStr, int n)
{
	if (pStr == nullptr || n < 0 || n > strlen(pStr))
	{
		cout << "非法输入！" << endl;
		throw new std::exception("InValid Input!");
	}

	int nLength = static_cast<int>(strlen(pStr));
	
	char* pFirstStart = pStr;
	char* pFirsrtEnd = pStr + n - 1;
	
	char* pSecondStart = pStr + n;
	char* pSecondEnd = pStr + nLength - 1;

	Reverse(pFirstStart, pFirsrtEnd);    // 第一步，翻转前n位；
	Reverse(pSecondStart, pSecondEnd);   // 第二步，翻转剩余的位数；
	Reverse(pFirstStart, pSecondEnd);    // 第三步，翻转整个字符串；

	return pStr;
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
	char pStr[1000];
	cout << "请输入一个字符串：";
	cin.get(pStr, 1000);

	cout << "要从第二位开始翻转？";
	int n;
	cin >> n;

	cout << "翻转后的字符串为：";
	char* pResult = LeftRotateString(pStr, n);
	cout << pResult << endl;
	// PrintCharArr(pResult);

	return 0;
}