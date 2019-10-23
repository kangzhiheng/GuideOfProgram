//-----------------------------------------------------------------------------
// �� �� ��: 997_�ҵ�С��ķ���.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.09.15
// ��    �����ҵ�С��ķ���
// ��    ����
// ���ӣ�https://leetcode-cn.com/problems/find-the-town-judge/
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findJudge(int N, vector<vector<int>>& trust)
{
	// �����С��ֻ��һ�����٣��򷵻�1
	if (trust.empty() && N == 1)
		return 1;

	unordered_map<int, int> nums;    // ��¼�����˺ͱ�������
	vector<int> flags(N, false);     // ��ʼ�������˵�״̬���������������Σ���Ϊfalse

	for (int i = 0; i != trust.size(); ++i)
	{
		nums[trust[i][1]]++;      // ͳ�Ʊ������˵Ĵ���
		flags[trust[i][0] - 1] = true;    // ��ô������Ӧ�������һ���������Ƿ��٣���״̬Ϊfalse��ע���һ��
	}
	int notTrust = 0;    // ͳ�Ʋ������ε���
	int JudgeIndex = 0;     // �ҵ����ٵ����������������ε�������
	for (int i = 0; i < N; ++i)
	{
		if (flags[i] == false)
		{
			++notTrust;
			if (notTrust > 1)     // ����������ε��˲���һ���ˣ�������-1
				return -1;
			JudgeIndex = i;       // �õ����ٵ�����
		}
	}
	if (notTrust == 1 && nums[JudgeIndex + 1] == N - 1)    // ���ٵ�������������������������������˶�������
		return JudgeIndex + 1;
	else
		return -1;
			
}

int main()
{
	int N;
	cin >> N;

	vector<vector<int>> trust;
	vector<int> temps(2);
	int left, right;
	while (cin >> left >> right)
	{
		temps[0] = left;
		temps[1] = right;
		trust.push_back(temps);
	}

	int a = findJudge(N, trust);
	//for (int i = 0; i < trust.size(); ++i)
	//	cout << trust[i][0] << " " << trust[i][1] << endl;

	cout << a << endl;

	return 0;
}