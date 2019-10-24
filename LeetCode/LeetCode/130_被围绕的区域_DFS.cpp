//-----------------------------------------------------------------------------
// 文 件 名: 130_被围绕的区域_DFS.cpp
// 作    者：adoredee
// 创建时间：2019.09.01
// 描    述：被围绕的区域
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------


// 给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
// 找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

// 参考链接：
// BFS https://blog.csdn.net/zjupeco/article/details/76376990
// DFS https://leetcode-cn.com/problems/surrounded-regions/solution/cbeats-9465easy-to-understand-by-zzyuting/
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// DFS
bool inBoard(vector<vector<char>>& board, int x, int y)
{
	if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size())
		return true;
	else
		return false;
}

void DFS(vector<vector<char>>& board, int x, int y, vector<vector<bool>>& visited)
{
	if (inBoard(board, x, y) && board[x][y] == 'O')
	{
		visited[x][y] = true;
		DFS(board, x - 1, y, visited);    // 上
		DFS(board, x + 1, y, visited);    // 下
		DFS(board, x, y - 1, visited);    // 左
		DFS(board, x, y + 1, visited);    // 右
	}
}

void solve_DFS(vector<vector<char>>& board)
{
	int rows = board.size();       // 行
	int cols = board[0].size();    // 列
	// 异常检测
	if (board.empty() || rows < 0 || cols < 0)
		return;

	vector<vector<bool>> visited(rows, vector<bool>(cols, false));

	// 左右两列
	for (int i = 0; i < rows; ++i)
	{
		if (board[i][0] == 'O')
			DFS(board, i, 0, visited);
		if (board[i][cols - 1] == 'O')
			DFS(board, i, cols - 1, visited);
	}

	// 上下两行
	for (int j = 0; j < cols; ++j)
	{
		if (board[0][j] == 'O')
			DFS(board, 0, j, visited);
		if (board[rows - 1][j] == 'O')
			DFS(board, rows - 1, j, visited);
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			if (board[i][j] == 'O' && visited[i][j] == false)
				board[i][j] = 'X';
		}
	}

	return;
}

int main()
{
	int rows, cols;
	cout << "设置区域的宽度：";
	cin >> rows;
	cout << "设置区域的高度：";
	cin >> cols;

	vector<vector<char>> board(rows, vector<char>(cols));
	char ch;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			cin >> ch;
			board[i][j] = ch;
		}
	}

	solve_DFS(board);

	cout << endl;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			cout << board[i][j] << " ";
		cout << endl;
	}

	return 0;
}