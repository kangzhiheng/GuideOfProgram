//-----------------------------------------------------------------------------
// 作    者：adoredee
// 创建时间：2019.04.12
// 描    述：合并两个有序数组
//-----------------------------------------------------------------------------
/*
给定两个有序整数数组 nums1 和 nums2，将 nums2 合并到 nums1 中，使得 num1 成为一个有序数组。

说明:

初始化 nums1 和 nums2 的元素数量分别为 m 和 n。
你可以假设 nums1 有足够的空间（空间大小大于或等于 m + n）来保存 nums2 中的元素。
示例:

输入:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

输出: [1,2,2,3,5,6]
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> printMatrix(vector<vector<int> > num)
{

	int cols = num[0].size();
	int rows = num.size();

	int stRow = 0;
	int stCol = 0;
	int edRow = rows - 1;
	int edCol = cols - 1;

	vector<int> m;

	// 矩阵分圈
	while (stRow <= edRow && stCol <= edCol)
	{
		//printEdge(matrix, res, stRow++, stCol++, edRow--, edCol--);
		// 只有一行
		if (stRow == edRow)
		{
			for (int i = stCol; i <= edCol; ++i)
			{
				//cout<<m[stRow][i]<<" ";
				m.push_back(num[stRow][i]);
			}
		}
		// 只有一列
		else if (stCol == edCol)·
		{
			for (int i = stRow; i <= edRow; ++i)
			{
				//cout<<m[i][stCol]<<" ";
				m.push_back(num[i][stCol]);
			}
		}
		// 一般情况
		else
		{
			int curRow = stRow;
			int curCol = stCol;

			// 遍历一行
			while (curCol != edCol)
			{
				//cout<<m[curRow][curCol++]<<" ";// curRow = stRow
				m.push_back(num[stRow][curCol++]);
			}
			// 接着遍历一列
			while (curRow != edRow)
			{
				//cout<<m[curRow++][curCol]<<" ";// curCol = edCol
				m.push_back(num[curRow++][edCol]);
			}
			// 又遍历一行
			while (curCol != stCol)
			{
				//cout<<m[curRow][curCol--]<<" ";// curRow = edRow
				m.push_back(num[edRow][curCol--]);
			}
			// 又遍历一列
			while (curRow != stRow)
			{
				//cout<<m[curRow--][curCol]<<" ";// curCol = stCol
				m.push_back(num[curRow--][stCol]);
			}
		}

		stRow++;
		edRow--;
		stCol++;
		edCol--;
	}

	return m;
}

int main(void)
{
	vector<vector<int>> num(2);
	vector<int> res;

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			num[i][j] = i + j + 1;
		}
	}

	res = printMatrix(num);

	return 0;
}


//#include<iostream>
//#include<vector>
//
//using namespace std;
//
//int main()
//{
//	cout << "我爱祖国" << endl;
//	vector<int> nums1 = {1, 2, 3, 0, 0, 0};
//	vector<int> nums2= { 1, 2, 5};
//	int m = 3, n = 3;
//	int len = m + n - 1;
//	--m;
//	--n;
//	while (m >= 0 && n >= 0)
//		nums1[len--] = nums1[m] > nums2[n] ? nums1[m--] : nums2[n--];
//	while (n >= 0)
//		nums1[len--] = nums2[n--];
//
//	return 0;
//
//}