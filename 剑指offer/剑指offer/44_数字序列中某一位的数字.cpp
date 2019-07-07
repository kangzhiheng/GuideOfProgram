//-----------------------------------------------------------------------------
// 文 件 名: 44_数字序列中某一位的数字.cpp
// 作    者：adoredee
// 创建时间： 2019.07.07
// 描    述：数字序列中某一位的数字
// 版    本：
//-----------------------------------------------------------------------------

// 面试题44：数字序列中某一位的数字
// 题目：数字以0123456789101112131415…的格式序列化到一个字符序列中。在这
//      个序列中，第5位（从0开始计数）是5，第13位是1，第19位是4，等等。请写一
//      个函数求任意位对应的数字。

#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

// 得到m位的数字有几个，比如输入2，表示两位数(10~99)
/*
digit = 1, 0 ~ 9，10个
digit = 2, 10 ~ 99，100 - 10 = 90个
digit = 3, 100 ~ 999，1000 - 100 = 900个
digit = 4, 1000 ~ 9999，10000- 1000 = 9000个
*/
int CountOfInteger(int digit)
{
	if (digit == 1)
		return 10;

	return 9 * int(pow(10, digit - 1));
}

// m位数的起始值，比如digit=1,起始值为0，digit=2，起始值为10
int BeginNumber(int digit)
{
	if (digit = 1)
		return 0;
	else
		return (int)pow(10, digit - 1);
}

// 确定要找的数字位于某m位数中的第几位，从0开始算起
int DigitAtIndex(int index, int digit)
{
	int number = BeginNumber(digit) + index / digit;
	int IndexFromLeftToRight = digit - index % digit;    // 该位从左向右是第几位，1 ~ IndexFromLeftToRight
	for (int i = 1; i < IndexFromLeftToRight; ++i)
		number /= 10;

	return number % 10;
}

int DigitAtIndex(int index)
{
	if (index < 0)
		return -1;

	// digit表示几位数，默认一位数
	int digit = 1;

	while (true)
	{
		int numbers = CountOfInteger(digit);
		if (index < numbers * digit)
			return DigitAtIndex(index, digit);

		index -= digit * numbers;
		digit++;
	}
	
	return -1;
}


int main()
{
	int index;
	cout << "请输入索引值，从开始算起: ";
	cin >> index;

	int value = DigitAtIndex(index);

	cout << "第" << index << "位的值位: " << value << endl;

	return 0;
}