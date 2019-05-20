//-----------------------------------------------------------------------------
// 文 件 名: 29_顺时针旋转矩阵.cpp
// 作    者：adoredee
// 创建时间：2019.05.20
// 描    述：顺时针旋转矩阵
// 版    本：
//-----------------------------------------------------------------------------

// 面试题29：顺时针打印矩阵
// 题目：输入一个矩阵，按照从外向里以顺时针的顺序依次打印出每一个数字。

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// 方法一：
void PrintSpiralMatrix(vector<vector<int>> matrix)
{
	// 异常处理
	if (matrix.empty())
		return;

	int top = 0;
	int bottom = matrix.size() - 1;    // 行数
	int left = 0;
	int right = matrix[0].size() - 1;    // 列数

	while (1)
	{
		// 从左向右打印
		if (left > right)
			break;
		for (int i = left; i <= right; i++)
			cout << matrix[top][i] << " ";
		top++;    // 下移一行

		// 从上到下打印
		if (top > bottom)
			break;
		for (int i = top; i <= bottom; i++)
			cout << matrix[i][bottom] << " ";
		right--;

		// 从右向左打印
		if (left > right)
			break;
		for (int i = right; i >= left; i--)
			cout << matrix[bottom][i] << " ";
		bottom--;

		// 从下到上打印
		for (int i = bottom; i >= top; i--)
			cout << matrix[i][left] << " ";
		left++;
	}

}

//方法二：
// 打印每一圈
void PrintMatrixInCircle(vector<vector<int>> matrix, int start)
{
	int rows = matrix.size();       // 行数
	int cols = matrix[0].size();    // 列数 

	int endX = cols - 1 - start;
	int endY = rows - 1 - start;

	// 从左到右打印一行
	for (int i = start; i <= endX; ++i)
		cout << matrix[start][i] << " ";

	// 从上到下打印一列
	if (start < endY)
	{
		for (int i = start + 1; i <= endY; ++i)
			cout << matrix[i][endX] << " ";
	}

	// 从右到左打印一行
	if (start < endX && start < endY)
	{
		for (int i = endX - 1; i >= start; --i)
			cout << matrix[endY][i] << " ";
	}

	// 从下到上打印一行
	if (start < endX && start < endY - 1)
	{
		for (int i = endY - 1; i >= start + 1; --i)
			cout << matrix[i][start] << " ";
	}
}

void PrintMatrixClockWise(vector<vector<int>> matrix)
{
	int rows = matrix.size();       // 行数
	int cols = matrix[0].size();    // 列数 
	// 异常处理
	if (matrix.empty() || rows <= 0 || cols <= 0)
		return;

	int start = 0;
	// 循环条件
	while (rows > start * 2 && cols > start * 2)
	{
		PrintMatrixInCircle(matrix, start);    // 打印每一圈
		++start;
	}
}

int main()
{
	int rows;
	cout << "请输入矩阵的行数：";
	cin >> rows;

	int cols;
	cout << "请输入矩阵的列数：";
	cin >> cols;

	vector<vector<int>> arr(rows, vector<int>(cols));

	cout << "请输入矩阵元素: ";
	for (int i = 0; i < rows; i++)
		for (int j = 0; j < cols; j++)
		{
			int value;
			cin >> value;
			arr[i][j] = value;
		}

	cout << "输入的矩阵为: " << endl;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << left << setw(5) << arr[i][j] << " ";    // 左对齐
		cout << endl;
	}

	cout << "顺时针打印螺旋矩阵: " << endl;
	cout << "方法一: ";
	PrintSpiralMatrix(arr);
	cout << endl;

	cout << "方法二: ";
	PrintMatrixClockWise(arr);
	cout << endl;

	return 0;
}