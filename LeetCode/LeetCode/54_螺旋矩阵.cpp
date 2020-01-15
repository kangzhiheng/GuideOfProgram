//-----------------------------------------------------------------------------
// 作    者：adoredee
// 创建时间：2019.04.23
// 描    述：螺旋矩阵
//-----------------------------------------------------------------------------
/*
给定一个包含 m x n 个元素的矩阵（m 行, n 列），请按照顺时针螺旋顺序，返回矩阵中的所有元素。

示例 1:

输入:
[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
输出: [1,2,3,6,9,8,7,4,5]
示例 2:

输入:
[
[1, 2, 3, 4],
[5, 6, 7, 8],
[9,10,11,12]
]
输出: [1,2,3,4,8,12,11,10,9,5,6,7]

*/

#include <iostream>
#include <vector>

using namespace std;

// 递归，每次打印最外面的那条边
vector<int> spiralOrder(vector<vector<int>>& matrix)
{
	if (matrix.empty())
		return {};

	int top = 0;
	int bottom = matrix.size() - 1;
	int left = 0;
	int right = matrix[0].size() - 1;

	vector<int> spiramatrix;

	while (1)
	{
		// 上边
		for (int i = left; i <= right; ++i)
			spiramatrix.push_back(matrix[top][i]);
		if (++top > bottom)
			break;

		// 右边
		for (int i = top; i <= bottom; ++i)
			spiramatrix.push_back(matrix[i][right]);
		if (right-- < left)
			break;

		// 下边
		for (int i = right; i >= left; i--)
			spiramatrix.push_back(matrix[bottom][i]);
		if (--bottom < top)
			break;
		// 左边
		for (int i = bottom; i >= top; i--)
			spiramatrix.push_back(matrix[i][left]);
		if (++left > right)
			break;
	}

	return spiramatrix;
}

int main()
{
	int row;
	cin >> row;
	int col;
	cin >> col;
	vector<vector<int>> arr(row, vector<int>(col));
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			int val;
			cin >> val;
			arr[i][j] = val;
		}
	}

	vector<int> arrs = spiralOrder(arr);
	for (int i = 0; i < arrs.size(); ++i)
		cout << arrs[i] << " ";

	return 0;
}