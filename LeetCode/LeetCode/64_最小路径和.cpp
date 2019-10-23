//-----------------------------------------------------------------------------
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.04.23
// ��    �������������
//-----------------------------------------------------------------------------
/*
����һ�������Ǹ������� m x n �������ҳ�һ�������Ͻǵ����½ǵ�·����ʹ��·���ϵ������ܺ�Ϊ��С��

˵����ÿ��ֻ�����»��������ƶ�һ����

ʾ��:

����:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
���: 7
����: ��Ϊ·�� 1��3��1��1��1 ���ܺ���С��
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
	// �����һ��
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
	// ����Ƕ��������ֵ
	vector<vector<int>> arr;
	int row, col;
	// ��������
	cin >> row;
	arr.resize(row);
	// ��������
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
			

	// ���������������
	//for (vector<vector<int>>::iterator i = arr.begin(); i != arr.end(); i++)
	//{
	//	for (vector<int>::iterator j = (*i).begin(); j != (*i).end(); j++)
	//	{
	//		cout << *j << " ";
	//	}
	//	cout << endl;
	//}

	cout << "������" << arr.size() << endl;
	cout << "������" << arr[0].size() << endl;

	cout << "���·��" << minPathSum(arr) <<endl;


	return 0;
}