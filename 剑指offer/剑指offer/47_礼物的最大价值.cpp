//-----------------------------------------------------------------------------
// 文 件 名:  47_礼物的最大价值.cpp
// 作    者： adoredee
// 创建时间：  2019.07.15
// 描    述： 礼物的最大价值
// 版    本：
//-----------------------------------------------------------------------------

// 面试题47：礼物的最大价值
// 题目：在一个m×n的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值
//     （价值大于0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向左或
//      者向下移动一格直到到达棋盘的右下角。给定一个棋盘及其上面的礼物，请计
//      算你最多能拿到多少价值的礼物？


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 二维数组存储
int get_1DMaxValue(vector<vector<int>>& arr)
{
	int row = arr.size();
	int col = arr[0].size();
    // 异常检测
	if (arr.empty() || row <= 0 || col <= 0)
		return 0;

	vector<vector<int>> DP_1D(row, vector<int>(col));    // 

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (i == 0 && j == 0)
			    DP_1D[0][0] = arr[0][0];
			else if (i == 0 && j != 0)
				DP_1D[i][j] = arr[i][j] + DP_1D[i][j - 1];    // 在第一行时，当前数据加上左边的数
			else if (i != 0 && j == 0)
				DP_1D[i][j] = arr[i][j] + DP_1D[i - 1][j];    // 在第一列时，当前数据加上上边的数
			else
				DP_1D[i][j] = arr[i][j] + max(DP_1D[i - 1][j], DP_1D[i][j - 1]);
		}
	}

	return DP_1D[row - 1][col - 1];
}


int main()
{
	int row, col;
	cout << "请输入二维矩阵的行数：";
	cin >> row;
	cout << "请输入二维矩阵的列数：";
	cin >> col;

	vector<vector<int>> arr(row, vector<int>(col));

	cout << "请输入一个 " << row << " x " << col << " 的矩阵：" << endl;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			int val;
			cin >> val;
			arr[i][j] = val;
		}
	}

	cout << "礼物的最大价值为：" << get_1DMaxValue(arr) << endl;


	return 0;
}