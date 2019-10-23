//-----------------------------------------------------------------------------
// 作    者：adoredee
// 创建时间：2019.04.28
// 描    述：合并区间
//-----------------------------------------------------------------------------
/*
给出一个区间的集合，请合并所有重叠的区间。

   示例 1:
   
   输入: [[1,3],[2,6],[8,10],[15,18]]
   输出: [[1,6],[8,10],[15,18]]
   解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
   示例 2:
   
   输入: [[1,4],[4,5]]
   输出: [[1,5]]
   解释: 区间 [1,4] 和 [4,5] 可被视为重叠区间。
*/

/*    解法二：二维数组法    */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
	// 异常判断
	if (intervals.empty())
		return intervals;

	// 对区间的第一列进行从小到大排序，即保证每个区间的起始值递增
	sort(intervals.begin(), intervals.end());

	vector<vector<int>> result;
	
	// 将第一个区间压入
	result.push_back(intervals[0]);

	for (size_t i = 1; i < intervals.size(); i++)
	{
		// result.back()表示result容器里的最后一个区间，result.back().back()表示这个区间的最后一个值
		// 如果已经压入result容器内最后一个区间的末端值小于要压入的区间的起始值
		if (result.back().back() < intervals[i].front())
			result.push_back(intervals[i]);
		// 如果已经压入result容器内最后一个区间的末端大于等于要压入的区间的起始值，则新压入的区间末端由这两个区间的最大末端所决定
		else
			result.back().back() = max(result.back().back(), intervals[i].back());
	}

	return result;
}

int main()
{
	int n;
	cout << "请输入区间个数: ";
	cin >> n;

	vector<vector<int>> arr(n, vector<int>(2));

	// 输入各个区间
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++)
		{
			int val;
			cin >> val;
			arr[i][j] = val;
		}

	vector<vector<int>> newarr = merge(arr);

	cout << "合并后的区间为: " << endl;
	for (size_t i = 0; i < newarr.size(); i++)
	{
		for (int j = 0; j < 2; j++)
			cout << newarr[i][j] << " ";
		cout << endl;
	}

	return 0;
}


/*    解法一：结构体解法    */

/*
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Interval
{
	int start;
	int end;
	Interval() : start(0), end(0) {}
	Interval(int s, int e) : start(s), end(e) {}
};

vector<Interval> merge(vector<Interval>& intervals)
{
	if (intervals.empty())
		return intervals;

	// 区间排序，start值由小到大
	sort(intervals.begin(), intervals.end(), 
		// lambda表达式
		[](Interval a, Interval b) 
	    { 
		    return a.start < b.start; 
	    });

	// 存放合并后的区间
	vector<Interval> result;

	result.push_back(intervals[0]);  // 将第一个区间压入

	for (size_t i = 1; i < intervals.size(); i++)
	{
		if (result.back().end < intervals[i].start)    // 如果已经压入result容器内最后一个区间的末端值小于要压入的区间的起始值
			result.push_back(intervals[i]);
		else    // 如果已经压入result容器内最后一个区间的末端大于等于要压入的区间的起始值，则新压入的区间末端由这两个区间的最大末端所决定
			result.back().end = max(result.back().end, intervals[i].end);
	}

	return result;
}

int main()
{
	int n;
	cout << "请输入区间个数: ";
	cin >> n;

	vector<Interval> arr;

	// 输入各个区间
	for (size_t i = 0; i < n; i++)
	{
		Interval val;
		cin >> val.start >> val.end;
		arr.push_back(val);
	}

	vector<Interval> newarr = merge(arr);

	cout << "合并后的区间为: " << endl;
	for (auto i : newarr)
		cout << i.start << " " << i.end << endl;

	return 0;
}
*/