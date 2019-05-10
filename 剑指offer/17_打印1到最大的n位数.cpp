//-----------------------------------------------------------------------------
// 文 件 名: 17_打印1到最大的n位数.cpp
// 作    者：adoredee
// 创建时间：2019.05.10
// 描    述：打印1到最大的n位数
// 版    本：
//-----------------------------------------------------------------------------
// 面试题17：打印1到最大的n位数
// 题目：输入数字n，按顺序打印出从1最大的n位十进制数。比如输入3，则
//      打印出1、2、3一直到最大的3位数即999。

// 注意考虑大数问题


#include<iostream>

using namespace std;

void PrintNumber(char* number);    // 打印当前字符

// 方法一：数组模拟数字，解决大数问题(数字很大，无法用long long来存储，用数字模拟数字，防止溢出)
/* 
    数组的高位为数值的个位，比如
	数字 126,
	数组 number = {1, 2, 6};
	数组的高位number[3] = 6为数字126的个位
*/

// 当前字符加1 
bool Increment(char* number) 
{
	bool isOverflow = false;    // 最高位是否有进位
	int nTakeover = 0;          // 进位默认为0
	int nLength = strlen(number);   // 统计字符串长度
	for (int i = nLength - 1; i >= 0; i--)     // 从个位开始
	{
		int nSum = number[i] - '0' + nTakeover;    // 字符转换为数值

		if (i == nLength - 1)    
			nSum++;             // 数值个位加1

		if (nSum >= 10)     // 如果进位后大于等于10
		{
			if (i == 0)     // 到达最高位，即对99...999加1时，最大值产生进位，表明此时已经达到最大值
				isOverflow = true;
			else 
			{
				nSum -= 10;    // 
				nTakeover = 1;    // 
				number[i] = '0' + nSum;    // 
			}
		}
		else    // 没有进位，则当前位加完之后退出即可
		{
			number[i] = '0' + nSum;
			break;
		}
	}
	return isOverflow;
}

void Print1ToMaxOfNDigits_ArrayToNumber(int n)
{
	// 异常情况
	if (n <= 0) 
		return;
	char *number = new char[n + 1];    // 创建一个n+1的字符数组，多出来一个存储'\0'，表示字符串结束
	memset(number, '0', n);    // 初始化，每一位都设置为0
	number[n] = '\0';

	// 当进位后不为最大值99...999加1后的数字
	while (!Increment(number)) 
	{
		PrintNumber(number);
	}

	delete[]number;    // 释放内存
}


// 方法二：递归
void Print1ToMaxOfNDigits_RecursivelyCore(char* number, int length, int index)
{
	if (index == length - 1)
	{
		PrintNumber(number);
		return;
	}

	for (int i = 0; i < 10; ++i)
	{
		number[index + 1] = i + '0';
		Print1ToMaxOfNDigits_RecursivelyCore(number, length, index + 1);
	}
}

void Print1ToMaxOfNDigits_Recursively(int n)
{
	// 异常情况
	if (n <= 0)
		return;

	char* number = new char[n + 1];    // 创建一个n+1的字符数组，多出来一个存储'\0'，表示字符串结束
	number[n] = '\0';

	for (int i = 0; i < 10; ++i)
	{
		number[0] = i + '0';
		Print1ToMaxOfNDigits_RecursivelyCore(number, n, 0);
	}

	delete[] number;
}

/*—————————————————————— 公共函数 ——————————————————————*/
// 打印当前字符
// 字符串number表示一个数字，数字有若干个0开头
// 打印出这个数字，并忽略开头的0
void PrintNumber(char* number)
{
	bool isBeginning0 = true;          // 是否以0开头
	int nLength = strlen(number);      // 字符串长度

	for (int i = 0; i < nLength; i++)
	{
		/*
		比如字符为090，有效数字为90，第一个0无效，不输出
		*/
		if (isBeginning0 && number[i] != '0')    // 检查是否0是否为有效数字
			isBeginning0 = false;
		if (!isBeginning0)
			printf("%c", number[i]);    // 打印当前字符数组表示的数字
	}

	printf("\t");
}

int main()
{
	cout << "请输入一个整数: ";
	int value;
	cin >> value;
	// Print1ToMaxOfNDigits_ArrayToNumber(value);
	Print1ToMaxOfNDigits_Recursively(value);

	return 0;
}