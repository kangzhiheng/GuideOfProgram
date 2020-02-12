//-----------------------------------------------------------------------------
// ��    �ߣ�adoredee
// ����ʱ�䣺 2020.02.12
// ��    �������ʲ��
// ��    ����
// ��    �ӣ�https://leetcode-cn.com/problems/word-break/
// Copyright (C) 2019 Shanghai Jiao Tong University

#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>    // ��ϣ
#include <unordered_map>

using namespace std;

// ��̬�滮��https://www.youtube.com/watch?v=il8Oi21WZN0
// ���䷨�ݹ飺https://www.youtube.com/watch?v=ptlwluzeC1I

// ��̬�滮����һ
bool wordBreak_DP_1(string s, vector<string> wordDict)
{
	unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());    // ��vector����ת���ɹ�ϣ�������ѯ
	int n = s.length();
	s = " " + s;
	vector<int> DP(n + 1, 0);    // ���Ƽ�ʹ��vector<bool>
	DP[0] = 1;

	// ��Լ��o(n^3)�η����Ӷ�
	for (int i = 0; i <=n ; ++i)
	{
		for (int j = 0; j < i; ++j)
		{
			if (DP[j] == 1)
			{
				const string new_s = s.substr(j + 1, i- j);    // i - (j + 1) + 1
				if (dict.count(new_s))    // ��ѯ�ұ��·ָ�������Ӵ��Ƿ��ڹ�ϣ����
				{
					DP[i] = 1;
					break;
				}
			}
		}
	}

	return DP[n];
}

// ��̬�滮������
bool wordBreak_DP_2(string s, vector<string> wordDict)
{
	vector<int> DP(s.size() + 1, 0);
	DP[0] = 1;
	for (int i = 0; i <= s.size(); ++i)
	{
		for (auto word : wordDict)
		{
			int wordsize = word.size();
			if (i - wordsize >= 0)
			{
				int com = s.compare(i - wordsize, wordsize, word);    // s1.compare(ix,len,s2),��s1��ixλ����len���ȵ��Ӵ���s2��ȣ�С�ڷ���-1����ȷ���0�����ڷ���1
				if (com == 0 && DP[i - wordsize] == 1)
					DP[i] = 1;
			}
		}
	}
	return DP[s.size()];
}


// �ݹ�
class Solution
{
public:
	bool wordBreak_Re(string s, vector<string> wordDict)
	{
		unordered_set<string> dict(wordDict.cbegin(), wordDict.cend());    // ��vector����ת���ɹ�ϣ�������ѯ
		return wordBreak_Re(s, dict);
	}

	// �ݹ�
	bool wordBreak_Re(string s, unordered_set<string> dict)
	{
		// �ݹ��������
		if (memo.count(s))
			return memo[s];
		if (dict.count(s))
			return memo[s] = true;

		for (int i = 1; i < s.length(); ++i)
		{
			const string left = s.substr(0, i);    // [0,i)����0��ʼ�ĳ���Ϊi���Ӵ�
			const string right = s.substr(i);

			if (dict.count(right) && wordBreak_Re(left, dict))
				return memo[s] = true;
		}

		return memo[s] = false;
	}

private:
	unordered_map<string, bool> memo;

};



int main()
{
	string s = "leetcode";
	vector<string> wordDict = { "leet","co", "de" };

	// Solution solution;
	// bool flag = solution.wordBreak_Re(s, wordDict);
	bool flag = wordBreak_DP_2(s, wordDict);
	cout << flag << endl;

	return 0;
}