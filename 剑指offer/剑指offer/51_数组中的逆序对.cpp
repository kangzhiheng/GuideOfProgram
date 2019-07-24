//-----------------------------------------------------------------------------
// �� �� ��: 51_�����е������.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.07.24
// ��    ���������е������
// ��    ����
//-----------------------------------------------------------------------------
// Copyright (C) 2019 Shanghai Jiao Tong University
//-----------------------------------------------------------------------------

// ������51�������е������
// ��Ŀ���������е������������ǰ��һ�����ִ��ں�������֣���������������
//      ��һ������ԡ�����һ�����飬�����������е�����Ե�������

#include <iostream>
#include <vector>

using namespace std;

vector<int> cnt;    // ͳ��ÿ�β���������������Եĸ���

// ��ӡ����
void PrintArray(vector<int>& arr)
{
	for (int i = 0; i < arr.size(); ++i)
		cout << arr[i] << " ";
	cout << endl;
}

// ����鲢
int Merge(vector<int>& data, int start, int mid, int end, vector<int>& temp)
{
	int i = mid;    // ǰ������һ�����ֵ��±�
	int j = end;    // �������һ�����ֵ��±�

	int k = 0;      // ��ʱ����ĵ�һ���±�
	int count = 0;

	while (i >= start && j > mid)
	{
		// ���ζ������򣬹����ǰ������һ�����ִ��ں������һ�����ӣ�
		// ����ں������е����֣��ʴ�������ԣ���Ϊ�������ֵĸ���
		if (data[i] > data[j])
		{
			temp[k++] = data[i--];
			count += j - mid;
		}
		else    // �������������󣬷ŵ���ʱ�������ʱ�����ǽ���
		{
			temp[k++] = data[j--];
		}
	}

	cout << "���ι鲢ʱ�����������Ϊ��" << count << endl;
	cnt.emplace_back(count);

	// ��ʾǰ��������л���Ԫ��δ������ʱ����
	while (i >= start)
	{
		temp[k++] = data[i--];
	}

	while (j > mid)
	{
		temp[k++] = data[j--];
	}
	// ����ʱ�����е�Ԫ��д�ص�ԭ���鵱��ȥ
	for (int i = 0; i < k; ++i)
		data[end - i] = temp[i];

	// ��ӡ��ÿ�ι鲢�Ժ��������ʽ
	PrintArray(data);

	return count;
}

int InversePairsCore(vector<int>& data, vector<int>& temp, int start, int end)
{
	int inversions = 0;

	if (start < end)
	{
		int mid = (start + end) / 2;
		inversions += InversePairsCore(data, temp, start, mid);
		inversions += InversePairsCore(data, temp, mid + 1, end);
		inversions += Merge(data, start, mid, end, temp);
	}

	return inversions;
}

// �ҳ����������
int InversePairs(vector<int>& data)
{
	if (data.empty() || data.size() < 0)
		throw "�����쳣";

	vector<int> temp(data.size());

	int counts = InversePairsCore(data, temp, 0, data.size() - 1);

	return counts;
}

int main()
{
	vector<int> arr = { 1,3,7,8,2,4,6,5 };
	int counts = InversePairs(arr);

	cout << "�ܹ�������" << cnt.size() << "�ι鲢��������" << endl;
	for (int i = 0; i < cnt.size(); ++i)
	{
		if (i == cnt.size() - 1)
		{
			cout << cnt[i] << " = " << counts << endl;
			break;
		}
		cout << cnt[i] << " + ";
	}

	cout << "�������Ϊ��" << counts << endl;

	return 0;
}
