//-----------------------------------------------------------------------------
// �� �� ��: 207_�γ̱�_Topological_Sort.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.09.04
// ��    �����γ̱�__Topological_Sort
// ��    ����
// ��    �ӣ�https://leetcode-cn.com/problems/course-schedule/
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------
#include <iostream>
#include <vector>

using namespace std;

bool DFS(vector<vector<int>>& graph, vector<int>& visit, int i);

// ��������
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
		if (DFS(graph, visit, i))    // ���DFS����true��֤���л�����ʾ��DAG�л���
			return false;
	}
	return true;
}
bool DFS(vector<vector<int>>& graph, vector<int>& visit, int i)
{
	// ���״̬Ϊvisiting����ʾ�л�
	if (visit[i] == 1) 
		return true;
	// ����Ѿ������ʹ��ĵ㣬֤���޻�
	if (visit[i] == 2) 
		return false;
	
	// ��ʾ���ڷ���
	visit[i] = 1;

	// ���ʸýڵ���ھ�
	for (auto a : graph[i]) 
	{
		if (DFS(graph, visit, a))    // // ���DFS����true��֤���л�������true
			return true;
	}
	// ����ýڵ���ھ��Ѿ���������ϣ��ýڵ㱻���Ϊvisited
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