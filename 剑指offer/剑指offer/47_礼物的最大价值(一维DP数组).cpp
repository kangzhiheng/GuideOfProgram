//-----------------------------------------------------------------------------
// �� �� ��:  47_���������ֵ.cpp
// ��    �ߣ� adoredee
// ����ʱ�䣺  2019.07.15
// ��    ���� ���������ֵ
// ��    ����
//-----------------------------------------------------------------------------

// ������47�����������ֵ
// ��Ŀ����һ��m��n�����̵�ÿһ�񶼷���һ�����ÿ�����ﶼ��һ���ļ�ֵ
//     ����ֵ����0��������Դ����̵����Ͻǿ�ʼ�ø�����������ÿ�������
//      �������ƶ�һ��ֱ���������̵����½ǡ�����һ�����̼��������������
//      ����������õ����ټ�ֵ�����


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int get_1DMaxValue(vector<vector<int>>& arr);
int get_2DMaxValue(vector<vector<int>>& arr);

// һά����洢
int get_1DMaxValue(vector<vector<int>>& arr)
{
	int row = arr.size();    // ���������
	int col = arr.size();    // ���������

	// �쳣���
	if (arr.empty() || row <= 0 || col <= 0)
		return 0;

	vector<int> DP_2D(col);

	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			if (i == 0 && j == 0)
				DP_2D[j] = arr[i][j];
			else if (i == 0 && j != 0)
			{
				DP_2D[j] = DP_2D[j - 1] + arr[i][j];
			}
			else if (j == 0 && i != 0)
			{
				DP_2D[j] = DP_2D[j] + arr[i][j];
			}
			else
				DP_2D[j] = arr[i][j] + max(DP_2D[j - 1], DP_2D[j]);
		}
	}
	return DP_2D[col - 1];
}

// ��ά����洢
int get_2DMaxValue(vector<vector<int>>& arr)
{
	int row = arr.size();
	int col = arr[0].size();
	// �쳣���
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
				DP_1D[i][j] = arr[i][j] + DP_1D[i][j - 1];    // �ڵ�һ��ʱ����ǰ���ݼ�����ߵ���
			else if (i != 0 && j == 0)
				DP_1D[i][j] = arr[i][j] + DP_1D[i - 1][j];    // �ڵ�һ��ʱ����ǰ���ݼ����ϱߵ���
			else
				DP_1D[i][j] = arr[i][j] + max(DP_1D[i - 1][j], DP_1D[i][j - 1]);
		}
	}

	return DP_1D[row - 1][col - 1];
}

int main()
{
	int row, col;
	cout << "�������ά�����������";
	cin >> row;
	cout << "�������ά�����������";
	cin >> col;

	vector<vector<int>> arr(row, vector<int>(col));

	cout << "������һ�� " << row << " x " << col << " �ľ���" << endl;
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j)
		{
			int val;
			cin >> val;
			arr[i][j] = val;
		}
	}

	cout << "���������ֵΪ������ά����������" << get_2DMaxValue(arr) << endl;
    cout << "���������ֵΪ����һά����������" << get_1DMaxValue(arr) << endl;


	return 0;
}
