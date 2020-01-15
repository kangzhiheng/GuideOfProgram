//-----------------------------------------------------------------------------
// ��    �ߣ�adoredee
// ����ʱ�䣺 2020.01.15
// ��    ������ͬ·��
// ��    ����
// ��    �ӣ�https://leetcode-cn.com/problems/unique-paths/
// Copyright (C) 2019 Shanghai Jiao Tong University

/*
˼·��
1. ����Ż������һ�����Ĳ������ǹ̶��ģ�����ܲ���Ҳ�ǹ̶��ģ�һ����Ҫ m + n - 2 ����
   ���ҵĲ���Ϊ m - 1�����µĲ���Ϊ n - 1������ܹ���C(m+n-2,m-1)����C(m+n-2,n-1)·��
2. ��̬�滮:2D DP�Ż�Ϊ1D DP
*/

#include <iostream>
#include <vector>

using namespace std;

// ��ά��̬�滮
int uniquePaths_DP_2D(int m, int n)
{
	// �쳣���
	if (m < 0 || n < 0)
		return 0;

	vector<vector<int>> DP(n, vector<int>(m));

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (i == 0 || j == 0)
				DP[i][j] = 1;
			else
			    DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
		}
	}

	return DP[n - 1][m - 1];
}

// һά��̬�滮
int uniquePaths_DP_1D(int m, int n)
{
	// �쳣���
	if (m < 0 || n < 0)
		return 0;

	vector<int> DP(m);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (i == 0 || j == 0)
				DP[j] = 1;
			else
				DP[j] = DP[j] + DP[j - 1];
		}
	}

	return DP[m - 1];
}

int main()
{
	int m, n;
	cin >> m >> n;

	int nPaths = uniquePaths_DP_1D(m, n);
	cout << nPaths << endl;

}