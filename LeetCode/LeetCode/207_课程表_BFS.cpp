//-----------------------------------------------------------------------------
// �� �� ��: 207_�γ̱�_BFS.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.09.05
// ��    �����γ̱�_BFS
// ��    ����
// ��    �ӣ�https://leetcode-cn.com/problems/course-schedule/
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
{
	vector<vector<int>> graph(numCourses, vector<int>());
	vector<int> inDegree(numCourses, 0);

	// ��ȣ�����ͼ��ĳ����Ϊͼ�бߵ��յ�Ĵ���֮��
	for (auto id : prerequisites)
	{
		graph[id[1]].push_back(id[0]);
		++inDegree[id[0]];
	}

	queue<int> q;

	for (int i = 0; i < inDegree.size(); ++i)
	{
		// ���������Ϊ0�ĵ��������У���û�б�ָ��õ�
		if (inDegree[i] == 0)
			q.push(i);
	}

	while (!q.empty())
	{
		int temp = q.front();
		q.pop();
		for (auto id : graph[temp])
		{
			--inDegree[id];
			if (inDegree[id] == 0)
				q.push(id);
		}
	}

	for (int i = 0; i < inDegree.size(); ++i)
	{
		// ����ʱ���нڵ����Ȳ�Ϊ0����˵��������
		if (inDegree[i] != 0)
			return false;
	}

	return true;
}

int main()
{
	vector<vector<int>> prerequisites = { { 1, 0 },{ 0, 1 } };

	bool flags = canFinish(3, prerequisites);

	if (flags)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	return 0;
}