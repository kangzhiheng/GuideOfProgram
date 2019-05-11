//-----------------------------------------------------------------------------
// 文 件 名: 20_表示数值的字符串.cpp
// 作    者：adoredee
// 创建时间：2019.05.11
// 描    述：表示数值的字符串
// 版    本：
//-----------------------------------------------------------------------------

// 面试题20：表示数值的字符串
// 题目：请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。例如，
//      字符串“+100”、“5e2”、“-123”、“3.1416”及“-1E-16”都表示数值，但“12e”、
//      “1a3.14”、“1.2.3”、“+-5”及“12e+5.4”都不是

/*
    注意：
    源代码有缺陷，如果出现类似 -.e2，也会判断为正确，故加了46和47两行判断语句
*/


#include <iostream>

using namespace std;

bool scanUnsignedInteger(const char **str);
bool scanInteger(const char** str);

/* 数字格式可以用 [A][.[B]][e|E][C]或者.B[e|E][C]表示
   A:有符号整数，+/-
   B:无符号整数表示小数部分
   C:有符号整数,表示指数，+/-
*/

bool scanUnsignedInteger(const char** str);
bool scanInteger(const char** str);

// 数字的格式可以用A[.[B]][e|EC]或者.B[e|EC]表示，其中A和C都是
// 整数（可以有正负号，也可以没有），而B是一个无符号整数
bool isNumeric(const char* str)
{
	// 异常处理
	if (str == nullptr)
		return false;

	// 1. 扫描A部分
	bool numeric = scanInteger(&str);
	// 如果是 -.e2 这种类型，则在A部分判断是false，此时就可以认为该字符串不可以表示一个数值
	if (numeric == false)
		return false;

	// 2. 判断A部分后是不是小数点，或者这个字符以小数点开始
	// 如果出现'.'，接下来是数字的小数部分B
	if (*str == '.')
	{
		++str;
		numeric = scanUnsignedInteger(&str) || numeric;
	}

	// 3. 判断A和B部分后是不是以e或者E开始
	if (*str == 'e' || *str == 'E')
	{
		++str;
		numeric = numeric && scanInteger(&str);
	}

	// 判断结束表示标志，numeric状态并且这个字符是否判断到最后一位
	return numeric && *str == '\0';

}

// 判断A或者C部分是否是有符号数，返回+/-后面的整数
bool scanInteger(const char** str)
{
	if (**str == '+' || **str == '-')
			++(*str);    // 如果str的第一个字符为 +/- 号，则地址向右移一位

	// 判断接下来的部分是否有若干数字
	return scanUnsignedInteger(str);
}

// 是否都是整数
bool scanUnsignedInteger(const char** str)
{
	const char* before = *str;    // 将*str的起始地址赋值给before
	// 还没有到字符串末尾，并且当前字符在0~9之间
	while (**str != '\0' && **str >= '0' && **str <= '9')
		++(*str);

	// 当*str中存在若干0~9的数字时，返回true
	// 为什么是大于号，因为字符串数组的里的元素的地址依次递增，所以后面元素的地址大于前面的，
	// 如果满足while循环体，则表示*str中存在若干0~9的数字，
	// 其跳出循环的元素的地址肯定大于最开始的地址，所以返回true
	return *str > before;
}

int main()
{
	const char* str = "1.1e1";

	if (isNumeric(str))
		cout << "该字符串可以表示为一个数值" << endl;
	else
		cout << "该字符串不可以表示为一个数值" << endl;

	return 0;
}