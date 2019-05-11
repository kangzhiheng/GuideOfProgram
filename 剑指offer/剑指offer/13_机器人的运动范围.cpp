//-----------------------------------------------------------------------------
// 文 件 名: 13_机器人的运动范围.cpp
// 作    者：adoredee
// 创建时间：2019.05.07
// 描    述：机器人的运动范围
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------
// 面试题13：机器人的运动范围
// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
//      每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
//      大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
//      但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

/* 回溯法 */

#include <iostream>

using namespace std;

int MovingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited);
// 检查机器人能否进入坐标为(row, col)的方格
bool check(int threshold, int rows, int cols, int row, int col, bool* visited);
// 得到一个数字的数位之和，比如31的位数之和为 3+1 = 4
int getDigitSum(int number);


int MovingCount(int threshold, int rows, int cols)
{
	// threshold —— 阈值

	if (threshold < 0 || rows <= 0 || cols <= 0)
		return 0;

	// 申请内存并初始化
	bool *visited = new bool[rows * cols];
	// memset(visited, 0, sizeof(bool) * (rows * cols));
	for (size_t i = 0; i < rows * cols; ++i)
		visited[i] = false;

	int counts = MovingCountCore(threshold, rows, cols, 0, 0, visited);

	delete[] visited;    // 释放内存

	return counts;
}

int MovingCountCore(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	int counts = 0;

	if (check(threshold, rows, cols, row, col, visited))
	{
		visited[row * cols + col] = true;

		// ++counts;    // 用这句话替代下面的1，有问题……
		// 当前坐标满足条件,加1
		counts = 1 + MovingCountCore(threshold, rows, cols, row, col - 1, visited)    // 左移
			       + MovingCountCore(threshold, rows, cols, row, col + 1, visited)    // 右移
			       + MovingCountCore(threshold, rows, cols, row - 1, col, visited)    // 上移
			       + MovingCountCore(threshold, rows, cols, row + 1, col, visited);   // 下移
	}

	return counts;
}

// 检查机器人能否进入坐标为(row, col)的方格
bool check(int threshold, int rows, int cols, int row, int col, bool* visited)
{
	if (row >= 0 && row < rows && col >= 0 && col < cols && getDigitSum(row) + getDigitSum(col) <= threshold && !visited[row * cols + col])
		return true;
	return false;
}

// 得到一个数字的数位之和，比如31的位数之和为 3+1 = 4
int getDigitSum(int number)
{
	int sum = 0;
	while (number > 0)
	{
		sum += number % 10;   // 取最低位
		number /= 10;         
	}

	return sum;
}

int main()
{
	cout << "请输入网格行数 —> ";
	int rows;
	cin >> rows;

	cout << "请输入网格列数 —> ";
	int cols;
	cin >> cols;

	cout << "阈值为 —> ";
	int threshold;
	cin >> threshold;

	int sum = MovingCount(threshold, rows, cols);
	cout << "机器人可以到达的格子数为 —> " << sum << endl;
	return 0;
}