//-----------------------------------------------------------------------------
// �� �� ��: 130_��Χ�Ƶ�����_BFS.cpp
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

// BFS ����⣬����ʱ
int movedirection[4][2] = { {-1, 0}, {1,0}, {0, -1}, {0, 1} };    // �����ƶ��ķ�����������

bool inBoard(vector<vector<char>>& board, int x, int y)
{
	if (x >= 0 && x < board.size() && y >= 0 && y < board[0].size())
		return true;
	else
		return false;
}

void BFS(vector<vector<char>>& board, int x, int y, vector<vector<bool>>& visited)
{
	// ��������
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

	// ������������
	for (int i = 0; i < rows; ++i)
	{
		if (board[i][0] == 'O')
		    BFS(board, i, 0, visited);
		if (board[i][cols - 1] == 'O')
			BFS(board, i, cols - 1, visited);
	}
	// ������������
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

	solve_BFS(board);

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
			cout << board[i][j] << " ";
		cout << endl;
	}

	return 0;
}