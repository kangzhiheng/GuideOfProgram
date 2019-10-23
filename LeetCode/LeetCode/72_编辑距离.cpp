//-----------------------------------------------------------------------------
// �� �� ��: 72_�༭����.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.09.19
// ��    �����༭����
// ��    ����
// ��    �ӣ�https://leetcode-cn.com/problems/edit-distance/
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// �ο���https://leetcode-cn.com/problems/edit-distance/solution/bian-ji-ju-chi-mian-shi-ti-xiang-jie-by-labuladong/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int min(int a, int b, int c)
{
	return min(a, min(b, c));
}

pair<int, int> min_pair(pair<int, int> a, pair<int, int> b, pair<int, int> c)
{
	pair<int, int> temp;
	if (a.first < b.first)
		temp = a;
	else
		temp = b;
	if (temp.first > c.first)
		temp = c;

	return temp;
}

pair<int, int> addTwoPair(pair<int, int> a, pair<int, int> b)
{
	int value = a.first + b.first;

	pair<int, int> sums(value, b.second);

	return sums;
}

/* DP[i][j] ��ʾ word1 �� i λ��ת���� word2 �� j λ���������С����
   1. word1[i] == word2[j], ����
   2. word1[i] != word2[j], ȡɾ�������롢�滻����Сֵ
      DP[i - 1][j] + 1 ��ʾɾ������word1��ɾ�����ʽ� i ������ֵ��1
	  DP[i][j - 1] + 1 ��ʾ���룬��word1�� i ������������word2�� j ����ֵ��������ֵ j - 1��������һ�β���
	  DP[i-1][j-1] + 1 ��ʾ�滻����word2�� j ����������ֵ�滻��word1�� i ��������ֵ��i, j ����1
    ��ʵ������word1ת����word2������word2ת����word1���ԳƲ���
 */
int minDistance(string word1, string word2)
{
	// ���word1Ϊ�գ���word1ת��Ϊword2��Ҫword2�ĳ��ȵĲ���������֮��Ȼ
	if (word2.empty() || word1.empty())
		return max(word1.size(), word2.size());

	vector<vector<int>> DP(word1.size() + 1, vector<int>(word2.size() + 1));
	DP[0][0] = 0;
	for (int i = 1; i <= word1.size(); ++i)
		DP[i][0] = i;
	for (int j = 1; j <= word2.size(); ++j)
		DP[0][j] = j;

	for (int i = 1; i <= word1.size(); ++i)
	{
		for (int j = 1; j <= word2.size(); ++j)
		{
			if (word1[i - 1] == word2[j - 1])
				DP[i][j] = DP[i - 1][j - 1];    // ����
			else
				DP[i][j] = min(
					DP[i - 1][j] + 1,        // ɾ��
					DP[i][j - 1] + 1,        // ����
					DP[i - 1][j - 1] + 1     // �滻
				);
		}
	}	

	for (auto i : DP)
	{
		for (auto j : i)
			cout << j << " ";
		cout << endl;
	}

	return DP[word1.size()][word2.size()];
}

// ����ÿһ���Ĳ���
int minDistance_Output(string word1, string word2)
{
	// ���word1Ϊ�գ���word1ת��Ϊword2��Ҫword2�ĳ��ȵĲ���������֮��Ȼ
	if (word2.empty() || word1.empty())
		return max(word1.size(), word2.size());

	// pair<int, int> ������С��������Ӧ�Ĳ�����0��ʾ������1��ʾɾ����2��ʾ���룬3��ʾ�滻
	vector<vector<pair<int, int>>> DP(word1.size() + 1, vector<pair<int, int>>(word2.size() + 1));
	DP[0][0] = { 0, 0 };
	for (int i = 1; i <= word1.size(); ++i)
		DP[i][0] = { i, 2 };
	for (int j = 1; j <= word2.size(); ++j)
		DP[0][j] = { j, 2 };

	pair<int, int> deletes(1, 1);
	pair<int, int> inserts(1, 2);
	pair<int, int> replace(1, 3);

	for (int i = 1; i <= word1.size(); ++i)
	{
		for (int j = 1; j <= word2.size(); ++j)
		{
			if (word1[i - 1] == word2[j - 1])
				DP[i][j] = DP[i - 1][j - 1];    // ����
			else
				DP[i][j] = min_pair(
					addTwoPair(DP[i - 1][j], deletes),        // ɾ��
					addTwoPair(DP[i][j - 1], inserts),        // ����
					addTwoPair(DP[i - 1][j - 1], replace)     // �滻
			);
		}
	}

	for (auto i : DP)
	{
		for (auto j : i)
			cout << "(" << j.first << "," << j.second << ")  ";
		cout << endl;
	}

	return DP[word1.size()][word2.size()].first;
}

int main()
{
	int i = 0, nSpaceNum = 0;
	char *newstr = new char[length + nSpaceNum];

	string s1, s2;
	cin >> s1 >> s2;

	int nMinSteps = minDistance_Output(s1, s2);
	cout << nMinSteps << endl;

	return 0;
}