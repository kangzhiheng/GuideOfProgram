//-----------------------------------------------------------------------------
// �� �� ��: 130_��Χ�Ƶ�����_DFS.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.09.01
// ��    ������Χ�Ƶ�����
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------


// ����һ����ά�ľ��󣬰��� 'X' �� 'O'����ĸ O����
// �ҵ����б� 'X' Χ�Ƶ����򣬲�����Щ���������е� 'O' �� 'X' ��䡣

// �ο����ӣ�
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
		DFS(board, x - 1, y, visited);    // ��
		DFS(board, x + 1, y, visited);    // ��
		DFS(board, x, y - 1, visited);    // ��
		DFS(board, x, y + 1, visited);    // ��
	}
}

void solve_DFS(vector<vector<char>>& board)
{
	int rows = board.size();       // ��
	int cols = board[0].size();    // ��
	// �쳣���
	if (board.empty() || rows < 0 || cols < 0)
		return;

	vector<vector<bool>> visited(rows, vector<bool>(cols, false));

	// ��������
	for (int i = 0; i < rows; ++i)
	{
		if (board[i][0] == 'O')
			DFS(board, i, 0, visited);
		if (board[i][cols - 1] == 'O')
			DFS(board, i, cols - 1, visited);
	}

	// ��������
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
	cout << "��������Ŀ�ȣ�";
	cin >> rows;
	cout << "��������ĸ߶ȣ�";
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