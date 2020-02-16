//-----------------------------------------------------------------------------
// �� �� ��: 40_��С��k����.cpp
// ��    �ߣ�adoredee
// ����ʱ�䣺 2019.06.13
// ��    ������С��k����
// ��    ����
//-----------------------------------------------------------------------------

// ������40����С��k����
// ��Ŀ������n���������ҳ�������С��k��������������4��5��1��6��2��7��3��8
//      ��8�����֣�����С��4��������1��2��3��4��

#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>

using namespace std;

int Partition(vector<int>& arr, int start, int end)
{
	// �쳣���
	if (arr.empty() || arr.size() <= 0)
		return 0;

	srand(int(time(0)));
	int pivot = rand() % (end - start + 1) + start;
	int key = arr[pivot];

	swap(arr[pivot], arr[start]);    // ����׼���ŵ���һ��λ����
	while (start < end)
	{
		while (start < end && arr[end] > key)
			end--;
		swap(arr[start], arr[end]);
		while (start < end && arr[start] <= key)
			start++;
		swap(arr[start], arr[end]);
	}

	return start;
}

vector<int> kLeastNumbers_Partition(vector<int>& arr, int k)
{
	// �쳣���
	if (arr.empty() || arr.size() <= 0 || k > arr.size() || k <= 0)
		return arr;

	int start = 0;
	int end = arr.size() - 1;

	int index = Partition(arr, start, end);    // ѡȡ��׼ֵ

	while (index != k - 1)    // �ж��Ƿ���ǰk����
	{
		if (index > k - 1)
		{
			end = index - 1;
			index = Partition(arr, start, end);
		}
		else    // index < k - 1
		{
			start = index + 1;
			index = Partition(arr, start, end);
		}
	}

	// ��ǰk�����洢����
	vector<int> arr_kLeast;
	for (int i = 0; i < k; ++i)
		arr_kLeast.emplace_back(arr[i]);

	return arr_kLeast;
}

vector<int> kLeastNumbers_top_k(vector<int>& arr, int k)
{
	// �쳣���
	if (arr.empty() || arr.size() <= 0 || k > arr.size() || k < 0)
		return arr;
	if (k == 0)
		return {};

	/*
	top_k˼·����ȡ������ǰk����������С�������У�
	���ʣ���������k�����е���Сֵ��ҪС������k���������滻����������������
	*/
	vector<int> arr_top_k;
	for (int i = 0; i < k; ++i)
		arr_top_k.emplace_back(arr[i]);
	sort(arr_top_k.begin(), arr_top_k.end());    // ��ԭ�����ǰk�������������

	for (int i = k; i < arr.size(); i++)
	{
		if (arr[i] < arr_top_k[k - 1])    // ���ʣ�µ�Ԫ��С��arr_top_k�����ģ����滻��arr_top_k��������
		{
			arr_top_k[k - 1] = arr[i];
			sort(arr_top_k.begin(), arr_top_k.end());
		}
	}

	return arr_top_k;
}

int main()
{
	int length;
	cout << "���������鳤�ȣ�";
	cin >> length;

	int k;
	cout << "������kֵ��";
	cin >> k;

	cout << "�����볤��Ϊ" << length << "����Ԫ��: ";
	vector<int> arr;
	for (int i = 0; i < length; i++)
	{
		int val;
		cin >> val;
		arr.emplace_back(val);
	}

	cout << "���������Ϊ��";
	for (int i = 0; i < arr.size(); i++)
		cout << arr[i] << " ";
	cout << endl;

	vector<int> arr_k_1 = kLeastNumbers_Partition(arr, k);
	cout << "��������С��ǰ" << k << "����Ϊ��" << endl;
	cout << "1. Partition����:" << endl;
	for (int i = 0; i < arr_k_1.size(); i++)
		cout << arr_k_1[i] << " ";
	cout << endl;

	cout << "2. Top_k����:" << endl;
	vector<int> arr_k_2 = kLeastNumbers_top_k(arr, k);
	for (int i = 0; i < arr_k_2.size(); i++)
		cout << arr_k_2[i] << " ";
	cout << endl;

	return 0;
}