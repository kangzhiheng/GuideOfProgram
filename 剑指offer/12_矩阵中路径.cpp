//-----------------------------------------------------------------------------
// 文 件 名: 12_矩阵中路径.cpp
// 作    者：adoredee
// 创建时间：2019.05.07
// 描    述：矩阵中路径
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// 面试题12：矩阵中的路径
// 题目：请设计一个函数，用来判断在一个矩阵中是否存在一条包含某字符串所有
//      字符的路径。路径可以从矩阵中任意一格开始，每一步可以在矩阵中向左、右、
//      上、下移动一格。如果一条路径经过了矩阵的某一格，那么该路径不能再次进入
//      该格子。例如在下面的3×4的矩阵中包含一条字符串“bfce”的路径（路径中的字
//      母用下划线标出）。但矩阵中不包含字符串“abfb”的路径，因为字符串的第一个
//      字符b占据了矩阵中的第一行第二个格子之后，路径不能再次进入这个格子。
//      A B T G
//      C F C S
//      J D E H

/* 回溯法 */

#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

// 在matrix里寻找目标字符串
// matrix, 本为rows行cols列二维矩阵，现在将其拉直为长度为 rows * cols 的一行
bool hasPathCore(char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited);

// 将其理解为控制矩阵，控制查找步骤
bool hasPath(char* matrix, int rows, int cols, const char* str)
{
	// 异常处理
	if (matrix == nullptr || rows < 1 || cols < 1 || str == nullptr)
		return false;

	// 初始化visited所指向的内存空间
	bool *visited = new bool[rows * cols];
	/*
	函数原型是：void *memset(void *s, int ch, size_t n);
	函数功能是：将s所指向的某一块内存中的前n个字节的内容全部设置为ch指定的ASCII值
	*/
	memset(visited, 0, sizeof(bool) * (rows*cols));    // 将visited所指的前rows*cols字节内容全部替换成0，进行初始化

	int pathLength = 0;    // 正在匹配目标字符串的第几位

	// 从左上角开始查找
	for (int row = 0; row < rows; ++row)
	{
		for (int col = 0; col < cols; ++col)
		{
			// 若找到目标字符串
			if (hasPathCore(matrix, rows, cols, row, col, str, pathLength, visited))
				return true;
		}
	}

	delete[] visited;   // delete[] —— 调用visited里的每一个元素的析构函数

	// 没有找到，即为false
	return false;
}

bool hasPathCore(char* matrix, int rows, int cols, int row, int col, const char* str, int& pathLength, bool* visited)
{
	/*
	参数解释：
	1. matrix —— 字符串矩阵拉成的行向量，本为rows行cols列二维矩阵，现在将其拉直为长度为 rows * cols 的一行
	2. rows —— 字符矩阵的行数
	3. cols —— 字符矩阵的列数
	4. row —— 当前被查找的字符所在的行数，小于rows
	5. col —— 当前被查找的字符所在的列数，小于cols
	6. str —— 目标字符串
	7. pathLength —— 正在匹配目标字符串的第几位
	8. visited —— 是否被访问过
	*/
	
	/* if (pathLength == str.size() - 1)
	 	return true;*/
	if (str[pathLength] == '\0')
		return true;

	bool hasPath = false;

	if (row >= 0 && row < rows && col >= 0 && col < cols && matrix[row * cols + col] == str[pathLength] && !visited[row * cols + col])
	{
		++pathLength;    // 当前字符在目标矩阵里匹配成功
		visited[row * cols + col] = true;    // 当前字符被访问过

		hasPath = hasPathCore(matrix, rows, cols, row, col - 1, str, pathLength, visited)    // 当前匹配字符所在的目标矩阵里的位置的前一个。即左移
			   || hasPathCore(matrix, rows, cols, row, col + 1, str, pathLength, visited)    // 右移
			   || hasPathCore(matrix, rows, cols, row - 1, col, str, pathLength, visited)    // 上移
			   || hasPathCore(matrix, rows, cols, row + 1, col, str, pathLength, visited);   // 下移

		if (!hasPath)
		{
			--pathLength;    // 回溯，没有进一步找到目标值
			visited[row * cols + col] = false;
		}
	}

	return hasPath;
}

int main()
{
	cout << "请输入二维字符数组的行数 —> ";
	int rows;
	cin >> rows;

	cout << "请输入二维字符数组的列数 —> ";
	int cols;
	cin >> cols;

	cout << "请输入二维字符数组，用一维行向量表示: ";
	char *matrix = new char[rows * cols];    // 申请一块类型为char的长度为 rows*cols 的内存空间
	memset(matrix, 0, sizeof(char) * (rows * cols));
	for (int i = 0; i < rows * cols; ++i)
	{
		char ch;
		cin >> ch;
		matrix[i] = ch;
	}
	// 显示输入的数组
	/*for (int i = 0; i < rows * cols; ++i)
		cout << matrix[i];
	cout << endl;*/

	/*cout << "请输入要查找的目标字符串: ";
	vector<char> str;
	char a;
	while (scanf("%c", &a))
		str.emplace_back(a);*/
	/*for (int i = 0; i < str.size(); ++i)
		cout << str[i];
	cout << endl;*/

	const char* str = "bfce";

	bool flag = hasPath(matrix, rows, cols, str);
	if (flag)
		cout << endl << "在二维字符矩阵中存在目标字符串 ^_^ " << endl << endl;
	else
		cout << endl << "在二维字符矩阵中不存在目标字符串... " << endl << endl;

	delete[] matrix;  // 释放空间
}