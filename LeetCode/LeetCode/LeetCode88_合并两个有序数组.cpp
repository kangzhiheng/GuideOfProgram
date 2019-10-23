//-----------------------------------------------------------------------------
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.04.12
// ��    �����ϲ�������������
//-----------------------------------------------------------------------------
/*
�������������������� nums1 �� nums2���� nums2 �ϲ��� nums1 �У�ʹ�� num1 ��Ϊһ���������顣

˵��:

��ʼ�� nums1 �� nums2 ��Ԫ�������ֱ�Ϊ m �� n��
����Լ��� nums1 ���㹻�Ŀռ䣨�ռ��С���ڻ���� m + n�������� nums2 �е�Ԫ�ء�
ʾ��:

����:
nums1 = [1,2,3,0,0,0], m = 3
nums2 = [2,5,6],       n = 3

���: [1,2,2,3,5,6]
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

	// �����Ȧ
	while (stRow <= edRow && stCol <= edCol)
	{
		//printEdge(matrix, res, stRow++, stCol++, edRow--, edCol--);
		// ֻ��һ��
		if (stRow == edRow)
		{
			for (int i = stCol; i <= edCol; ++i)
			{
				//cout<<m[stRow][i]<<" ";
				m.push_back(num[stRow][i]);
			}
		}
		// ֻ��һ��
		else if (stCol == edCol)��
		{
			for (int i = stRow; i <= edRow; ++i)
			{
				//cout<<m[i][stCol]<<" ";
				m.push_back(num[i][stCol]);
			}
		}
		// һ�����
		else
		{
			int curRow = stRow;
			int curCol = stCol;

			// ����һ��
			while (curCol != edCol)
			{
				//cout<<m[curRow][curCol++]<<" ";// curRow = stRow
				m.push_back(num[stRow][curCol++]);
			}
			// ���ű���һ��
			while (curRow != edRow)
			{
				//cout<<m[curRow++][curCol]<<" ";// curCol = edCol
				m.push_back(num[curRow++][edCol]);
			}
			// �ֱ���һ��
			while (curCol != stCol)
			{
				//cout<<m[curRow][curCol--]<<" ";// curRow = edRow
				m.push_back(num[edRow][curCol--]);
			}
			// �ֱ���һ��
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
//	cout << "�Ұ����" << endl;
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