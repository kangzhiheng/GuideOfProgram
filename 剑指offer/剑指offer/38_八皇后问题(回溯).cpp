//-----------------------------------------------------------------------------
// 文 件 名: 38_八皇后问题(回溯).cpp
// 作    者：adoredee
// 创建时间： 2019.06.25
// 描    述：八皇后问题(回溯)
// 版    本：
//-----------------------------------------------------------------------------

#include <iostream>

using namespace std;

#define Max 8    // max为棋盘最大坐标


int Queen[Max];    // 模拟二维键盘，数组下标代表行，数组元素值代表列
static int sum = 0;    // 记录所有情况 

void show() // 输出所有皇后的坐标
{
	++sum;
	cout << "第" << sum << "种解法：";
	for (int i = 0; i < Max; i++)
	{
		cout << "(" << i << "," << Queen[i] << ")";
	}
	cout << endl;
}

int check(int n) // 检查当前列能否放置皇后 
{
	for (int i = 0; i < n; i++) // 检查横排和对角线上是否可以放置皇后
	{
		if (Queen[i] == Queen[n] || (Queen[i] - Queen[n]) == (n - i) || (Queen[i] - Queen[n]) == (i - n))
		{
			return 1;
		}
	}
	return 0;
}

void EightQueen(int line) // 回溯尝试皇后位置,n为横坐标 
{
	for (int i = 0; i < Max; i++)
	{
		Queen[line] = i; // 将皇后摆到当前循环到的位置
		if (!check(line))
		{
			if (line == Max - 1)
			{
				show(); // 如果全部摆好，则输出所有皇后的坐标
			}
			else
			{
				EightQueen(line + 1); // 否则继续摆放下一个皇后
			}
		}
	}
}

int main()
{
	// 从横坐标为0开始依次尝试
	EightQueen(0);
	cout << Max << "皇后总共有" << sum << "种解法" << endl;
	system("pause");
	return 0;
}