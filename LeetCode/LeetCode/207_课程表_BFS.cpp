//-----------------------------------------------------------------------------
// 文 件 名: 207_课程表_BFS.cpp
// 作    者：adoredee
// 创建时间：2019.09.05
// 描    述：课程表_BFS
// 版    本：
// 链    接：https://leetcode-cn.com/problems/course-schedule/
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

	// 入度：有向图中某点作为图中边的终点的次数之和
	for (auto id : prerequisites)
	{
		graph[id[1]].push_back(id[0]);
		++inDegree[id[0]];
	}

	queue<int> q;

	for (int i = 0; i < inDegree.size(); ++i)
	{
		// 将所有入度为0的点放入队列中，即没有边指向该点
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
		// 若此时还有节点的入度不为0，则说明环存在
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