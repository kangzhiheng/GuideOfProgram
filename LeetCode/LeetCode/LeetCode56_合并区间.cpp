//-----------------------------------------------------------------------------
// ��    �ߣ�adoredee
// ����ʱ�䣺2019.04.28
// ��    �����ϲ�����
//-----------------------------------------------------------------------------
/*
����һ������ļ��ϣ���ϲ������ص������䡣

   ʾ�� 1:
   
   ����: [[1,3],[2,6],[8,10],[15,18]]
   ���: [[1,6],[8,10],[15,18]]
   ����: ���� [1,3] �� [2,6] �ص�, �����Ǻϲ�Ϊ [1,6].
   ʾ�� 2:
   
   ����: [[1,4],[4,5]]
   ���: [[1,5]]
   ����: ���� [1,4] �� [4,5] �ɱ���Ϊ�ص����䡣
*/

/*    �ⷨ������ά���鷨    */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals)
{
	// �쳣�ж�
	if (intervals.empty())
		return intervals;

	// ������ĵ�һ�н��д�С�������򣬼���֤ÿ���������ʼֵ����
	sort(intervals.begin(), intervals.end());

	vector<vector<int>> result;
	
	// ����һ������ѹ��
	result.push_back(intervals[0]);

	for (size_t i = 1; i < intervals.size(); i++)
	{
		// result.back()��ʾresult����������һ�����䣬result.back().back()��ʾ�����������һ��ֵ
		// ����Ѿ�ѹ��result���������һ�������ĩ��ֵС��Ҫѹ����������ʼֵ
		if (result.back().back() < intervals[i].front())
			result.push_back(intervals[i]);
		// ����Ѿ�ѹ��result���������һ�������ĩ�˴��ڵ���Ҫѹ����������ʼֵ������ѹ�������ĩ������������������ĩ��������
		else
			result.back().back() = max(result.back().back(), intervals[i].back());
	}

	return result;
}

int main()
{
	int n;
	cout << "�������������: ";
	cin >> n;

	vector<vector<int>> arr(n, vector<int>(2));

	// �����������
	for (int i = 0; i < n; i++)
		for (int j = 0; j < 2; j++)
		{
			int val;
			cin >> val;
			arr[i][j] = val;
		}

	vector<vector<int>> newarr = merge(arr);

	cout << "�ϲ��������Ϊ: " << endl;
	for (size_t i = 0; i < newarr.size(); i++)
	{
		for (int j = 0; j < 2; j++)
			cout << newarr[i][j] << " ";
		cout << endl;
	}

	return 0;
}


/*    �ⷨһ���ṹ��ⷨ    */

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

	// ��������startֵ��С����
	sort(intervals.begin(), intervals.end(), 
		// lambda���ʽ
		[](Interval a, Interval b) 
	    { 
		    return a.start < b.start; 
	    });

	// ��źϲ��������
	vector<Interval> result;

	result.push_back(intervals[0]);  // ����һ������ѹ��

	for (size_t i = 1; i < intervals.size(); i++)
	{
		if (result.back().end < intervals[i].start)    // ����Ѿ�ѹ��result���������һ�������ĩ��ֵС��Ҫѹ����������ʼֵ
			result.push_back(intervals[i]);
		else    // ����Ѿ�ѹ��result���������һ�������ĩ�˴��ڵ���Ҫѹ����������ʼֵ������ѹ�������ĩ������������������ĩ��������
			result.back().end = max(result.back().end, intervals[i].end);
	}

	return result;
}

int main()
{
	int n;
	cout << "�������������: ";
	cin >> n;

	vector<Interval> arr;

	// �����������
	for (size_t i = 0; i < n; i++)
	{
		Interval val;
		cin >> val.start >> val.end;
		arr.push_back(val);
	}

	vector<Interval> newarr = merge(arr);

	cout << "�ϲ��������Ϊ: " << endl;
	for (auto i : newarr)
		cout << i.start << " " << i.end << endl;

	return 0;
}
*/