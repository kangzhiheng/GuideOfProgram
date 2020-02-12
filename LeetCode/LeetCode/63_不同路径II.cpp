//-----------------------------------------------------------------------------
// 作    者：adoredee
// 创建时间： 2020.02.11
// 描    述：不同路径II
// 版    本：
// 链    接：https://leetcode-cn.com/problems/unique-paths-ii/
// Copyright (C) 2019 Shanghai Jiao Tong University

#include <iostream>
#include <vector>

using namespace std;

// 2D DP
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid)
{ 
	int m = obstacleGrid.size();     // 行
	int n = obstacleGrid[0].size();  // 列

	if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
		return 0;

	vector<vector<long>> DP(m, vector<long>(n));

	DP[0][0] = 1;
	// 初始化行列
	for (int i = 1; i < n; ++i)
		DP[0][i] = obstacleGrid[0][i] == 1 ? 0 : DP[0][i - 1];
	
	for (int j = 1; j < m; ++j)
		DP[j][0] = obstacleGrid[j][0] == 1 ? 0 : DP[j - 1][0]; 

	for (int i = 1; i < m; ++i)
	{
		for (int j = 1; j < n; ++j)
		{
			if (obstacleGrid[i][j] == 1)
				DP[i][j] = 0;
			else
				DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
		}
	}

	return DP[m - 1][n - 1];
}

// 1D DP
int uniquePathsWithObstacles_1D_DP(vector<vector<int>>& obstacleGrid)
{
	int m = obstacleGrid.size();
	int n = obstacleGrid[0].size();   // 列

	if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1)
		return 0;

	vector<long> DP(n);

	DP[0] = 1;

	for (int i = 1; i < n; ++i)
		DP[i] = obstacleGrid[0][i] == 1 ? 0 : DP[i - 1];

	for (int i = 1; i < m; ++i)
		for (int j = 0; j < n; ++j)
		{
			if (j == 0)
			{
				if (obstacleGrid[i][j] == 1)
					DP[j] = 0;
				else
					DP[j] = 1;
			}
			else
			{
				if (obstacleGrid[i][j] == 1)
					DP[j] = 0;
				else 
					DP[j] = DP[j] + DP[j - 1];
			}
				
		}

	return DP[n - 1];
}

int main()
{
	vector<vector<int>> grid = { {0,0},{0,0} };
	int res = uniquePathsWithObstacles_1D_DP(grid);
	cout << res << endl;
}