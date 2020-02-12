//-----------------------------------------------------------------------------
// ��    �ߣ�adoredee
// ����ʱ�䣺 2020.02.12
// ��    ������ͬ�Ķ���������
// ��    ����
// ��    �ӣ�https://leetcode-cn.com/problems/unique-binary-search-trees/
// Copyright (C) 2019 Shanghai Jiao Tong University

#include <iostream>
#include <vector>

using namespace std;

// ��������
int numTrees(int n)
{
	vector<int> G(n + 1);
	G[0] = 1;
	G[1] = 1;

	for (int i = 2; i <= n; ++i)
	{
		for (int j = 1; j <= i; ++j)
		{
			G[i] += G[j - 1] * G[i - j];	// ��iΪ��ʱ�ĸ���
		}
	}

	return G[n];
}

int main()
{
	int n = 3;
	int nums = numTrees(n);
	cout << nums << endl;
}