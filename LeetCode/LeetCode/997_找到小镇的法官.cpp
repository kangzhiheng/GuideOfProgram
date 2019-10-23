//-----------------------------------------------------------------------------
// 文 件 名: 997_找到小镇的法官.cpp
// 作    者：adoredee
// 创建时间：2019.09.15
// 描    述：找到小镇的法官
// 版    本：
// 链接：https://leetcode-cn.com/problems/find-the-town-judge/
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int findJudge(int N, vector<vector<int>>& trust)
{
	// 如果该小镇只有一个法官，则返回1
	if (trust.empty() && N == 1)
		return 1;

	unordered_map<int, int> nums;    // 记录信任人和被信任人
	vector<int> flags(N, false);     // 初始化所有人的状态，都不被别人信任，即为false

	for (int i = 0; i != trust.size(); ++i)
	{
		nums[trust[i][1]]++;      // 统计被信任人的次数
		flags[trust[i][0] - 1] = true;    // 那么他所对应的这个就一定不可能是法官，该状态为false，注意减一，
	}
	int notTrust = 0;    // 统计不被信任的人
	int JudgeIndex = 0;     // 找到法官的索引，即不被信任的人索引
	for (int i = 0; i < N; ++i)
	{
		if (flags[i] == false)
		{
			++notTrust;
			if (notTrust > 1)     // 如果不被信任的人不是一个人，即返回-1
				return -1;
			JudgeIndex = i;       // 得到法官的索引
		}
	}
	if (notTrust == 1 && nums[JudgeIndex + 1] == N - 1)    // 法官的两个必须的条件，不被信任且其他人都信任他
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