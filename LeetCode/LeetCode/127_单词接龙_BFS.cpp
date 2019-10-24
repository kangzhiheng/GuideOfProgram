//-----------------------------------------------------------------------------
// 文 件 名: 130_被围绕的区域_BFS.cpp
// 作    者：adoredee
// 创建时间：2019.09.03
// 描    述：被围绕的区域
// 版    本：
// 链接：https://leetcode-cn.com/problems/word-ladder/
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

/*
	给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
	1. 每次转换只能改变一个字母。
	2. 转换过程中的中间单词必须是字典中的单词。
	说明:
	1. 如果不存在这样的转换序列，返回 0。
	2. 所有单词具有相同的长度。
	3. 所有单词只由小写字母组成。
	4. 字典中不存在重复的单词。
	你可以假设 beginWord 和 endWord 是非空的，且二者不相同。
	
	示例 1:
	输入:
	beginWord = "hit",
	endWord = "cog",
	wordList = ["hot","dot","dog","lot","log","cog"]
	输出: 5
	解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog", 返回它的长度 5。

	示例 2:
	输入:
	beginWord = "hit"
	endWord = "cog"
	wordList = ["hot","dot","dog","lot","log"]
	输出: 0
	解释: endWord "cog" 不在字典中，所以无法进行转换。
*/

// 参考
// https://www.bilibili.com/video/av38705526
// https://zxi.mytechroad.com/blog/searching/127-word-ladder/

#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <string>

using namespace std;

// BFS
int ladderLength(string beginWord, string endWord, vector<string>& wordList)
{
	unordered_set<string> dict(wordList.begin(), wordList.end());    // 相当于visited
	if (!dict.count(endWord))   // 如果endWord不在dict里，转换失败
		return 0;

	queue<string> q;
	q.push(beginWord);

	const int nLen = beginWord.size();    // 每个单词的长度不变
	int steps = 0;

	while (!q.empty())
	{
		++steps;
		for (int size = q.size(); size > 0; size--)
		{
			string curw = q.front();
			q.pop();
			for (int i = 0; i < nLen; ++i)
			{
				char ch = curw[i];    // 保存现场
				for (char a = 'a'; a <= 'z'; ++a)
				{
					curw[i] = a;
					if (curw == endWord)
						return steps + 1;
					if (dict.count(curw))
					{
                        dict.erase(curw);
					    q.push(curw);
					}
					
				}
				curw[i] = ch;
			}
		}
	}
	return 0;
}

int main()
{
	vector<string> wordList = { "hot","dot","dog","lot","log","cog" };
	string beginWord = "hit";
	string endWord = "lot";

	int nums = ladderLength(beginWord, endWord, wordList);
	cout << nums << endl;

	return 0;
}