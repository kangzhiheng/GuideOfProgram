//-----------------------------------------------------------------------------
// 文 件 名: 752_打开转盘锁.cpp
// 作    者：adoredee
// 创建时间：2019.08.17
// 描    述：打开转盘锁
// 版    本：
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

/*
	   你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' 。
	每个拨轮可以自由旋转：例如把 '9' 变为  '0'，'0' 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。锁的初始数字为 '0000' ，
	一个代表四个拨轮的数字的字符串。列表 deadends 包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。
	字符串 target 代表可以解锁的数字，你需要给出最小的旋转次数，如果无论如何不能解锁，返回 -1。

	 示例 1:
	 输入：deadends = ["0201","0101","0102","1212","2002"], target = "0202"
	 输出：6
	 解释：
	 可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" -> "0202"。
	 注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202" 这样的序列是不能解锁的，
	 因为当拨动到 "0102" 时这个锁就会被锁定。

	 示例 2:
	 输入: deadends = ["8888"], target = "0009"
	 输出：1
	 解释：
	 把最后一位反向旋转一次即可 "0000" -> "0009"。

	 示例 3:
	 输入: deadends = ["8887","8889","8878","8898","8788","8988","7888","9888"], target = "8888"
	 输出：-1
	 解释：
	 无法旋转到目标数字且不被锁定。

	 示例 4:
	 输入: deadends = ["0000"], target = "8888"
	 输出：-1
  
	 提示：
	 死亡列表 deadends 的长度范围为 [1, 500]。
	 目标数字 target 不会在 deadends 之中。
	 每个 deadends 和 target 中的字符串的数字会在 10,000 个可能的情况 '0000' 到 '9999' 中产生。
*/


/*
    参考：
	https://zxi.mytechroad.com/blog/searching/leetcode-752-open-the-lock/
	https://www.bilibili.com/video/av31636797?t=385
*/
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

// BFS模板
int openlock(vector<string>& deadends, string target)
{
	const string start = "0000";    // 从“0000”开始找
	unordered_set<string> dead(deadends.begin(), deadends.end());    // 无序且不重复的集合

	if (dead.count(start))    // 返回匹配特定键的元素数量
		return -1;
	
	if (target == start)    // 目标就是“0000”
		return 0;

	queue<string> q;
	unordered_set<string> visited{ start };

	int step = 0;
	q.push(start);

	while (!q.empty())
	{
		++step;
		const size_t size = q.size();
		for (int i = 0; i < size; ++i)
		{
			const string cur = q.front();
			q.pop();
			for (int i = 0; i < 4; ++i)
			{
				for (int j = -1; j <= 1; j += 2)   // 核心步骤1
				{
					string next = cur;    // 备份
					next[i] = (next[i] - '0' + j + 10) % 10 + '0';    // 核心步骤2

					if (next == target)
						return step;
					if (dead.count(next) || visited.count(next))
						continue;
					q.push(next);
					visited.insert(next);
				}
			}
		}
	}

	return -1;

}


int main()
{
	vector<string> deadens = { "0001" };
	string target = "0002";

	int res = openlock(deadens, target);
	cout << "从0000到" << target << "，避开锁死区域，至少要走" << res << "步。" << endl;

	return 0;
}