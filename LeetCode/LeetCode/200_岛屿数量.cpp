//-----------------------------------------------------------------------------
// 文 件 名: 200_岛屿数量.cpp
// 作    者：adoredee
// 创建时间：2019.08.17
// 描    述：岛屿数量
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

//  给定一个由 '1'（陆地）和 '0'（水）组成的的二维网格，计算岛屿的数量。
//  一个岛被水包围，并且它是通过水平方向或垂直方向上相邻的陆地连接而成的。
//  你可以假设网格的四个边均被水包围。

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/* 参考：
        https://leetcode-cn.com/problems/number-of-islands/solution/yong-zei-ji-chu-de-cppyu-yan-stackdfs-by-youlookde/
        https://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-shu-liang-by-leetcode/
		https://leetcode-cn.com/problems/number-of-islands/solution/dfs-bfs-bing-cha-ji-python-dai-ma-java-dai-ma-by-l/
*/


// 判断点是否越界
bool inGrid(vector<vector<char>>& grid, pair<int, int> a)
{
	if (a.first >= 0 && a.first < grid.size() && a.second >= 0 && a.second < grid[0].size())
		return true;
	else
		return false;
}

int numIsIsland(vector<vector<char>>& grid)
{
	// 异常判断
	if (grid.empty())
		return 0;

	int res = 0;    // 统计陆地个数

	queue<pair<int, int>> po; 

	// BFS
	// 遍历地图上的每一个点
	for (size_t x = 0; x < grid.size(); ++x)
	{
		for (size_t y = 0; y < grid[0].size(); ++y)
		{
			if (grid[x][y] == '1')
			{
				po.push({ x, y });
				++res;    // 岛屿数量加1
				while (!po.empty())    // 进入广度优先搜索
				{ 
					pair<int, int> temp = po.front();    // 取队首元素
					po.pop();
					if (grid[temp.first][temp.second] == '0')    // 如果该点为海水，跳出循环
						continue;
					grid[temp.first][temp.second] = '0';
					pair<int, int> up = { temp.first - 1, temp.second };
					pair<int, int> down = { temp.first + 1, temp.second };
					pair<int, int> left = { temp.first, temp.second - 1 };
					pair<int, int> right = { temp.first, temp.second + 1 };

					if (inGrid(grid, up) && grid[up.first][up.second] == '1')
						po.push(up);
					if (inGrid(grid, down) && grid[down.first][down.second] == '1')
						po.push(down);
					if (inGrid(grid, left) && grid[left.first][left.second] == '1')
						po.push(left);
					if (inGrid(grid, right) && grid[right.first][right.second] == '1')
						po.push(right);

				}
			}
		}
	}

	return res;
}

int main()
{
	
	size_t nLength;
	size_t nWidth;

	cout << "请输入海域的长度：";
	cin >> nLength;
	cout << "请输入海域的宽度：";
	cin >> nWidth;

	vector<vector<char>> grid(nWidth, vector<char>(nLength));

	char nVal;
	for (size_t i = 0; i < nWidth; ++i)
		for (size_t j = 0; j < nLength; ++j)
		{
			cin >> nVal;
			grid[i][j] = nVal;
		}

	for (size_t i = 0; i < nWidth; ++i)
	{
		for (size_t j = 0; j < nLength; ++j)
			cout << grid[i][j] << " ";
		cout << endl;
	}

	int res = numIsIsland(grid);
	cout << "岛屿数量为：" << res << endl;

	return 0;
}