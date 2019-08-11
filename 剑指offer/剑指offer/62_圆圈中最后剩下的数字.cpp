// 文 件 名: 62_圆圈中最后剩下的数字.cpp
// 作    者：adoredee
// 创建时间： 2019.08.10
// 描    述：圆圈中最后剩下的数字
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//----------------------------------------------------------------------------- 

// 面试题62：圆圈中最后剩下的数字
// 题目：0, 1, …, n-1这n个数字排成一个圆圈，从数字0开始每次从这个圆圈里
//      删除第m个数字。求出这个圆圈里剩下的最后一个数字。

#include <iostream>
#include <list>
#include <vector>

using namespace std;

// 方法一：双向链表
int LastReamin_List(size_t n, size_t m)
{
	// 异常判断
	if (n < 1 || m < 1 || m > n)
		return -1;

	list<int> numbers;

	for (size_t i = 0; i < n; i++)
		numbers.emplace_back(i);

	list<int>::iterator current = numbers.begin();

	while (numbers.size() > 1)
	{
		for (size_t i = 1; i < m; ++i)
		{
			current++;
			if (current == numbers.end())
				current = numbers.begin();
		}

		list<int>::iterator next = ++current;   // 保存删除位置的下一个位置
		if (next == numbers.end())
			next = numbers.begin();

		--current;    // 回退到删除位置
		numbers.erase(current);
		current = next;
	}

	return *current;
}

// 方法二：找规律
/*
    参考： https://blog.csdn.net/u011500062/article/details/72855826
    先设f(n, m)表示n个数里第m个被删掉的数字，最终胜利者的编号
	   f(n-1, m)表示n-1个数里第m个被删除的数字，最终胜利者的编号，注意，胜利者本身不会改变，但是在圆圈中的下标会改变！
	再设 n = 5, m = 3, 则有
	f(5,3)  0 1 2 3 4    ——> 2 被删除，此时3作为下一轮的开始数字
	f(4,3)  3 4 0 1      ——> 0 被删除，此时1作为下一轮的开始数字
	f(3,3)  1 3 4        ——> 4 被删除，此时1作为下一轮的开始数字
	f(2,3)  1 3          ——> 1 被删除，此时3作为下一轮的开始数字
	f(1,3)  3            ——> 只剩一个数字3，满足条件
	至此，我们总结一下最后剩余的数字在各轮的下标
	f(5,3)  0 1 2 3 4    ——> 3的下标为3，f(5,3) = 3
	f(4,3)  3 4 0 1      ——> 3的下标为0，f(4,3) = 0
	f(3,3)  1 3 4        ——> 3的下标为1，f(3,3) = 1
	f(2,3)  1 3          ——> 3的下标为1，f(2,3) = 1
	f(1,3)  3            ——> 3的下标为0，f(1,3) = 0  
	由下到上推导可得，
	f(1,3) = 0                              = 0
	f(2,3) = (f(1,3) + 3) % 2 = (0 + 3) % 2 = 1
	f(3,3) = (f(2,3) + 3) % 3 = (1 + 3) % 3 = 1
	f(4,3) = (f(3,3) + 3) % 4 = (1 + 3) % 4 = 0
	f(5,3) = (f(4,3) + 3) % 5 = (0 + 3) % 5 = 3

	因此得到公式，f(n,m) = (f(n-1,m) + m) % (n-1), n>=2
*/

int LastReamin_Formula(size_t n, size_t m)
{
	// 异常判断
	if (n < 1 || m < 1 || m > n)
		return -1;

	int nLast = 0;
	for (size_t i = 2; i <= n; ++i)
	{
		nLast = (nLast + m) % i;
	}

	return nLast;
}

int main()
{
	int n;
	int m;
	cout << "原始环里的个数：";
	cin >> n;
	cout << "每次删除第几个位置：";
	cin >> m;

	int nLastNumber_list = LastReamin_List(n, m);
	int nLastNumber_Formula = LastReamin_Formula(n, m);
	cout << "该圆圈剩余的最后一个元素为：" << endl;
	cout << "双向链表法：\t" << nLastNumber_list << endl;
	cout << "找规律：\t" << nLastNumber_Formula << endl;

	return 0;
}