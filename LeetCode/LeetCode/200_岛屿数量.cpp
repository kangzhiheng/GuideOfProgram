//-----------------------------------------------------------------------------
// �� �� ��: 200_��������.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.08.17
// ��    ������������
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

//  ����һ���� '1'��½�أ��� '0'��ˮ����ɵĵĶ�ά���񣬼��㵺���������
//  һ������ˮ��Χ����������ͨ��ˮƽ�����ֱ���������ڵ�½�����Ӷ��ɵġ�
//  ����Լ���������ĸ��߾���ˮ��Χ��

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

/* �ο���
        https://leetcode-cn.com/problems/number-of-islands/solution/yong-zei-ji-chu-de-cppyu-yan-stackdfs-by-youlookde/
        https://leetcode-cn.com/problems/number-of-islands/solution/dao-yu-shu-liang-by-leetcode/
		https://leetcode-cn.com/problems/number-of-islands/solution/dfs-bfs-bing-cha-ji-python-dai-ma-java-dai-ma-by-l/
*/


// �жϵ��Ƿ�Խ��
bool inGrid(vector<vector<char>>& grid, pair<int, int> a)
{
	if (a.first >= 0 && a.first < grid.size() && a.second >= 0 && a.second < grid[0].size())
		return true;
	else
		return false;
}

int numIsIsland(vector<vector<char>>& grid)
{
	// �쳣�ж�
	if (grid.empty())
		return 0;

	int res = 0;    // ͳ��½�ظ���

	queue<pair<int, int>> po; 

	// BFS
	// ������ͼ�ϵ�ÿһ����
	for (size_t x = 0; x < grid.size(); ++x)
	{
		for (size_t y = 0; y < grid[0].size(); ++y)
		{
			if (grid[x][y] == '1')
			{
				po.push({ x, y });
				++res;    // ����������1
				while (!po.empty())    // ��������������
				{ 
					pair<int, int> temp = po.front();    // ȡ����Ԫ��
					po.pop();
					if (grid[temp.first][temp.second] == '0')    // ����õ�Ϊ��ˮ������ѭ��
						continue;
					grid[temp.first][temp.second] = '0';
					pair<int, int> up = { temp.first - 1, temp.second };
					pair<int, int> down = { temp.first + 1, temp.second };
					pair<int, int> left = { temp.first, temp.second - 1 };
					pair<int, int> right = { temp.first, temp.second + 1 };

					if (inGrid(grid, up) && grid[up.first][up.second] == '1')
						po.push(up);
					if (inGrid(grid, down) && grid[down.first][down.second] == '1')
						po.push(down);
					if (inGrid(grid, left) && grid[left.first][left.second] == '1')
						po.push(left);
					if (inGrid(grid, right) && grid[right.first][right.second] == '1')
						po.push(right);

				}
			}
		}
	}

	return res;
}

int main()
{
	
	size_t nLength;
	size_t nWidth;

	cout << "�����뺣��ĳ��ȣ�";
	cin >> nLength;
	cout << "�����뺣��Ŀ�ȣ�";
	cin >> nWidth;

	vector<vector<char>> grid(nWidth, vector<char>(nLength));

	char nVal;
	for (size_t i = 0; i < nWidth; ++i)
		for (size_t j = 0; j < nLength; ++j)
		{
			cin >> nVal;
			grid[i][j] = nVal;
		}

	for (size_t i = 0; i < nWidth; ++i)
	{
		for (size_t j = 0; j < nLength; ++j)
			cout << grid[i][j] << " ";
		cout << endl;
	}

	int res = numIsIsland(grid);
	cout << "��������Ϊ��" << res << endl;

	return 0;
}