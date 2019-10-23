//-----------------------------------------------------------------------------
// 文 件 名: 207_课程表_Topological_Sort.cpp
// 作    者：adoredee
// 创建时间：2019.09.04
// 描    述：课程表__Topological_Sort
// 版    本：
// 链    接：https://leetcode-cn.com/problems/course-schedule/
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------
#include <iostream>
#include <vector>

using namespace std;

bool DFS(vector<vector<int>>& graph, vector<int>& visit, int i);

// 拓扑排序
bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
{
	vector<vector<int>> graph(numCourses, vector<int>());
	vector<int> visit(numCourses, 0);
	for (auto a : prerequisites) 
	{
		graph[a[1]].push_back(a[0]);
	}
	for (int i = 0; i < numCourses; ++i) 
	{
		// states: 0 = unkonwn, 1 == visiting, 2 = visited
		if (DFS(graph, visit, i))    // 如果DFS返回true，证明有环，表示该DAG有环，
			return false;
	}
	return true;
}
bool DFS(vector<vector<int>>& graph, vector<int>& visit, int i)
{
	// 如果状态为visiting，表示有环
	if (visit[i] == 1) 
		return true;
	// 如果已经被访问过的点，证明无环
	if (visit[i] == 2) 
		return false;
	
	// 表示正在访问
	visit[i] = 1;

	// 访问该节点的邻居
	for (auto a : graph[i]) 
	{
		if (DFS(graph, visit, a))    // // 如果DFS返回true，证明有环，返回true
			return true;
	}
	// 如果该节点的邻居已经被访问完毕，该节点被标记为visited
	visit[i] = 2;

	return false;
}

int main()
{
	vector<vector<int>> prerequisites = { {1, 0}, {2, 1} };

	bool flags = canFinish(3, prerequisites);

	if (flags)
		cout << "true" << endl;
	else
		cout << "false" << endl;

	return 0;
}