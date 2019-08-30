//-----------------------------------------------------------------------------
// 文 件 名:  46_把数字翻译成字符串.cpp
// 作    者： adoredee
// 创建时间：  2019.07.17
// 描    述： 把数字翻译成字符串
// 版    本：
//-----------------------------------------------------------------------------

// 面试题46：把数字翻译成字符串
// 题目：给定一个数字，我们按照如下规则把它翻译为字符串：0翻译成"a"，1翻
//      译成"b"，……，11翻译成"l"，……，25翻译成"z"。一个数字可能有多个翻译。例
//      如12258有5种不同的翻译，它们分别是"bccfi"、"bwfi"、"bczi"、"mcfi"和
//      "mzi"。请编程实现一个函数用来计算一个数字有多少种不同的翻译方法。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

// 重载函数
// int GetTranslationCount(int number);
void GetTranslationCount(const string& number);

//int GetTranslationCount(int number)
//{
//	// 异常检测
//	if (number < 0)
//		return 0;
//
//	string numberInString = to_string(number);
//
//	return GetTranslationCount(numberInString);
//}

void GetTranslationCount(const string& number)
{
	int length = number.length();
	int* kinds = new int[length];    // 记录从每个位置开始翻译的翻译种数
	int count = 0;

	for (int i = length - 1; i >= 0; --i) 
	{
		count = 0;
		if (i < length - 1)    // 从当前位置i开始翻译，包含了i+1位置的翻译种数
			count = kinds[i + 1];  // 末尾开始的翻译只有一种
		else
			count = 1;

		if (i < length - 1)    
		{
			int digit1 = number[i] - '0';
			int digit2 = number[i + 1] - '0';
			int converted = digit1 * 10 + digit2;       // 拼接i和i+1位置
			if (converted >= 10 && converted <= 25)     // 拼接的结果是否符合要求
			{
				if (i < length - 2)
					count += kinds[i + 2];    // 有点像斐波那契数列
				else
					count += 1;
			}
		}

		kinds[i] = count;    // 记录当前位置可以翻译的种数
		cout << kinds[i] << " ";
	}

	count = kinds[0];
	delete[] kinds;

	// return count;
}

int main()
{
	long number;
	cout << "请输入一个数字：";
	cin >> number;

	// int num = GetTranslationCount(number);
	string numberInString = to_string(number);
	GetTranslationCount(numberInString);
	// cout << number << "有" << num << "种不同的翻译方法。" << endl;

	return 0;
}