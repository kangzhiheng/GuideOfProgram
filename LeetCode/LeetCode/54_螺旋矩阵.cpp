//-----------------------------------------------------------------------------
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.04.23
// ��    ������������
//-----------------------------------------------------------------------------
/*
����һ������ m x n ��Ԫ�صľ���m ��, n �У����밴��˳ʱ������˳�򣬷��ؾ����е�����Ԫ�ء�

ʾ�� 1:

����:
[
[ 1, 2, 3 ],
[ 4, 5, 6 ],
[ 7, 8, 9 ]
]
���: [1,2,3,6,9,8,7,4,5]
ʾ�� 2:

����:
[
[1, 2, 3, 4],
[5, 6, 7, 8],
[9,10,11,12]
]
���: [1,2,3,4,8,12,11,10,9,5,6,7]

*/

#include <iostream>
#include <vector>

using namespace std;

// �ݹ飬ÿ�δ�ӡ�������������
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
		// �ϱ�
		for (int i = left; i <= right; ++i)
			spiramatrix.push_back(matrix[top][i]);
		if (++top > bottom)
			break;

		// �ұ�
		for (int i = top; i <= bottom; ++i)
			spiramatrix.push_back(matrix[i][right]);
		if (right-- < left)
			break;

		// �±�
		for (int i = right; i >= left; i--)
			spiramatrix.push_back(matrix[bottom][i]);
		if (--bottom < top)
			break;
		// ���
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