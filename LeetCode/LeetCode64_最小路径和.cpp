//-----------------------------------------------------------------------------
// 作    者：adoredee
// 创建时间：2019.04.23
// 描    述：最大子序列
//-----------------------------------------------------------------------------
/*
给定一个包含非负整数的 m x n 网格，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。

示例:

输入:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
输出: 7
解释: 因为路径 1→3→1→1→1 的总和最小。
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int minPathSum(vector<vector<int>>& grid)
{
	int row = grid.size();
	int col = grid[0].size();    // int col = grid.frony().size();

	vector<vector<int>> dp(row, vector<int>(col, 0));
	
	dp[0][0] = grid[0][0];
	cout << dp[0][0] << endl;
	// 计算第一行
	for (size_t i = 1; i < col; i++)
		dp[0][i] = grid[0][i] + dp[0][i - 1];

	for (size_t i = 1; i < row; i++)
		dp[i][0] = grid[i][0] + dp[i - 1][0];

 	for (size_t i = 1; i < row; i++)
		for (size_t j = 1; j < col; j++)
			dp[i][j] = min(grid[i][j] + dp[i - 1][j], grid[i][j] + dp[i][j - 1]);

	return dp[row - 1][col - 1];

}

int main()
{
	// 容器嵌套容器赋值
	vector<vector<int>> arr;
	int row, col;
	// 输入行数
	cin >> row;
	arr.resize(row);
	// 输入列数
	cin >> col;

	for (int i = 0; i < arr.size(); i++)
		arr[i].resize(col);

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
		{
			int a;
			cin >> a;
			arr[i][j] = a;
		}
			

	// 遍历容器里的数据
	//for (vector<vector<int>>::iterator i = arr.begin(); i != arr.end(); i++)
	//{
	//	for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); j++)
	//	{
	//		cout << *j << " ";
	//	}
	//	cout << endl;
	//}

	cout << "行数：" << arr.size() << endl;
	cout << "列数：" << arr[0].size() << endl;

	cout << "最短路径" << minPathSum(arr) <<endl;


	return 0;
}