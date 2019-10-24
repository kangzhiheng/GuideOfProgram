//-----------------------------------------------------------------------------
// 文 件 名: 130_被围绕的区域_BFS.cpp
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

// BFS 易理解，但超时
int movedirection[4][2] = { {-1, 0}, {1,0}, {0, -1}, {0, 1} };    // 定义移动的方向，上下左右

bool inBoard(vector<vector<char>>& board, int x, int y)
{
	if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size())
		return true;
	else
		return false;
}

void BFS(vector<vector<char>>& board, int x, int y, vector<vector<bool>>& visited)
{
	// 构建队列
	queue<pair<int, int>> q;
	q.push({ x,y });
	// q.push(make_pair(x, y));
	visited[x][y] = true;
	while (!q.empty())
	{
		int curX = q.front().first;
		int curY = q.front().second;
		q.pop();
		for (int i = 0; i < 4; ++i)
		{
			int newX = curX + movedirection[i][0];
			int newY = curY + movedirection[i][1];
			if (inBoard(board, newX, newY) && board[newX][newY] == 'O')
			{
				q.push(make_pair(newX, newY));
				visited[newX][newY] = true;
			}
		}
	}

	return;
}

void solve_BFS(vector<vector<char>>& board)
{
	if (board.empty() || board.size() < 0 || board[0].size() < 0)
		return;

	int rows = board.size();
	int cols = board[0].size();

	vector<vector<bool>> visited(rows, vector<bool>(cols, false));

	// 遍历左右两列
	for (int i = 0; i < rows; ++i)
	{
		if (board[i][0] == 'O')
		    BFS(board, i, 0, visited);
		if (board[i][cols - 1] == 'O')
			BFS(board, i, cols - 1, visited);
	}
	// 遍历上下两行
	for (int j = 0; j < cols; ++j)
	{
		if (board[0][j] == 'O')
			BFS(board, 0, j, visited);
		if (board[rows - 1][j] == 'O')
			BFS(board, rows - 1, j, visited);
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

	solve_BFS(board);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			cout << board[i][j] << " ";
		cout << endl;
	}

	return 0;
}